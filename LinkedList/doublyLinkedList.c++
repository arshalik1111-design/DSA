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
    Node *insertAtTail(Node *head, int val)
    {
        Node *newNode = new Node(val);
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next->data = val;
        curr->next->next = nullptr;
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution sol;
    // Original list
    cout << "Original List: ";
    sol.printList(head);
    head = sol.insertAtTail(head, 6);

    cout << "After Insertion: ";
    sol.printList(head);
}