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

    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int length = 0;
        for (int i = 0; i < s.length(); i++)
        {
        }
    }
};

int main()
{

    string s = "abcddabac";
    SolutionBruteForce sbf;
    int r = sbf.lengthOfLongestSubstring(s);
    cout << r;
}