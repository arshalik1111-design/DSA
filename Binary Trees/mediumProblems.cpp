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

class Solution
{

public:
    // Recursive Approach
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }

    // Using LevelOrder
    int maxDepthUsingBFS(TreeNode *root)
    {
        vector<vector<int>> levelOrder;

        queue<TreeNode *> q;
        TreeNode *node = root;
        if (!node)
            return 0;
        q.push(node);
        int cnt = 0;

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
            cnt++;
        }

        return cnt;
    }

    // Leetcode 110. Balanced Binary Tree
    bool isBalanced(TreeNode *root)
    {
        // we make a tweak in the code of finding the height of the tree

        if (!root)
            return 0;
        int left = isBalanced(root->left);
        if (left == -1)
            return -1;
        int right = isBalanced(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
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
    bool res = sol.isBalanced(root);
    cout << res;
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