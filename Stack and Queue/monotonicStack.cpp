#include <bits/stdc++.h>
using namespace std;

class BruteForce
{
};
class OptimalSolution
{

private:
public:
    vector<int> nextGreaterElement(vector<int> nums)
    {
        int n = nums.size();

        vector<int> ans(n);
        // we will traverse from the last, as till we reach an element whose NGE is to be find, we will already know all the elements on it's right
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }

            else
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }

    // Leetcode 503. Next Greater Element II

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // Hypothetically we double the array and taverse from the end, also preserving the order of monotonic stack.
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            // Only store results when we are in the first pass range (actual indices)
            if (i < n)
            {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }

    // Leetcode 735. Asteroid Collision
    vector<int> asteroidCollision(vector<int> &arr)
    {
        vector<int> li;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            // store Positive elements into the list
            if (arr[i] > 0)
            {
                li.push_back(arr[i]);
            }
            else
            {
                // remove element from the list if arr[i]>st.back(), also the top element in list must be greater than 0.
                while (!li.empty() && li.back() > 0 && abs(arr[i]) > li.back())
                {
                    li.pop_back();
                }
                // if both the aesteroids have same absolute value and opposite directions
                if (!li.empty() && abs(arr[i]) == li.back())
                {
                    li.pop_back();
                }
                else if (li.empty() || li.back() < 0)
                {
                    li.push_back(arr[i]);
                }
            }
        }
        return li;
    }

    // Leetcode 907. Sum of Subarray Minimums

    // Find Previously smaller element for all indices
    vector<int> PSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> previousLess(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            previousLess[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return previousLess;
    }
    vector<int> NSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextLessOrEqual(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        { // Remove values that are strictly greater
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            nextLessOrEqual[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nextLessOrEqual;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long mod = 1e9 + 7;
        vector<int> previousLess = PSE(arr);
        vector<int> nextLessOrEqual = NSEE(arr);
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            int leftChoices = i - previousLess[i];
            int rightChoices = nextLessOrEqual[i] - i;

            long long contributions = (arr[i] * leftChoices) % mod;
            contributions = (contributions * rightChoices) % mod;

            answer = (answer + contributions) % mod;
        }
        return answer;
    }

    // Sum of Subarray Maximums
    vector<int> PGE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> previousMax(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            previousMax[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return previousMax;
    }
    vector<int> NGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextMaxOrEqual(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        { // Remove values that are strictly greater
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            nextMaxOrEqual[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nextMaxOrEqual;
    }
    int sumSubarrayMax(vector<int> &arr)
    {
        int n = arr.size();
        long long mod = 1e9 + 7;
        vector<int> previousMax = PGE(arr);
        vector<int> nextMaxOrEqual = NGEE(arr);
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            int leftChoices = i - previousMax[i];
            int rightChoices = nextMaxOrEqual[i] - i;

            long long contributions = (arr[i] * leftChoices) % mod;
            contributions = (contributions * rightChoices) % mod;

            answer = (answer + contributions) % mod;
        }
        return answer;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 4};

    OptimalSolution obj;
    int res = obj.sumSubarrayMax(arr);
    cout << res;
    // for (auto it : res)
    // {
    //     cout << it;
    // }
}