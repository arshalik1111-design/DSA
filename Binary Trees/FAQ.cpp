#include <bits\stdc++.h>
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
                currLevel.push_back(node->data);
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
    vector<vector<int>> res = sol.zigzagLevelOrder(root);
    // cout << res;
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
