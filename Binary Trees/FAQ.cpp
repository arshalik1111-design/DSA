#include <bits\stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    // Leetcode 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        TreeNode *node = root;
        q.push(node);
        int flag = 0;

        while (!q.empty())
        {

            int levelSize = q.size();
            vector<int> currLevel;

            for (int i = 0; i < levelSize; i++)
            {
                node = q.front();
                q.pop();
                currLevel.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (flag == 0)
            {
                ans.push_back(currLevel);
                flag = 1;
            }
            else
            {
                reverse(currLevel.begin(), currLevel.end());
                ans.push_back(currLevel);
                flag = 0;
            }
        }
        return ans;
    }

    // Boundary Traversal of Binary Tree
    bool isLeaf(TreeNode *root)
    {
        return (!root->left && !root->right);
    }
    void addLeft(TreeNode *root, vector<int> &res)
    {
        TreeNode *node = root->left;
        while (node)
        {
            if (!isLeaf(node))
                res.push_back(node->val);
            if (node->left)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
    }
    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        if (isLeaf(root))
        {
            res.push_back(root->val);
            return;
        }

        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }
    void addRight(TreeNode *root, vector<int> &res)
    {
        vector<int> temp;
        TreeNode *node = root->right;

        while (node)
        {
            if (!isLeaf(node))
                temp.push_back(node->val);
            if (node->right)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }
    vector<int> boundary(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        if (!isLeaf(root))
            res.push_back(root->val);
        addLeft(root, res);
        addLeaves(root, res);
        addRight(root, res);

        return res;
    }

    // Vertical Traversal Of Binary Tree
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second.first;
            int level = it.second.second;

            mp[line][level].insert(node->val);
            if (node->left)
            {
                q.push({node->left, {line - 1, level + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {line + 1, level + 1}});
            }
        }

        for (auto &p : mp)
        {
            vector<int> col;
            for (auto &q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    // Top view of Binary Tree
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;

        if (!root)
            return ans;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int line = it.second;
            if (mp.find(line) == mp.end())
            {
                mp[line] = node->val;
            }
            if (node->left)
            {
                q.push({node->left, it.second - 1});
            }
            if (node->right)
            {
                q.push({node->right, it.second + 1});
            }
        }
        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }

    // Bottom view of Binary tree

    vector<int> bottomView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;
            mp[line] = node->val;

            if (node->left)
            {
                q.push({node->left, it.second - 1});
            }
            if (node->right)
            {
                q.push({node->right, it.second + 1});
            }
        }
        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
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
    Solution sol;
    vector<int> res = sol.bottomView(root);
    // cout << res;

    for (auto &it : res)
    {
        cout << it << " ";
    }
    // for (const auto &level : res)
    // {
    //     cout << "[ ";
    //     for (int val : level)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << "]\n";
    // }
}
