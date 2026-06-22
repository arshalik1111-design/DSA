#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    // Pointer to the next node
    Node *next;
    // Pointer to the previous node
    Node *prev;
    // Constructor when data, next and prev are provided
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    // Constructor when only data is provided
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution
{
public:
    // Function to convert an array to a doubly linked list

    Node *convertArr2DLL(vector<int> arr)
    {
        // Create the head node with the first element of the array
        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
    // Function to insert a new node with value 'k' at the end of the linkedlist.
    Node *insertAtTail(Node *head, int k)
    {
        Node *newNode = new Node(k);
        if (head == nullptr)
        {
            return newNode;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = nullptr;
        curr = newNode;
        return head;
    }

    Node *deletionOfTail(Node *head)
    {
        if (head == NULL)
        {

            return NULL;
        }
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->prev->next = NULL;
        delete curr;
        return head;
    }

    Node *reverseDLL(Node *head)
    {
        // If list is empty or has only one node, return as-is
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *curr = head;
        stack<int> st;
        while (curr != NULL)
        {
            st.push(curr->data);
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL)
        {
            curr->data = st.top();
            st.pop();
            curr = curr->next;
        }
        return head;
    }

    void printList(Node *head)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main()
{
    // Initialize an array of integers
    vector<int> arr = {7, 4, 2};
    Solution sol;

    // Convert the array into a doubly linked list
    Node *head = sol.convertArr2DLL(arr);

    // Original list
    cout << "Original List: ";
    sol.printList(head);
    head = sol.reverseDLL(head);

    cout << "After Insertion: ";
    sol.printList(head);
}