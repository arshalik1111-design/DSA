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
    vector<int> res = sol.postOrderUsingTwoStacks(root);

    for (auto &it : res)
    {
        cout << it << " ";
    }
}