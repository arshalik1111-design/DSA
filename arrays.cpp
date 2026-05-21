#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // void largestElement(int arr[], int n)
    // {
    //     long max = arr[0];

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] > max)
    //         {
    //             max = arr[i];
    //         }
    //     }

    //     cout << max;
    // }
    // void secondSmallest(int arr[], int n)
    // {

    //     int largest = arr[0];
    //     int slargest = -1;
    //     for (int i = 1; i < n; i++)
    //     {
    //         if (arr[i] > largest)
    //         {
    //             slargest = largest;
    //             largest = arr[i];
    //         }
    //     }
    // }
    void secondLargest(int arr[], int n)
    {

        int largest = arr[0];
        int slargest = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > largest)
            {
                slargest = largest;
                largest = arr[i];
            }
        }
        cout << slargest;
    }

    void secondSmallest(int arr[], int n)
    {
        int small = INT_MAX;
        int secondSmall = INT_MAX;
        for (int i = 0; i < n; i++)
        {
        }
    }

    bool check_array_sorting(int arr[], int n)
    {
        if (n == 0 || n == 1)
        {
            return true;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    int removeDuplicates(vector<int> &arr, int n)
    {
        // Brute force
        //  set<int> s;
        //  for (int i = 0; i < n; i++)
        //  {
        //      s.insert(arr[i]);
        //  }

        // for (auto it : s)
        // {
        //     cout << it << " ";
        // }

        // Optimal Approach-Two Pointers

        int j = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                arr[j] = arr[i];
                j++;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
        }
    }

    void leftRotateTheArray(vector<int> &arr, int n, int k)
    {
        int var = arr[0, k];
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i + 1];
            arr[n] = var;
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void rightRotateArrayByDPlaces(vector<int> &arr, int n, int k)
    {
        if (n == 0)
            return;
        k = k % n;

        // //Brute Force
        // // Store elements in temp array
        // int temp[k];
        // for (int i = n - k; i < n; i++)
        // {
        //     temp[i - n + k] = arr[i];
        // }
        // // Shift elements by K place in original array
        // for (int i = n - k - 1; i >= 0; i--)
        // {
        //     arr[i + k] = arr[i];
        // }
        // // Copy temp array to original array
        // for (int i = 0; i < k; i++)
        // {
        //     arr[i] = temp[i];
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }

        // Optimal
        // 1. Reverse the entire array
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        // cout << endl;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
    }

    int LinearSearch(vector<int> &arr, int n, int k)
    {

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == k)
            {
                return i;
            }
        }
    }

    vector<int> FindUnion(vector<int> &arr1, vector<int> &arr2, int n, int m)
    {
        // USing Set
        // set<int> s;
        // for (int i = 0; i < n; i++)
        // {
        //     s.insert(arr1[i]);
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     s.insert(arr2[i]);
        // }
        // vector<int> UnionArr(s.begin(), s.end());
        // return UnionArr
        // for (auto it : s)
        // {
        //     cout << it << " ";
        // }

        // Using Map
        // prestoring
        // map<int, int> freq;
        // vector<int> Union;

        // for (int i = 0; i < n; i++)
        // {
        //     freq[arr1[i]]++;
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     freq[arr2[i]]++;
        // }

        // for (auto it : freq)
        // {
        //     Union.push_back(it.first);
        // }
        // return Union;

        // Using Two Pointers

        vector<int> Union;
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                if (Union.empty() || Union.back() != arr1[i])
                {
                    Union.push_back(arr1[i]);
                    i++;
                }
            }
            else if (arr2[j] < arr1[i])
            {
                if (Union.empty() || Union.back() != arr2[i])
                {
                    Union.push_back(arr2[j]);
                    j++;
                }
            }
            else
            {
                if (Union.empty() || Union.back() != arr1[i])
                {
                    Union.push_back(arr1[i]);
                    i++;
                    j++;
                }
            }
        }
        while (i < n)
        {
            if (Union.empty() || Union.back() != arr1[i])
            {
                Union.push_back(arr1[i]);

                i++;
            }
        }
        while (j < m)
        {
            if (Union.empty() || Union.back() != arr2[j])
            {
                Union.push_back(arr2[j]);

                j++;
            }
        }

        return Union;
    }

    int MissingNum(vector<int> &arr, int n)
    {

        // Brute Force
        // for (int i = 1; i <= n; i++)
        // {
        //     int flag = 0;

        //     for (int j = 0; j < n - 1; j++)
        //     {
        //         if (arr[j] == i)
        //         {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if (flag == 0)
        //         return i;
        // }
        // return -1;

        // Optimised Approach 1
        // Summation of N numbers
        // int sum = (n * (n + 1)) / 2;

        // // Sum of array elements
        // int arrSum = 0;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     arrSum = arrSum + arr[i];
        // }

        // int diff = sum - arrSum;

        // return diff;

        // Optimised Approach 2
        int xor2 = 0;
        int xor1 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            xor2 = xor2 ^ arr[i];
            xor1 = xor1 ^ (i + 1);
        }
        xor1 = xor1 ^ n;
        return xor1 ^ xor2;
    }
    int maxCount(vector<int> arr, int n)
    {
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                cnt++;
            }
            if (arr[i] == 0)
            {
                cnt = 0;
            }
            maxi = max(cnt, maxi);
        }

        return maxi;
    }
    int getSingleElement(vector<int> arr, int n)
    {

        // Brute Force
        //  for (int i = 0; i < n; i++)
        //  {
        //      int cnt = 0;

        //     for (int j = 0; j < n; j++)
        //     {
        //         if (arr[i] == arr[j])
        //         {
        //             cnt++;
        //         }
        //     }
        //     if (cnt == 1)
        //     {

        //         return arr[i];
        //     }
        // }
        // return -1;

        // Better Approach(Map data str)
        // map<int, int> map;
        // for (int i = 0; i < n; i++)
        // {
        //     map[arr[i]]++;
        // }

        // for (auto it : map)
        // {
        //     if (it.second == 1)
        //     {
        //         return it.first;
        //     }
        // }

        // Optimal Approach(Using XOR)
        int xorr = 0;
        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ arr[i];
        }

        return xorr;
    }
    int longestSubArraySum(vector<int> arr, int n, int k)
    {
    }

    void sortZeroOneTwo(vector<int> nums, int n)
    {
        // int cnt0 = 0;
        // int cnt1 = 0;
        // int cnt2 = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] == 0)

        //         cnt0++;

        //     else if (nums[i] == 1)

        //         cnt1++;

        //     else

        //         cnt2++;
        // }
        // int idx = 0;
        // while (cnt0--)
        // {
        //     nums[idx++] = 0;
        // }
        // while (cnt1--)
        // {
        //     nums[idx++] = 1;
        // }
        // while (cnt2--)
        // {
        //     nums[idx++] = 2;
        // }
        // Optimal Approach
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }

        for (auto it : nums)
        {
            cout << it << " ";
        }
    }

    int MajorityElement(vector<int> nums, int n)
    {
        // Brute Force
        //  for (int i = 0; i < n; i++)
        //  {
        //      int cnt = 0;

        //     for (int j = 0; j < n; j++)
        //     {

        //         if (nums[j] == nums[i])
        //         {
        //             cnt++;
        //         }

        //         if (cnt > n / 2)
        //         {
        //             return cnt;
        //         }
        //     }
        // }

        // Better Approach: Using hashmap
        // map<int, int> mpp;
        // for (int i = 0; i < n; i++)
        // {
        //     mpp[nums[i]]++;
        // }
        // for (auto it : mpp)
        // {

        //     if (it.second > n / 2)
        //     {
        //         return it.first;
        //     }
        // }
        // Optimal Approach
        int count = 0;
        int element;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                count = 1;
                element = nums[i];
            }
            else if (nums[i] == element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == element)
            {
                cnt1++;
            }
        }
        if (cnt1 > n / 2)
        {
            return element;
        }
        return -1;
    }

    int bestTimeToBuySell(vector<int> prices, int n)
    {
        // Brute Force
        //  int maxProfit = 0;
        //  for (int i = 0; i < n; i++)
        //  {
        //      for (int j = i + 1; j < n; j++)
        //      {
        //          int profit = prices[j] - prices[i];

        //         maxProfit = max(maxProfit, profit);
        //     }
        // }

        // Optimal Approach
        int mini = prices[0];
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;

            profit = max(profit, cost);
            mini = min(prices[i], mini);
        }

        return profit;
    }

    void RearrangeArrayElements(vector<int> arr, int n)
    {
        // Brute Force
        //  vector<int> pos;
        //  vector<int> neg;

        // for (int i = 0; i < n; i++)
        // {
        //     if (arr[i] > 0)
        //     {
        //         pos.push_back(arr[i]);
        //     }
        //     if (arr[i] < 0)
        //     {
        //         neg.push_back(arr[i]);
        //     }
        // }

        // int index = 0;
        // for (int i = 0; i < neg.size(); i++)
        // {

        //     arr[2 * i + 1] = neg[i];
        // }
        // for (int i = 0; i < pos.size(); i++)
        // {

        //     arr[2 * i] = pos[i];
        // }

        // for (auto it : pos)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : neg)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        // for (auto it : arr)
        // {
        //     cout << it << " ";
        // }

        // Optimal Approach

        int pos = 0;
        int neg = 1;
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                result[pos] = arr[i];

                pos += 2;
            }
            else
            {
                result[neg] = arr[i];

                neg += 2;
            }
        }
        for (auto it : result)
        {
            cout << it << " ";
        }
    }

    void nextPermutation(vector<int> arr, int n)
    {
        // Better Approach
        //  next_permutation(arr.begin(), arr.end());
        //  for (auto it : arr)
        //  {
        //      cout << it << " ";
        //  }

        // Optimal Approach

        // Finding break point
        int bp = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                bp = i;
                break;
            }
        }
        if (bp == -1)
        {
            reverse(begin(arr), end(arr));
            return;
        }
        // Swap break point and the element greater than it on the right side
        for (int i = n - 1; i > bp; i--)
        {
            if (arr[i] > arr[bp])
            {
                swap(arr[i], arr[bp]);
                break;
            }
        }
        // Reverse the array elements forward of break point till the end of the array

        reverse(arr.begin() + bp + 1, arr.end());

        // for (auto it : arr)
        // {
        //     cout << it << " ";
        // }
    }

    void LeadersInAnArray(vector<int> arr, int n)
    {

        // Brute Force
        vector<int> ans;
        //  for (int i = 0; i < n; i++)
        //  {

        //     bool leader = true;

        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (arr[j] > arr[i])
        //         {
        //             leader = false;
        //             break;
        //         }
        //     }
        //     if (leader == true)
        //     {
        //         ans.push_back(arr[i]);
        //     }
        // }

        // Optimal Approach
        int max = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }

    // Linear Search helper function
    bool LinearSearch(vector<int> &a, int num)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] = num)
            {
                return true;
            }
        }
        return false;
    }

    int LongestConsecutive(vector<int> arr, int n)
    {

        // Brute Force
        // int longest = 1;
        // for (int i = 0; i < n; i += 2)
        // {
        //     int x = arr[i];
        //     int cnt = 1;
        //     // Linear search
        //     while (LinearSearch(arr, x + 1) == true)
        //     {
        //         x = x + 1;
        //         cnt = cnt + 1;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        // Better Approach
        // sort(arr.begin(), arr.end());
        // int longest = 1;
        // int lastSmaller = INT_MIN;
        // int cnt = 0;

        // for (int i = 0; i < n; i++)
        // {
        //     if (arr[i] - 1 == lastSmaller)
        //     {
        //         cnt++;
        //         lastSmaller = arr[i];
        //     }
        //     else if (arr[i] != lastSmaller)
        //     {
        //         cnt = 1;
        //         lastSmaller = arr[i];
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        // Optimal Approach
        if (n == 0)
            return 0;
        int longest = 1;

        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(arr[i]);
        }

        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end())
                {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }

    void SetMatrixZero(vector<vector<int>> mt)
    {

        // Brute Force Approach
        //  int m = mt.size();
        //  int n = mt[0].size();

        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (mt[i][j] == 0)
        //         {
        //             // mark all elements of this row as -1 except existing zeroes
        //             for (int col = 0; col < n; col++)
        //             {
        //                 if (mt[i][col] != 0)
        //                 {
        //                     mt[i][col] = -1;
        //                 }
        //             }
        //             // mark all elements of this col as -1 except existing zeroes
        //             for (int row = 0; row < m; row++)
        //             {
        //                 if (mt[row][j] != 0)
        //                 {
        //                     mt[row][j] = -1;
        //                 }
        //             }
        //         }
        //     }
        // }

        // // Iterate thorugh the mt and whoever is -1 set them to 0
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (mt[i][j] == -1)
        //         {
        //             mt[i][j] = 0;
        //         }
        //     }
        // }

        // Better Approach
        int m = mt.size();
        int n = mt[0].size();
        vector<int> col(m, 0);
        vector<int> row(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mt[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    mt[i][j] = 0;
                }
            }
        }

        for (auto row : mt)
        {
            for (auto val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> RotateMatrix(vector<vector<int>> mt)
    {
        // Brute Force

        int n = mt.size();
        // // vector<vector<int>> ans(n, vector<int>(n));

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         mt[j][n - i - 1] = mt[i][j];
        //     }
        // }

        // return mt;

        // Optimal Solution
        // Transpose of the matrix
        for (int i = 0; i < n; i++)

        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mt[j][i], mt[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {

            reverse(mt[i].begin(), mt[i].end());
        }

        return mt;
    }

    void spiralMatrix(vector<vector<int>> &mt)
    {
        vector<int> result;
        int top = 0;
        int left = 0;
        int right = mt[0].size() - 1;
        int bottom = mt.size() - 1;

        while (top <= bottom && left <= right)
        {

            // Traverse from left to right across the top row
            for (int i = left; i <= right; i++)
            {
                result.push_back(mt[top][i]);
            }
            top++;
            // Traverse from top to bottom on the right coloumn
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(mt[i][right]);
            }
            right--;
            // Check if there are rows remianing
            if (top <= bottom)
            {
                // Traverse from right to left on the bottom row
                for (int i = right; i >= left; i--)
                {
                    result.push_back(mt[bottom][i]);
                }
                bottom--;
            }
        }
        // Traverse from bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(mt[i][left]);
            }
            left++;
        }
        for (auto it : result)
        {
            cout << it << " ";
        }
    }

    long long findPascalElement(int r, int c)
    {
        // Problem1
        // Given row and coloumn tell the element at that place
        int n = r - 1;
        int k = c - 1;
        int result = 1;

        for (int i = 0; i < k; i++)
        {
            result *= (n - i);
            result /= i + 1;
        }

        return result;
    }

    vector<vector<int>> PascalsTriangle(int numRows)
    {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }

    void majorityElementTwo(vector<int> nums)
    {
        // Brute Force
        // Empty List
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;

            if (ans.size() == 0 || ans[0] != nums[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] == nums[i])
                    {
                        cnt++;
                    }
                    if (cnt > (n / 3))
                    {
                        ans.push_back(nums[i]);
                    }
                }
                if (ans.size() == 2)
                {
                    break;
                }
            }
        }
        for (auto it : ans)
        {
            cout << it << " ";
        }
        // Better Solution
        // Optimal Solution
    }

    vector<vector<int>> threeSum(vector<int> nums)
    {
        // Brute Force
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        // Better Solution
    }

    int searchSingleElement(vector<int> nums, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) != i)
            {
                return (i + 1);
            }
        }
    }
};

int main()
{
    // int m;
    // cin >> m;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // int k;
    // cin >> k;
    // vector<vector<int>> mt = {{1, 2, 3},
    //                           {4, 5, 6},
    //                           {7, 8, 9}};
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> mt[i][j];
    //     }
    // }

    // vector<int> arr2(m);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> arr2[i];
    // }
    Solution obj;

    // vector<vector<int>> res = obj.threeSum(nums);
    // for (auto &it : res)
    // {
    //     for (auto &num : it)
    //     {ṇ
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    int r = obj.searchSingleElement(nums, n);
    cout << r << " ";
    // vector<vector<int>> rotated = obj.RotateMatrix(mt);
    // for (auto it : rotated)
    // {
    //     for (auto val : it)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    // for (int num : arr)
    // {
    //     cout << num << " ";
    // }
    // longestSubArraySum(arr, n);
    // cout << result;
    // vector<int> Union = obj.FindUnion(arr1, arr2, m, n);

    // for (auto &it : Union)
    // {
    //     cout << it << " ";
    // }

    // cout << LinearSearch(arr, n, k) << " ";
}