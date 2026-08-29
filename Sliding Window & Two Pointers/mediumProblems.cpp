#include <bits./stdc++.h>
using namespace std;

class BruteForce
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> hash(256, 0);
            for (int j = i; j < s.length(); j++)
            {
                if (hash[s[j]] == 1)
                    break;
                hash[s[j]] = 1;

                int length = j - i + 1;
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }

    // Leetcode 1004. Max Consecutive Ones III
    int MaxConsecutiveOnesIII(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int zeroes = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                {
                    zeroes++;
                }
                if (zeroes > k)
                {
                    break;
                }
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
    // Leetcode 904. Fruit into Baskets
    int fruitIntoBaskets(vector<int> fruits)
    {
        int n = fruits.size();
        int maxFruits = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> basket;
            int currentCount = 0;

            for (int j = i; j < n; j++)
            {
                basket[fruits[j]]++;
                if (basket.size() > 2)
                {
                    break;
                }
                currentCount++;
            }
            maxFruits = max(maxFruits, currentCount);
        }
        return maxFruits;
    }

    // Leetcode 424. Longest Repeating Character Replacement
    int characterReplacement(string s, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < s.length(); j++)
            {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                int windowLength = j - i + 1;
                int replace = windowLength - maxFreq;
                if (replace <= k)
                {
                    maxLen = max(maxLen, windowLength);
                }
            }
        }
        return maxLen;
    }

    // Leetcode 930. Binary Subarrays With Sum
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == goal)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    // Leetcode 1248. Count Number of Nice Subarrays
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        for (int start = 0; start < n; start++)
        {
            int oddCount = 0;

            for (int end = start; end < n; end++)
            {
                if (nums[end] % 2 != 0)
                {
                    oddCount++;
                }
                if (oddCount > k)
                {
                    break;
                }

                if (oddCount == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        vector<int> hash(256, -1);
        while (r < s.length())
        {
            if (hash[s[r]] != -1)
            {
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxLength = max(maxLength, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLength;
    }

    // Leetcode 1004. Max Consecutive Ones III
    int MaxConsecutiveOnesIII(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        int zeroes = 0;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (nums[right] == 0)
            {
                zeroes++;
            }
            if (zeroes > k)
            {
                if (nums[left] == 0)
                {
                    zeroes--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    int fruitIntoBaskets(vector<int> fruits)
    {
        int n = fruits.size();
        int l = 0;
        int maxFruits = 0;
        unordered_map<int, int> basket;
        for (int r = 0; r < n; r++)
        {
            basket[fruits[r]]++;
            while (basket.size() > 2)
            {
                basket[fruits[l]]--;
                if (basket[fruits[l]] == 0)
                {
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxFruits = max(maxFruits, r - l + 1);
        }
        return maxFruits;
    }
    // Leetcode 904. Fruit into Baskets

    int fruitIntoBasketsOptimal(vector<int> fruits)
    {
        int maxLen = 0;
        int lastFruit = -1;
        int secondLastFruit = -1;

        int currCount = 0;
        int lastfruitStreak = 0;

        for (int fruit : fruits)
        {
            if (fruit == lastFruit || fruit == secondLastFruit)
            {
                currCount++;
            }
            else
            {
                currCount = lastfruitStreak + 1;
            }

            if (fruit == lastFruit)
            {
                lastfruitStreak++;
            }
            else
            {
                lastfruitStreak = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            maxLen = max(maxLen, currCount);
        }
        return maxLen;
    }
    // Leetcode 424. Longest Repeating Character Replacement

    int characterReplacement(string s, int k)
    {
        int n = s.length();
        int maxLen = 0;
        int l = 0;
        int maxFreq = 0;
        unordered_map<char, int> freq;

        for (int r = 0; r < n; r++)
        {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while ((r - l + 1) - maxFreq > k)
            {
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }

    // Leetcode 930. Binary Subarrays With Sum
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int> nums, int k)
    {
        if (k < 0)
            return 0;
        int cnt = 0;
        int left = 0;
        int n = nums.size();
        int sum = 0;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum > k)
            {
                sum -= nums[left];
                left++;
            }
            cnt += (right - left + 1);
        }
        return cnt;
    }

    // Leetcode 1248. Count Number of Nice Subarrays
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        int oddCount = 0;
        int left = 0;

        for (int right = 0; right < n; right++)
        {

            if (nums[right] % 2 != 0)
            { 
                oddCount++;
            }
            if (oddCount > k)
            {
                nums[left]--;
                if (nums[left] == 0)
                {
                }
                left++;
            }

            if (oddCount == k)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{

    // string s = "abcddabac";
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    // string s = "BAABAABBBAAA";
    int goal = 2;
    Solution sol;
    int r = sol.numberOfSubarrays(nums, goal);
    cout << r;
}