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

    // Leetcode 42. Trapping Rain Water

    vector<int> prefixMax(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        // start from one as we already stored first element as prefixMax
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }
        return prefix;
    }
    vector<int> suffixMax(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> suffix(n);
        suffix[n - 1] = arr[n - 1];
        // start from one as we already stored first element as suffixMax
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], arr[i]);
        }
        return suffix;
    }
    int trap(vector<int> &height)
    {
        int n = height.size();
        int total = 0;
        vector<int> getLeftMax = prefixMax(height);
        vector<int> getRightMax = suffixMax(height);
        for (int i = 0; i < n; i++)
        {
            int leftMax = getLeftMax[i];
            int rightMax = getRightMax[i];

            total += (min(leftMax, rightMax) - height[i]);
        }
        return total;
    }
};

int main()
{
    // vector<int> nums = {1, 3, 1, 2, 0, 5};
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int k = 3;
    Optimal sol;

    int res = sol.trap(height);
    cout << res;
    // for (auto it : res)
    // {
    //     cout << it << " ";
    // }
}