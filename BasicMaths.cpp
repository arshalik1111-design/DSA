#include <bits/stdc++.h>

using namespace std;

int main()
{
    // take digits
    int n = 7789;
    while (n > 0)
    {
        int ld = n % 10;
        int count = n / 10;
        cout << ld << " ";
    }
}
