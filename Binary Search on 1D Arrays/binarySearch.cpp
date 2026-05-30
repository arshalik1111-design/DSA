#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(int n, vector<int> &nums, int t)
    {

        // Brute Force
        //  for (int i = 0; i < n; i++)
        //  {
        //      if (nums[i] >= t)
        //      {
        //          return i;
        //      }
        //  }
        //  return n;

        int start = 0;
        int end = n - 1;
        int result = n;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            if (nums[mid] >= t)
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }
    int upperBound(int n, vector<int> &nums, int t)
    {

        // Brute Force
        //  for (int i = 0; i < n; i++)
        //  {
        //      if (nums[i] <= t)
        //      {
        //          return i;
        //      }
        //  }
        //  return n;

        int start = 0;
        int end = n - 1;
        int result = n;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            if (nums[mid] > t)
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }

    int findFloor(int n, int t, vector<int> &nums)
    {

        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e)
        {

            int mid = s + ((e - s) / 2);
            if (nums[mid] <= t)
            {
                ans = nums[mid];
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
    int findCeil(int n, int t, vector<int> &nums)
    {

        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e)
        {

            int mid = s + ((e - s) / 2);
            if (nums[mid] >= t)
            {
                ans = nums[mid];
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(int n, int t, vector<int> &nums)
    {
        int f = findFloor(n, t, nums);
        int c = findCeil(n, t, nums);
        return make_pair(f, c);
    }
    int firstOccurance(int n, int t, vector<int> &nums)
    {
        int result = -1;
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (nums[mid] == t)
            {
                result = mid;
                e = mid - 1;
            }
            else if (nums[mid] > t)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return result;
    }
    int lastOccurance(int n, int t, vector<int> &nums)
    {
        // Optimal Approach
        int result = -1;

        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (nums[mid] == t)
            {
                result = mid;
                s = mid + 1;
            }
            else if (nums[mid] > t)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return result;
    }

    pair<int, int> getFirstAndLast(int n, int t, vector<int> &nums)
    {
        int first = firstOccurance(n, t, nums);
        int last = lastOccurance(n, t, nums);
        return make_pair(first, last);
    }

    int SearchElementInRotatedArray(int n, int t, vector<int> &nums)
    {
        int s = 0;
        int e = n - 1;
        int res = -1;

        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (nums[mid] == t)
            {
                return mid;
            }
            // If Left part is sorted
            if (nums[s] <= nums[mid])
            {
                if (nums[s] <= t && t < nums[mid])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < t && t <= nums[e])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
    }
    int searchSingleElement(vector<int> nums, int n)
    {
        // Brute Force 1
        // for (int i = 0; i < n; i++)
        // {
        //     if ((i + 1) != i)
        //     {
        //         return (i + 1);
        //     }
        // }
        // Brute Force 2
        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans = ans ^ nums[i];
        // }
        // return ans ;
        // Optimal

        // Edge case: only one element in the array
        if (n == 1)
            return nums[0];

        // Edge case: first element is the unique one
        if (nums[0] != nums[1])
            return nums[0];

        // Edge case: last element is the unique one
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        int s = 1;
        int e = n - 2;

        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            {
                return nums[mid];
            }
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }

    int peakElement(vector<int> nums, int n)
    {

        //    Brute Force
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        //     {
        //         return i;
        //     }
        // }
        // return -1;

        // Optimal solution

        // Edge case 1:

        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[mid] > nums[mid + 1])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
    }

    int sqrtOfANumber(int n)
    {
        // Brute Force
        // int ans;
        // for (int i = 0; i < n; i++)
        // {
        //     if (i * i <= n)
        //     {
        //         ans = i;
        //     }
        // }
        // return ans;

        // Optimal Solution
        int s = 1;
        int e = n;
        int ans = 0;
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (mid * mid <= n)
            {
                ans = mid;

                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }

    long long NRootOfM(int n, int m)
    {
        // Brute Force
        // for (int i = 1; i <= m; i++)
        // {
        //     int power = pow(i, n);

        //     if (power == m)
        //         return i;

        //     if (power > m)
        //         break;
        // }
        // return -1;

        // Optimal Solution
        int s = 1;
        int e = m;

        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            long long power = pow(mid, n);
            if (power == m)
                return mid;
            if (power < m)
            {

                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    // int t;
    // cin >> t;
    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }
    Solution solution;
    long long ans = solution.NRootOfM(n, m);
    cout << ans;
}
