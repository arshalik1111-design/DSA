#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static bool comparator(pair<int, char> p1, pair<int, char> p2)
    {
        if (p1.first > p2.first)
            return true;
        if (p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

public:
    string removeOuterMostParenthesis(string s)
    {
        string result = "";
        int level = 0;
        for (char currentChar : s)
        {
            if (currentChar == '(')
            {
                level++;

                if (level > 1)
                {
                    result += currentChar;
                }
            }
            if (currentChar == ')')
            {
                level--;

                if (level > 0)
                {
                    result += currentChar;
                }
            }
        }

        for (auto it : result)
        {
            cout << it << " ";
        }
    }

    string reverseWords(string s)
    {
        int n = s.size() - 1;
        // stringstream ss(s);
        // string word;
        // vector<string> words;
        // while (ss >> word)
        // {
        //     words.push_back(word);
        // }
        string r = "";
        int i = s[n - 1];
        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }
            if (i < 0)
                break;
            int end = i;
            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }

            string word = s.substr(i + 1, end - i);
            if (!r.empty())
            {
                r += " ";
            }
            r += word;
        }

        return r;
    }

    string largestOddNumber(string &s)
    {
        int idx = -1;
        int i;
        for (i = s.size() - 1; i >= 0; i--)
        {
            if ((s[i] - '0') % 2 == 1)
            {
                idx = i;
                break;
            }
        }
        // To Remove Leading zeroes
        i = 0;
        while (i <= idx && s[i] == '0')
            i++;
        return s.substr(i, idx - i + 1);
    }

    string longestCommonPrefix(vector<string> &s)
    {
        if (s.empty())
            return "";
        sort(s.begin(), s.end());
        string s1 = s[0];
        string s2 = s[s.size() - 1];
        string ans = "";
        int minlength = min(s1.size(), s2.size());
        for (int i = 0; i < minlength; i++)
        {
            if (s1[i] != s2[i])
            {
                break;
            }
            ans += s1[i];
        }
        return ans;
    }

    bool isomorphicStrings(string s, string t)
    {
        unordered_map<char, int> charIndexS;
        unordered_map<char, int> charIndexT;

        for (int i = 0; i < s.length(); i++)
        {
            if (charIndexS.find(s[i]) == charIndexS.end())
            {
                charIndexS[s[i]] = i;
            }
            if (charIndexT.find(t[i]) == charIndexT.end())
            {
                charIndexT[t[i]] = i;
            }
            if (charIndexS[s[i]] != charIndexT[t[i]])
            {
                return false;
            }
        }
        return true;
    }

    bool checkRotation(string s, string g)
    {

        if (s.length() != g.length())
            return false;
        // for (int i = 0; i < s.length(); i++)
        // {
        //     if (s.substr(i) + s.substr(0, i) == g)
        //     {
        //         return true;
        //     }
        // }
        // return false;

        // Optimal
        string doubledS = s + s;
        return doubledS.find(g) != string::npos;
    }

    bool validAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // Brute Force
        // for (int i = 0; i < s.length(); i++)
        // {
        //     if (s[i] != t[i])
        //         return false;
        // }
        // return true;

        // Optimal

        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            freq[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }

    string frequencySort(string s)
    {
        int n = s.length();

        // Frequency map to count frequency of character .
        unordered_map<char, int> count;
        for (char ch : s)
        {
            count[ch]++;
        }
        // Initialize frequency array to store characters and frequency in the array
        vector<pair<int, char>> freq;
        for (auto &it : count)
        {
            freq.push_back({it.second, it.first});
        }
        sort(begin(freq), end(freq), comparator);
        string ans = "";
        for (auto &p : freq)
        {
            ans.append(p.first, p.second);
        }
        return ans;
    }
    // Leetcode 1614. Maximum Nesting Depth of the Parentheses
    int maxDepth(string s)
    {
        int count = 0;
        int ans = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                count++;
                ans = max(ans, count);
            }
            else if (ch == ')')
            {
                count--;
            }
        }
        return ans;
    }
    // Leetcode 13. Roman to Integer
    int roamnToInt(string s)
    {

        int sum = 0;

        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (roman[s[i]] < roman[s[i + 1]])
            {
                sum -= roman[s[i]];
            }
            else
            {
                sum += roman[s[i]];
            }
        }
        return sum + roman[s.back()];
    }
    // 8. String to Integer (atoi)
    // We'll solve this problem using recursion, we keep on running the loop till we reach the end of the array or a non-digit is encounter

    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;
    int helper(string s, int i, int num, int sign)
    {
        if (i >= s.size() && !isdigit(s[i]))
            return (int)(sign * num);

        num = (num * 10) + (s[i] - '0');
        if (sign * num <= INT_MIN_VAL)
            return INT_MIN_VAL;
        if (sign * num >= INT_MAX_VAL)
            return INT_MAX_VAL;
        return helper(s, i + 1, num, sign);
    }
    int myAtoi(string s, int i = 0)
    {
        while (i < s.size() && s[i] == ' ')
            i++;

        // Handle the sign here ;
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return helper(s, i, 0, sign);
    }

    // Count Number Of Substrings
    int atMostKDistincts(string s, int k)
    {
        int l = 0;
        int res = 0;
        unordered_map<char, int> map;
        for (int r = 0; r < s.length(); r++)
        {
            map[s[r]]++;
            while (map.size() > k)
            {
                map[s[l]]--;
                if (map[s[l]] == 0)
                    map.erase(s[l]);
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }

    int countSubstrings(string s, int k)
    {
        return atMostKDistincts(s, k) - atMostKDistincts(s, k - 1);
    }

    // Leetcode 5. Longest Palindromic Substring
    int t[1001][1001];
    bool solve(string &s, int i, int j)
    {
        if (i >= j)
            return 1;
        if (t[i][j] != -1)
            return t[i][j];
        if (s[i] == s[j])
        {
            return t[i][j] = solve(s, i + 1, j - 1);
        }

        return t[i][j] = 0;
    }
    string longestPalindrome(string s)
    {
        int startIndex = 0;
        int maxLength = INT_MIN;
        memset(t, -1, sizeof(t));
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (solve(s, i, j))
                {
                    if ((j - i + 1) > maxLength)
                    {
                        maxLength = max(maxLength, (j - i + 1));
                        startIndex = i;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLength);
    }

    // Leetcode 1781. Sum of Beauty of All Substrings
    int beautySum(string s)
    {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> map;
            for (int j = i; j < n; j++)
            {
                map[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for (auto it : map)
                {
                    maxi = max(it.second, maxi);
                    mini = min(it.second, mini);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solution;
    int ans = solution.beautySum(s);
    cout << ans;
    return 0;
}