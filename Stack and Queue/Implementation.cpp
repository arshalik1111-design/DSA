#include <bits/stdc++.h>

using namespace std;

class ArrayStack
{
private:
    vector<int> st;
    int capacity;
    int top;

public:
    ArrayStack(int cap)
    {
        st.resize(cap);
        capacity = cap;
        top = -1;
    }

    void push(int x, vector<string> &output)
    {
        // Stack get's full and have no more capacity
        if (top == capacity - 1)
        {
            output.push_back("Stack Overflow");
            return;
        }
        // move top one step ahead
        top = top + 1;
        // now push the new element at the top index
        st[top] = x;
        // record the successful push action
        output.push_back("Pushed: " + to_string(x));
    }

    void pop(vector<string> &output)
    {
        // if the stack is empty we cannot pop, it will cause stack underflow
        if (top == -1)
        {
            output.push_back("Stack Underflow");
        }
        top = top - 1;
        output.push_back("Popped Value: " + to_string(st[top]));
    }

    int top()
    {
        return st[top];
    }
    bool isEmpty()
    {
        return top == -1;
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
int main()
{
}