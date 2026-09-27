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

        for (int i = 2 * n - 1; i >= 0; i--)
        {
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

    // Leetcode 735. Asteroid Collision
    vector<int> asteroidCollision(vector<int> &arr)
    {
        vector<int> li;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            // store Positive elements into the list
            if (arr[i] > 0)
            {
                li.push_back(arr[i]);
            }
            else
            {
                // remove element from the list if arr[i]>st.back(), also the top element in list must be greater than 0.
                while (!li.empty() && li.back() > 0 && abs(arr[i]) > li.back())
                {
                    li.pop_back();
                }
                // if both the aesteroids have same absolute value and opposite directions
                if (!li.empty() && abs(arr[i]) == li.back())
                {
                    li.pop_back();
                }
                else if (li.empty() || li.back() < 0)
                {
                    li.push_back(arr[i]);
                }
            }
        }
        return li;
    }
};

int main()
{
    vector<int> arr = {5, 10, -5};

    Solution obj;
    vector<int> res = obj.asteroidCollision(arr);

    for (auto it : res)
    {
        cout << it;
    }
}