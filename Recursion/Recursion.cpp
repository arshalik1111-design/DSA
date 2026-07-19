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

    // Leetcode 22. Generate Parentheses

    bool isValid(string s)
    {
        int balance = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            if (balance < 0)
                return false;
        }
        return balance == 0;
    }
    void generateParenthesis(int n, string curr, vector<string> &result)
    {
        if (curr.length() == 2 * n)
        {
            if (isValid(curr))
            {
                result.push_back(curr);
            }
            return;
        }
        generateParenthesis(n, curr + '(', result);
        generateParenthesis(n, curr + ')', result);
    }

    void SubsetIIHelper(int index, vector<int> &nums, set<vector<int>> &result, vector<int> &ds)
    {
        if (index == nums.size())
        {
            result.insert(ds);
            return;
        }
        ds.push_back(nums[index]);

        SubsetIIHelper(index + 1, nums, result, ds);
        ds.pop_back();
        SubsetIIHelper(index + 1, nums, result, ds);
    }
    vector<vector<int>> subsetII(vector<int> nums)
    {
        set<vector<int>> result;
        vector<int> ds;
        SubsetIIHelper(0, nums, result, ds);
        vector<vector<int>> newArr(result.begin(), result.end());
        return newArr;
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

    void reverse(stack<int> &st, int temp)
    {
        if (st.empty())
        {
            st.push(temp);
            return;
        }
        int val = st.top();
        st.pop();
        reverse(st, temp);

        st.push(val);
    }
    void reverseStack(stack<int> &st)
    {
        if (!st.empty())
        {
            int temp = st.top();
            st.pop();
            reverseStack(st);

            reverse(st, temp);
        }
    }

    void generateBinaryStrings(int n, string curr, vector<string> &result)
    {
        if (curr.length() == n)
        {
            result.push_back(curr);
            return;
        }

        generateBinaryStrings(n, curr + '0', result);

        if (curr.empty() || curr.back() != '1')
        {
            generateBinaryStrings(n, curr + '1', result);
        }
    }

    void generateParenthesis(int n, int opencount, int closeCount, string curr, vector<string> &result)
    {
        if (curr.length() == 2 * n)
        {
            result.push_back(curr);
            return;
        }
        if (opencount < n)
        {
            generateParenthesis(n, opencount + 1, closeCount, curr + '(', result);
        }
        if (closeCount < opencount)
        {
            generateParenthesis(n, opencount, closeCount + 1, curr + ')', result);
        }
    }

    vector<string> printSubsequence(string s)
    {
        int n = s.length();
        vector<string> subsequences;
        for (int i = 0; i < 1 << n; i++)
        {
            string subseq = "";
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subseq += s[j];
                }
            }
            subsequences.push_back(subseq);
        }
        return subsequences;
    }

    void SubSequenceHelper(int i, string curr, string &str, vector<string> &res)
    {

        if (i == str.size())
        {
            res.push_back(curr);
            return;
        }

        SubSequenceHelper(i + 1, curr, str, res);
        SubSequenceHelper(i + 1, curr + str[i], str, res);
    }
    vector<string> printSubsequenceRecursively(string str)
    {
        vector<string> res;
        string curr = "";
        SubSequenceHelper(0, curr, str, res);
        return res;
    }

    int countSubsequences(int index, int current_sum, int target, vector<int> &arr)
    {
        if (index == arr.size())
        {
            if (current_sum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int exclude_Path = countSubsequences(index + 1, current_sum, target, arr);
        int include_Path = countSubsequences(index + 1, current_sum + arr[index], target, arr);

        return exclude_Path + include_Path;
    }

    int CountAllSubSequencesWithSumK(vector<int> arr, int k)
    {
        return countSubsequences(0, 0, k, arr);
    }

    bool checkSubSequenceSum(int index, int current_sum, int k, vector<int> &arr)
    {
        if (index == arr.size())
        {
            return current_sum == k;
        }
        if (checkSubSequenceSum(index + 1, current_sum, k, arr))
        {
            return true;
        }
        if (checkSubSequenceSum(index + 1, current_sum + arr[index], k, arr))
        {
            return true;
        }
        return false;
    }

    bool CheckIfThereExistsASubsequenceWithSumK(vector<int> arr, int k)
    {
        return checkSubSequenceSum(0, 0, k, arr);
    }

    void findCombinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        // Base Case: if index == arr.size() i.e. we have traversed all the elements we check if current combination is equal to target
        if (index == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[index] <= target)
        {
            ds.push_back(arr[index]);
            findCombinations(index, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }
        findCombinations(index + 1, target, arr, ans, ds);
    }
    vector<vector<int>> CombinationSum(vector<int> candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }

    void findCombinationsII(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {

            if (i > index && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombinationsII(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> CombinationSumII(vector<int> candidates, int target)

    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationsII(0, target, candidates, ans, ds);
        return ans;
    }
    vector<vector<int>> subset(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> sequences;
        for (int i = 0; i < 1 << n; i++)
        {
            vector<int> subsets;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subsets.push_back(nums[j]);
                }
            }
            sequences.push_back(subsets);
        }
        sort(sequences.begin(), sequences.end());
        return sequences;
    }

    vector<int> subsetSum(vector<int> nums)
    {
        int n = nums.size();
        vector<int> sequences;
        for (int i = 0; i < (1 << n); i++)
        {
            int sum = 0;

            vector<int> arr;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    sum += nums[j];
                }
            }
            sequences.push_back(sum);
        }
        sort(sequences.begin(), sequences.end());
        return sequences;
    }

    // Find Subsets

    // Subset Sum Recursively
    void findSubsetSumRecursively(int index, vector<int> &ans, vector<int> &nums, int sum)
    {
        if (index == nums.size())
        {
            ans.push_back(sum);
            return;
        }
        findSubsetSumRecursively(index + 1, ans, nums, sum + nums[index]);
        findSubsetSumRecursively(index + 1, ans, nums, sum);
    }
    vector<int> subsetSumUsingRecursion(vector<int> nums)
    {
        vector<int> ans;

        findSubsetSumRecursively(0, ans, nums, 0);

        sort(ans.begin(), ans.end());
        return ans;
    }

    void SubsetIIHelper(int index, vector<int> &nums, vector<vector<int>> &result, vector<int> &ds)
    {
        result.push_back(ds);

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[index]);
            SubsetIIHelper(i + 1, nums, result, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetII(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        SubsetIIHelper(0, nums, result, ds);
        return result;
    }

    void helperCombinationSumIII(int sum, int last, int k, vector<vector<int>> &res, vector<int> &nums)

    {
        if (sum == 0 && nums.size() == k)
        {
            res.push_back(nums);
            return;
        }
        if (sum <= 0 || nums.size() > k)
            return;

        for (int i = last; i <= 9; i++)
        {

            if (i <= sum)
            {
                nums.push_back(i);
                helperCombinationSumIII(sum - i, i + 1, k, res, nums);
                nums.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSumIII(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> nums;
        helperCombinationSumIII(n, 1, k, res, nums);
        return res;
    }
};

int main()
{

    vector<int> arr = {1, 2, 2};
    int sum = 8;
    int k = 3;
    int n = 9;
    Solution sol;
    SolutionBruteForce sbf;

    vector<vector<int>> result = sol.combinationSumIII(k, n);

    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }
    // cout << "Combinations are: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " "; // Print each element of the combination
        }
        cout << endl; // Print a newline after each combination
    }

    // cout << "Sorted stack (descending order): ";
    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    return 0;
}