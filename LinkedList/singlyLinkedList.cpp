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

    // function to insert at the tail of the linked list.
    // Here, we have to take care of two edge cases:
    // 1. check if the list is empty or not, if the list is empty i.e. head == nullptr, the newNode becomes the head and the tail and we return the new node as our new head.

    Node *insertAtLast(int newData, Node *head)
    {
        Node *newNode = new Node(newData);
        // Scenario 1: Edge case - If list is empty
        if (head == nullptr)
            return newNode;
        // Scenario 2: Traverse to the last node
        Node *curr = head;
        while (curr->next != nullptr) // Stop EXACTLY at the last node
        {
            curr = curr->next;
        }
        curr->next = newNode;
        return head;
    }

    Node *deleteTail(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            delete head;
            return NULL;
        }

        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = NULL;
        return head;
    }

    int lengthOfLinkedList(Node *head)
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }

    bool searchInList(Node *head, int val)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->data == val)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
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
    // create a simple linkedlist: 2->3->4->5
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    // Original list
    // cout << "Original List: ";
    // sol.printList(head);
    Solution obj;

    if (obj.searchInList(head, 6))
        cout << "Found";
    else
    {
        cout << "Not Found";
    }
    // cout << "After Deletion: ";
    // sol.printList(head);
    return 0;
}