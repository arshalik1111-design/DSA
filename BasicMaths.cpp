#include <bits/stdc++.h>
using namespace std;

void printAllDivisors(int n)
{
}

void checkForPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }
    }
    if (cnt == 2)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}

void GCD(int n1, int n2)
{
    vector<int> ls;
    // int max_val = max(n1, n2);
    int min_val = min(n1, n2);
    int gcd = 1;
    for (int i = 1; i <= min_val; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            ls.push_back(i);
        }
    }
    auto max_it = max_element(ls.begin(), ls.end());

    cout << *max_it << " ";
}

void GCD2(int n1, int n2)
{

    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        cout << n2 << " ";
    else
        cout << n1 << " ";
}
int main()
{

    int n1;
    int n2;
    cin >> n1;
    cin >> n2;
    // GCD(n1, n2);
    GCD2(n1, n2);
}