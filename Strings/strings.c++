#include <bits/stdc++.h>
using namespace std;

class Solution
{
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
};

int main()
{
    // int n;
    // cin >> n;
    // vector<string> s(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> s[i];
    // }
    string s;
    cin >> s;
    string t;
    cin >> t;

    Solution solution;

    bool ans = solution.isomorphicStrings(s, t);
    cout << ans;
    // return 0;
}