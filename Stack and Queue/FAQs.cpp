#include <bits/stdc++.h>

using namespace std;

class BruteForce
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> list;
        for (int i = 0; i <= n - k; i++)
        {
            int maxi = nums[i];
            for (int j = i; j <= k + i - 1; j++)
            {
                maxi = max(maxi, nums[j]);
            }
            list.push_back(maxi);
        }
        return list;
    }
};

class Optimal
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> list;
        for (int i = 0; i < n; i++)
        {
            // Maintain Sliding window order of K
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            // if current element is greater than dq.front we pop from dq.front to maintain decreasing order fashion
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            // store dq.front() as the max element
            // also check for first window span
            if (i >= k - 1)
                list.push_back(nums[dq.front()]);
        }
        return list;
    }
};

int main()
{
    vector<int> nums = {1, 3, 1, 2, 0, 5};
    int k = 3;
    Optimal sol;

    vector<int> res = sol.maxSlidingWindow(nums, k);
    for (auto it : res)
    {
        cout << it << " ";
    }
}