#include <bits./stdc++.h>
using namespace std;
// Node class to represent each node in the linked list
class Node
{
public:
    // Data stored in the node
    int data;
    // Pointer to the next node
    Node *next;
    // Constructor with data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    // Constructor with only data

    Node(int data2)
    {
        data = data2;
        next = nullptr;
    }
};

// Solution class to handle LinkedList operations
class Solution
{
public:
    // function to insert at head of LinkedList
    Node *insertAtHead(Node *head, int newData)
    {
        // Create a new node whose next points to current head
        Node *newNode = new Node(newData, head);
        // Return the new node as the head
        return newNode;
    }
    // function to print the list
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{

    Solution sol;

    // create a simple linkedlist: 2->3->4
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    // Original list
    cout << "Original List: ";
    sol.printList(head);
    head = sol.insertAtHead(head, 1);
    // List after Insertion
    cout << "After Insertion: ";
    sol.printList(head);
}