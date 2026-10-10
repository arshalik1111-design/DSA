#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class RecursiveApproach
{
public:
    // Inorder: left root right
    void inOrderHelper(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        inOrderHelper(root->left, ans);
        ans.push_back(root->data);
        inOrderHelper(root->right, ans);
    }

    vector<int> inOrderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inOrderHelper(root, ans);
        return ans;
    }

    // PreOrder: Root Left Right
    void preOrderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->data);
        preOrderHelper(root->left, ans);
        preOrderHelper(root->right, ans);
    }

    vector<int> preOrderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrderHelper(root, ans);
        return ans;
    }
};

class IterativeApproach
{

public:
    // Leetcode 94. Binary Tree Inorder Traversal
    vector<int> inOrderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inOrder;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->data);
                node = node->right;
            }
        }
        return inOrder;
    }

    vector<int> preOrderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> preOrder;
        if (!root)
            return preOrder;
        TreeNode *node = root;
        st.push(node);
        while (!st.empty())
        {
            node = st.top();
            st.pop();
            preOrder.push_back(node->data);
            if (node->right)
            {
                st.push(node->right);
            }
            if (node->left)
            {
                st.push(node->left);
            }
        }
        return preOrder;
    }

    // Post order traversal using single stack appraoch

    vector<int> postOrderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> postOrder;
        if (!root)
            return postOrder;
        TreeNode *node = root;
        st.push(node);
        while (!st.empty())
        {
            node = st.top();
            st.pop();
            postOrder.push_back(node->data);
            if (node->left)
            {
                st.push(node->left);
            }
            if (node->right)
            {
                st.push(node->right);
            }
        }
        vector<int> res(rbegin(postOrder), rend(postOrder));
        return res;
    }

    // Post order traversal using two stacks appraoch
    vector<int> postOrderUsingTwoStacks(TreeNode *root)
    {
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        vector<int> postOrder;
        if (!root)
            return postOrder;
        TreeNode *node = root;
        st1.push(node);
        while (!st1.empty())
        {
            node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left)
            {
                st1.push(node->left);
            }
            if (node->right)
            {
                st1.push(node->right);
            }
        }
        vector<int> res;
        while (!st2.empty())
        {
            res.push_back(st2.top()->data);
            st2.pop();
        }
        return res;
    }

    vector<vector<int>> levelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> levelOrder;
        if (!root)
            return levelOrder;
        queue<TreeNode *> q;
        TreeNode *node = root;
        q.push(node);
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++)
            {
                node = q.front();
                q.pop();
                currentLevel.push_back(node->data);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelOrder.push_back(currentLevel);
        }
        return levelOrder;
    }

    vector<vector<int>> preInPostTraversal(TreeNode *root)
    {
        vector<int> pre, in, post;
        stack<pair<TreeNode *, int>> st;
        if (!root)
            return {in, pre, post};
        st.push({root, 1});

        while (!st.empty())
        {
            auto &it = st.top();
            if (it.second == 1)
            {
                pre.push_back(it.first->data);
                it.second++;
                if (it.first->left)
                {

                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->data);
                it.second++;
                if (it.first->right)
                {

                    st.push({it.first->right, 1});
                }
            }
            else
            {
                post.push_back(it.first->data);
                st.pop();
            }
        }

        return {in, pre, post};
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> ans;
    IterativeApproach sol;
    vector<vector<int>> res = sol.preInPostTraversal(root);

    for (const auto &level : res)
    {
        cout << "[ ";
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << "]\n";
    }
}