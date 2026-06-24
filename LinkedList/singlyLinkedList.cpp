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

class SolutionBruteForce
{
public:
    // Leetcode 876. Middle of the Linked List
    Node *middleNode(Node *head)
    {
        // If the list is empty or have only one node return it's head as the middle
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        int mid = cnt / 2 + 1;
        temp = head;
        while (temp != nullptr)
        {
            mid = mid - 1;
            if (mid == 0)
            {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    Node *reverseList(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(N)

        Node *curr = head;
        stack<int> st;
        while (curr != nullptr)
        {
            st.push(curr->data);
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr)
        {
            curr->data = st.top();
            st.pop();
            curr = curr->next;
        }
        return head;
    }

    bool detectCycle(Node *head)
    {
        // Time Complexity: O(N) | Space Complexity: O(N)
        Node *temp = head;
        unordered_map<Node *, bool> mp;
        while (temp != nullptr)
        {
            if (mp.find(temp) != mp.end())
            {
                return true;
            }
            // store the current node in map;
            mp[temp] = true;
            temp = temp->next;
        }
        return false;
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

    // Leetcode 876. Middle of the Linked List
    Node *middleNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // Leetcode 206. Reverse Linked List
    Node *reverseList(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(1)
        Node *curr = head;
        Node *prev = NULL;
        while (curr != nullptr)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    // function to print the list

    // Node *reverseListRecursively(Node *head)
    // {
    //     if (head == NULL || head->next == NULL)
    //     {
    //         return head;
    //     }
    // }
    bool detectCycle(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(N)
        Node *temp = head;
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
    // create a simple linkedlist: 2->3->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Solution sol;
    SolutionBruteForce sbf;

    // Original list
    cout << "Original List: ";
    sol.printList(head);
    head = sol.reverseList(head);
    cout << "After Operation: ";
    sol.printList(head);
    return 0;
}