// #include <bits./stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int data1, Node *next1)
//     {
//         data = data1;
//         next = next1;
//     }
//     Node(int data2)
//     {
//         data = data2;
//         next = nullptr;
//     }
// };

// // Solution class to handle LinkedList operations
// class Solution
// {
// public:
//     // function to insert a new node at the head
//     Node *insertAtHead(Node *head, int newData)
//     {
//         // Create a new node whose next points to the curretn head
//         Node *newNode = new Node(newData, head);
//         // Return the new node as the head
//         return newNode;
//     }
//     void printList(Node *head)
//     {
//         Node *temp = head;
//         while (temp != nullptr)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     Solution sol;

//     // Creating a sample linked list: 2 -> 3
//     Node *head = new Node(2);
//     head->next = new Node(3);
//     head->next->next = new Node(4);

//     cout << "Original List: ";
//     sol.printList(head);

//     // Inserting new node at head
//     head = sol.insertAtHead(head, 1);

//     cout << "After Insertion at Head: ";
//     sol.printList(head);

//     return 0;
// }

#include <bits./stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *insertAtHead(Node *head, int newData)
    {
        Node *newNode = new Node(newData, head);
        return newNode;
    }
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