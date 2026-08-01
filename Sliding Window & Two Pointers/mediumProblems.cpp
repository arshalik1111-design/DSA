#include <bits./stdc++.h>
using namespace std;

class SolutionBruteForce
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
};

int main()
{

    // string s = "abcddabac";
    vector<int> nums = {1, 2, 3, 2, 2};
    int k = 3;
    Solution sbf;
    int r = sbf.fruitIntoBaskets(nums);
    cout << r;
}