#include <bits/stdc++.h>
using namespace std;

void printNRev(int i, int n)
{

    if (i >= n)
    {
        return;
    }

    cout << n - i << " ";
    printNRev(i + 1, n);
}
void printNBT(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    printNBT(i - 1, n);
    cout << i << " ";
}
void printNBtRev(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printNBtRev(i + 1, n);
    cout << i << " ";
}
void sumOfNParameterized(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << " ";
        return;
    }
    sumOfNParameterized(i - 1, sum + i);
}
int SumofNFunctional(int n)
{

    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + SumofNFunctional(n - 1);
    }
}

int NFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * NFactorial(n - 1);
    }
}

void reverseAnArrayTwoP(vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    reverseAnArrayTwoP(arr, l + 1, r - 1);
}

void revArrOnePnt(vector<int> &arr, int i)
{
    int n = arr.size();
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    revArrOnePnt(arr, i + 1);
}

int Fibonacci(int n)
{

    if (n <= 1)
    {
        return n;
    }

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int query(int n, int arr[])
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == n)
        {
            cnt++;
        }
    }
    return cnt;
}
// void countFrequencyOfEachElement()
// {
// }

int main()
{
    int arr[] = {2, 6, 2, 4, 5, 2, 6};
    int n;
    cin >> n;
    cout << query(n, arr) << " ";
}