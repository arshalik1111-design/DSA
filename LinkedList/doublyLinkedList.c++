#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    // Pointer to the next node
    Node *next;
    // Pointer to the previous node
    Node *back;
    // Constructor when data, next and back are provided
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        back = prev1;
    }
    // Constructor when only data is provided
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};
class SolutionBruteForce
{
public:
    Node *reverseDLL(Node *head)
    {
        // Brute Force
        // Time Complexity: O(N) | Space Complexity: O(N)

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
};

class Solution
{
public:
    // Function to convert an array to a doubly linked list

    Node *convertArr2DLL(vector<int> arr)
    {
        // Create the head node with the first element of the array
        Node *head = new Node(arr[0]);
        Node *back = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr, back);
            back->next = temp;
            back = temp;
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
        newNode->back = curr;
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
        curr->back->next = NULL;
        delete curr;
        return head;
    }

    Node *reverseDLL(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(1)

        Node *curr = head;
        while (curr != NULL)
        {
            // Swap next and back pointers of current node
            Node *temp = curr->next;
            curr->next = curr->back;
            curr->back = temp;
            // Move to the next node in original order
            head = curr;
            curr = temp;
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
    vector<int> arr = {7, 4, 2, 3, 1, 5, 3, 12};
    Solution sol;
    SolutionBruteForce obj;
    // Convert the array into a doubly linked list
    Node *head = sol.convertArr2DLL(arr);
    // Original list
    cout << "Original List: ";
    sol.printList(head);
    // head = sol.reverseDLL(head);
    head = sol.reverseDLL(head);
    cout << "After Operation: ";
    sol.printList(head);
}