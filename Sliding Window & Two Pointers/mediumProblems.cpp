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

    // Leetcode 1358. Number of Substrings Containing All Three Characters

    int numberOfSubstrings(string s)
    {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            set<char> st;
            for (int j = i; j < n; j++)
            {
                st.insert(s[j]);

                if (st.size() >= 3)
                {
                    count++;
                }
            }
        }
        return count;
    }

    // Leetcode 1423. Maximum Points You Can Obtain from Cards
    int maxScore(vector<int> cardPoints, int k)
    {
        int n = cardPoints.size();
        int maxSum = 0;
        for (int i = 0; i <= k; i++)
        {
            int tempSum = 0;
            // Sum of i elements from start
            for (int j = 0; j < i; j++)
            {
                tempSum += cardPoints[j];
            }
            // Sum of k-i elements from back

            for (int j = 0; j < k - i; j++)
            {
                tempSum += cardPoints[n - 1 - j];
            }

            maxSum = max(maxSum, tempSum);
        }
        return maxSum;
    }

    int longestKSubstr(string s, int k)
    {
        int maxLength = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            set<char> st;
            for (int j = i; j < n; j++)
            {
                st.insert(s[j]);

                if (st.size() <= k)
                {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            set<int> st;
            for (int j = i; j < n; j++)
            {
                st.insert(nums[j]);
                if (st.size() == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

class Better_solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int count = 0;

        int n = nums.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++)
        {
            if (prefixSum[j] == goal)
            {
                count++;
            }
            int val = prefixSum[j] - goal;
            if (mp.find(val) != mp.end())
            {
                count += mp[val];
            }
            if (mp.find(prefixSum[j]) == mp.end())
            {
                mp[prefixSum[j]] = 0;
            }
            mp[prefixSum[j]]++;
        }
        return count;
    }
};

class Optimal_solution
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

    // Leetcode 1358. Number of Substrings Containing All Three Characters

    int numberOfSubstrings(string s)
    {
        int res = 0;
        int n = s.length();
        int left = 0;
        vector<int> freq(3, 0);
        for (int r = 0; r < n; r++)
        {
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                res += (n - r);
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }

    // Leetcode 1423. Maximum Points You Can Obtain from Cards
    int maxScore(vector<int> cardPoints, int k)
    {

        int n = cardPoints.size();
        int total = 0;
        // Sum of first k elements

        for (int i = 0; i < k; i++)
        {
            total += cardPoints[i];
        }
        // Initial maxScore of first k elements, if it is the maxScore we get
        // this as answer otherwise we check from back for k elements.
        int maxScore = total;

        // Move window from front to back k times
        for (int i = 0; i < k; i++)
        {
            // Subtract cards from front

            total -= cardPoints[k - 1 - i];
            // Add cards from back

            total += cardPoints[n - 1 - i];
            // update maxScore if needed

            maxScore = max(maxScore, total);
        }
        return maxScore;
    }

    int longestKSubstr(string s, int k)
    {
        int maxLength = 0;
        int left = 0;
        int n = s.length();
        unordered_map<char, int> freq;
        for (int right = 0; right < n; right++)
        {
            freq[s[right]]++;

            if (freq.size() > k)
            {
                freq[s[left]]--;

                if (freq[s[left]] == 0)
                {
                    freq.erase(s[left]);
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }

    // Leetcode 992. Subarrays with K Different Integers

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }

    int countAtMostK(vector<int> &nums, int k)
    {
        int cnt = 0;
        unordered_map<int, int> freq;
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            if (freq[nums[r]] == 0)
            {
                k--;
            }
            freq[nums[r]]++;

            while (k < 0)
            {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                {
                    k++;
                }
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};

int main()
{

    // string s = "aababbcaacc";
    vector<int> nums = {1, 2, 1, 2, 3};
    // string s = "BAABAABBBAAA";
    int goal = 2;
    Optimal_solution sol;
    int r = sol.subarraysWithKDistinct(nums, 2);
    cout << r;
}