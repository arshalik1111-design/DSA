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
};

int main()
{

    // string s = "abcddabac";
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 3;
    Solution sbf;
    int r = sbf.MaxConsecutiveOnesIII(nums, k);
    cout << r;
}