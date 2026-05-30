#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateTotalHours(vector<int> &piles, int hourly)
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
        int ans = 0;
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            if (calculateTotalHours(piles, mid) <= h)
            {
                ans = mid;
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }
        }
        return ans;
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

    int daysNeeded(vector<int> nums, int capacity)
    {
        int days = 1;
        int currentLoad = 0;
        for (int weight : nums)
        {
            if (currentLoad + weight > capacity)
            {
                days++;
                currentLoad = weight;
            }
            else
            {
                currentLoad += weight;
            }
        }
        return days;
    }
    int capacityToShipPackages(int n, vector<int> weights, int days)
    {
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        int minCapacity = *max_element(weights.begin(), weights.end());
        // for (int i = minCapacity; i <= maxCapacity; i++)
        // {
        //     if (daysNeeded(weights, i) <= days)
        //     {
        //         return i;
        //     }
        // }
        // return maxCapacity;

        int s = minCapacity;
        int e = maxCapacity;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (daysNeeded(weights, mid) <= days)
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }

    int KthMissingNumber(int n, vector<int> vec, int k)
    {
        // Brute Force
        // for (int i = 0; i < n; i++)
        // {
        //     if (vec[i] <= k)
        //     {
        //         k++;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // return k;

        // Optimal solution
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s / 2);
            int count = 0;

            int valuesMissing = vec[mid] - (mid + 1);

            if (valuesMissing < k)
            {

                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return e + k + 1;
    }

    bool canWePlace(vector<int> stalls, int d, int cows)
    {
        int cntCows = 1;
        int lastPlacedCow = stalls[0];
        for (int stall : stalls)
        {
            if (stall - lastPlacedCow >= d)
            {
                cntCows++;
                lastPlacedCow = stall;
            }
            if (cntCows >= cows)
                return true;
        }
        return false;
    }
    int aggressiveCows(int n, vector<int> stalls, int cows)
    {

        sort(stalls.begin(), stalls.end());
        int maxDist = stalls[n - 1] - stalls[0];
        int ans = 0;
        // Brute Force
        // for (int d = 1; d <= maxDist; d++)
        // {
        //     if (canWePlace(stalls, d, cows))
        //     {
        //         ans = d;
        //     }
        // }
        // return ans;
        // Optimal
        int s = 1;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (canWePlace(stalls, mid, cows))
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

    int countStudents(vector<int> arr, int page)
    {
        int cntStudent = 1;

        int pagesStudent = 0;
        for (int p : arr)
        {
            if (p + pagesStudent <= page)
            {
                pagesStudent += p;
            }
            else

            {
                cntStudent++;
                pagesStudent = p;
            }
        }
        return cntStudent;
    }
    int bookAllocation(int n, vector<int> arr, int s)
    {
        if (s > n)
            return -1;
        int maxPages = *max_element(arr.begin(), arr.end());
        int sumOfAllPages = accumulate(arr.begin(), arr.end(), 0);

        // Brute Force
        // for (int page = maxPages; page <= sumOfAllPages; page++)
        // {
        //     if (countStudents(arr, page) == s)
        //         return page;
        // }
        // return maxPages;

        // Optimal Aprroach
        int low = maxPages;
        int high = sumOfAllPages;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (countStudents(arr, mid) <= s)
            {
                ans = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countK(vector<int> arr, int range)
    {
        int cnt = 1;
        int sum = 0;
        for (int num : arr)
        {
            if (sum + num <= range)
            {
                sum += num;
            }
            else
            {
                cnt++;
                sum = num;
            }
        }
        return cnt;
    }
    int splitArray(int n, vector<int> arr, int k)
    {
        int maxElement = *max_element(arr.begin(), arr.end());
        int sumOfAllElements = accumulate(arr.begin(), arr.end(), 0);
        // Brute Force
        // for (int i = maxElement; i <= sumOfAllElements; i++)
        // {
        //     if (countK(arr, i) == k)
        //     {
        //         return i;
        //     }
        // }
        // return maxElement;

        // Optiaml
        int s = maxElement;
        int e = sumOfAllElements;
        int ans = 0;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (countK(arr, mid) <= k)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }

    void MedianOfTwoSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> temp;
        for (int i = 0; i < n2; i++)
        {
            nums2[i] = temp[i];
        }
        for (int i = 0; i < n1 + n2; i++)
        {
            nums1[i + n1] = temp[i];
        }
        for (auto it : nums1)
        {
            cout << it << " ";
        }
    }
};
int main()
{
    int n1;
    cin >> n1;

    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }
    int n2;
    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }
    // int k;
    // cin >> k;

    // int h;
    // cin >> h;
    Solution solution;
    solution.MedianOfTwoSortedArrays(nums1, nums2);
    // cout << ans;
}