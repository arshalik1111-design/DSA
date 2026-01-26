#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int n, int arr[])
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void BubbleSort(int n, int arr[])
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // If left array finishes but there are elements in right array, we use while
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // Place elements from temp arr to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;

    } // Playaround with index. Recursion and backtracking
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);      // Left side
    mergeSort(arr, mid + 1, high); // Right side
    merge(arr, low, mid, high);
}
int findPivot(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (pivot >= arr[i] && i <= high - 1)
        {
            i++; // Element greater than pivot
        }
        while (pivot < arr[j] && j >= low + 1)
        {
            j--; // Element smaller than pivot
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int prtionidx = findPivot(arr, low, high);
        quickSort(arr, low, prtionidx - 1);
        quickSort(arr, prtionidx + 1, high);
    }
}

void RecursiveBS(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    int didSwap = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        didSwap = 1;
    }
    if (didSwap == 0)
    {
        return;
    }
    RecursiveBS(arr, n - 1);
}
void RecursiveIS(int arr[], int n, int i)
{
    if (i == n)
        return;
    while (i > 0 && arr[i] < arr[i - 1])
    {
        int temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        i--;
    }
    RecursiveIS(arr, n, i + 1);
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

    // mergeSort(arr, 0, n - 1);
    // quickSort(arr, 0, n - 1);
    // RecursiveBS(arr, n);
    RecursiveIS(arr, n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}