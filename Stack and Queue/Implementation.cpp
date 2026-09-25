#include <bits/stdc++.h>

using namespace std;

class ArrayStack
{
private:
    vector<int> st;
    int capacity;
    int topIndex;

public:
    ArrayStack(int cap)
    {
        st.resize(cap);
        capacity = cap;
        topIndex = -1;
    }

    void push(int x, vector<string> &output)
    {
        // Stack get's full and have no more capacity
        if (topIndex == capacity - 1)
        {
            output.push_back("Stack Overflow");
            return;
        }
        // move topIndex one step ahead
        topIndex = topIndex + 1;
        // now push the new element at the topIndex index
        st[topIndex] = x;
        // record the successful push action
        output.push_back("Pushed: " + to_string(x));
    }

    void pop(vector<string> &output)
    {
        // if the stack is empty we cannot pop, it will cause stack underflow
        if (topIndex == -1)
        {
            output.push_back("Stack Underflow");
        }
        topIndex = topIndex - 1;
        output.push_back("Popped Value: " + to_string(st[topIndex]));
    }

    int top()
    {
        return st[topIndex];
    }
    bool isEmpty()
    {
        return topIndex == -1;
    }
};

class ArrayQueue
{
private:
    vector<int> q;
    int start;
    int end;
    int capacity;
    int currSize;

public:
    ArrayQueue()
    {
        capacity = 1000;
        q.resize(capacity);
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int x)
    {
        // Queue is full and have no capacity
        if (currSize == capacity)
        {
            return;
        }
        if (currSize == 0)
        {
            start++;
            end++;
        }
        else
        {
            end = (end + 1) % capacity;
        }
        q[end] = x;
        currSize++;
    }
    int pop()
    {
        if (currSize == 0)
        {
            return -1;
        }
        int el = q[start];
        // Queue have only one element and we are going to destroy the queue.
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % capacity;
        }
        currSize--;
        return el;
    }
    int peek()
    {
        if (currSize == 0)
            return -1;
        return q[start];
    }

    bool isEmpty() { return currSize == 0; }
};

class Solution
{

public:
    // Leetcode 20. Valid Parentheses
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                if (!((ch == '(' && s[i] == ')') || (ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}')))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
int main()
{
    string s = "]";
    Solution obj;
    bool res = obj.isValid(s);
    cout << res;
}