#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;
    int helper(int i, long long sign, long long num, string &s)
    {
        if (i >= s.size() || !isdigit(s[i]))
        {
            return num * sign;
        }
        num = (num * 10) + (s[i] - '0');
        if (sign * num >= INT_MAX_VAL)
            return INT_MAX_VAL;
        if (sign * num <= INT_MIN_VAL)
            return INT_MIN_VAL;

        return helper(i + 1, sign, num, s);
    }

    int atoi(string s)
    {
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        long long sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return helper(i, sign, 0, s);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.atoi(s);
    cout << ans;
}