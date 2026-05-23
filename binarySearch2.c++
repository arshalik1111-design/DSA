#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateTotalHours(int n, vector<int> &piles, int hourly)
    {

        int totalHours = 0;

        for (int pile : piles)
        {
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }
    int KokoEatingBananas(int n, vector<int> &piles, int h)
    {
        int maxPile = *max_element(piles.begin(), piles.end());
        // for (int i = 1; i <= maxPile; i++)
        // {
        //     int totalTime = calculateTotalHours(n, piles, i);
        //     if (totalTime <= h)
        //     {
        //         return i;
        //     }
        // }
        int s = 1;
        int e = maxPile;
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            int totalTime = calculateTotalHours(n, piles, mid);
            if (totalTime == h)
            {
                return mid;
            }
            else if (totalTime < h)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }

    bool isPossilbe(vector<int> bloomDays, long long day, long long m, long long k)
    {
        int bouquets = 0;
        int count = 0;
        for (int bloom : bloomDays)
        {
            if (bloom <= day)
            {
                count++;
                if (count == k)
                {
                    bouquets++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minimumDaysToMakeBouquets(int n, vector<int> bloomDays, int m, int k)
    {
        long long numberOfFlowers = 1LL * m * k;
        if (numberOfFlowers > n)
            return -1;

        int maxi = *max_element(bloomDays.begin(), bloomDays.end());
        int mini = *min_element(bloomDays.begin(), bloomDays.end());
        // Brute Force
        // for (int day = maxi; day <= mini; ++day)
        // {
        //     if (isPossilbe(bloomDays, day, m, k))
        //     {
        //         return day;
        //     }
        // }
        int s = mini;
        int e = maxi;
        int result = -1;
        // Optimal
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossilbe(bloomDays, mid, m, k))
            {
                result = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return result;
    }

    int isLessThanThreshold(vector<int> &nums, int divisor)
    {
        int sum = 0;
        for (int div : nums)
        {
            sum += ceil((double)div / divisor);
        }
        return sum;
    }
    int smallestDivisor(int n, vector<int> &nums, int th)
    {

        int e = *max_element(nums.begin(), nums.end());
        int s = 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isLessThanThreshold(nums, mid) <= th)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return s;
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int th;
    cin >> th;

    // int k;
    // cin >> k;
    // int h;
    // cin >> h;
    Solution solution;
    int ans = solution.smallestDivisor(n, nums, th);
    cout << ans;
}