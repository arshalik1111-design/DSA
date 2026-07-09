#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce
{
public:
    double myPow(double x, double n)
    {
        // Time Complexity : O(N) , Space Complexity: O(1)
        int ans = 1;
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        for (int i = 0; i < n; i++)
        {
            ans = ans * x;
        }
        return ans;
    }
};
class Solution
{
public:
    // Leetcode 8. String to Integer (atoi)
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

    // Leetcode 50. Pow(x, n)

    double power(double x, long n)
    {

        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;

        if (n % 2 == 0)
        {
            return power(x * x, n / 2);
        }
        return x * power(x, n - 1);
    }
    double myPow(double x, double n)
    {
        // Optimal Approach
        // Time Complexity : O(N) , Space Complexity: O(1)
        int num = n;
        if (num < 0)
        {
            return (1.0 / power(x, -1 * num));
        }
        return power(x, n);
    }
};

int main()
{
    // string s;
    // cin >> s;
    Solution sol;
    double ans = sol.myPow(2.0000, 6);
    cout << ans;
}