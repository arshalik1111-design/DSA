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
};

int main()
{

    string s = "abcddabac";
    Solution sbf;
    int r = sbf.lengthOfLongestSubstring(s);
    cout << r;
}