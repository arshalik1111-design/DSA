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
};

int main()
{
    vector<int> arr = {1, 3, 2, 4};

    Solution obj;
    vector<int> res = obj.nextGreaterElement(arr);

    for (auto it : res)
    {
        cout << it;
    }
}