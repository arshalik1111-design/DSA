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
};

int main()
{

    string s;
    cin >> s;

    Solution obj;
    string ans = obj.largestOddNumber(s);
    cout << ans;
}