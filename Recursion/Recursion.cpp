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

    // Leetcode 1922. Count Good Numbers
    const int mod = 1e9 + 7;
    int countGoodNumbers(int index, long long n)
    {
        // It will give TLE for bigger inputs
        if (index == n)
            return 1;
        int result = 0;
        if (index % 2 == 0)
        {
            for (int num : {0, 2, 4, 6, 8})
            {
                result = (result + countGoodNumbers(index + 1, n) % mod);
            }
        }
        else
        {
            for (int num : {2, 3, 5, 7})
            {
                result = (result + countGoodNumbers(index + 1, n) % mod);
            }
        }
        return result;
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

    const int mod = 1e9 + 7;

    long long powerII(long long x, long long y)
    {
        if (y == 0)
            return 1;
        if (y == 1)
            return x;

        long long half = powerII(x, y / 2) % mod;

        if (y % 2 == 0)
        {
            return (half * half) % mod;
        }
        else
        {
            return (x * ((half * half) % mod)) % mod;
        }
    }
    int countGoodNumbers(long long n)
    {
        //    Optimal Solution

        long long primes = n / 2;
        long long evens = n - primes;

        long long evenChoices = powerII(5, evens);
        long long oddChoices = powerII(4, primes);
        return (evenChoices * oddChoices) % mod;
    }

    //  Add '&' to pass st by reference
    void insert(stack<int> &st, int temp)
    {
        // Base case: if the stack is empty or temp is larger than the top element
        if (st.empty() || st.top() <= temp)
        {
            st.push(temp);
            return;
        }

        int val = st.top();
        st.pop();
        insert(st, temp);
        st.push(val);
    }
    void sortStack(stack<int> &st)
    {

        if (!st.empty())
        {
            int temp = st.top();
            st.pop();
            sortStack(st);

            insert(st, temp);
        }
    }
};

int main()
{
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    Solution sol;

    sol.sortStack(s);

    cout << "Sorted stack (descending order): ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}