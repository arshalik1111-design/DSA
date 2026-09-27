#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> nextGreaterElement(vector<int> nums)
    {
        int n = nums.size();

        vector<int> ans(n);
        // we will traverse from the last, as till we reach an element whose NGE is to be find, we will already know all the elements on it's right
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }

            else
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }

    // Leetcode 503. Next Greater Element II

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // Hypothetically we double the array and taverse from the end, also preserving the order of monotonic stack.
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        // Loop twice the size of the array backwards to handle the circular property
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            // Maintain a monotonic decreasing stack (top of stack is the smallest)
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            // Only store results when we are in the first pass range (actual indices)
            if (i < n)
            {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 1};

    Solution obj;
    vector<int> res = obj.nextGreaterElements(arr);

    for (auto it : res)
    {
        cout << it;
    }
}