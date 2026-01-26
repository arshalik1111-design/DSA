

#include <bits/stdc++.h>
using namespace std;

// Count frequency of each element in the array
// Brute Force
void countingFrequenciesofArrayElements(int n, int arr[])
{
    // n specifies the size of the vector (the number of elements it will contain). It is assumed that n is an integer variable defined earlier in the code.
    // false sets the initial value of all n elements in the vector to false.

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
        {
            continue;
        }
        int cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;

                cnt++;
            }
        }
        cout << arr[i] << "->" << cnt << endl;
    }
}

// Optimal Approach
void countingFreqOfArrElements(int n, int arr[])
{
    unordered_map<int, int> mpp;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    int minFreq = INT_MAX;
    int maxFreq = INT_MIN;
    int minElement = -1;
    int maxElement = -1;

    for (auto it : mpp)
    {
        int element = it.first;
        int frequency = it.second;

        if (frequency < minFreq)
        {
            minFreq = frequency;
            minElement = element;
        }

        if (frequency > maxFreq)
        {
            maxFreq = frequency;
            maxElement = element;
        }
    }
}

// Find the highest/lowest frequency element
void FreqOfMostFrequentElement(int n, int arr[])
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    int min_f = INT_MAX;
    int max_f = INT_MIN;
    int minE = -1;
    int maxE = -1;
    for (auto it : map)
    {
        int element = it.first;
        int freq = it.second;

        if (freq < min_f)
        {
            min_f = freq;
            minE = element;
        }

        if (freq > max_f)
        {
            max_f = freq;
            maxE = element;
        }
    }
    cout << maxE << "->" << max_f << endl;
    cout << minE << "->" << min_f << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // countingFreqOfArrElements(n, arr);
    // countingFrequenciesofArrayElements(n, arr);

    FreqOfMostFrequentElement(n, arr);
}