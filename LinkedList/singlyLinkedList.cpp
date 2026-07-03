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

    Node *detectCycleII(Node *head)
    {
        // Time Complexity: O(N) | Space Complexity: O(N)
        unordered_map<Node *, bool> mp;
        while (head != nullptr)
        {
            if (mp.find(head) != mp.end())
                return head;
            mp[head] = true;
            head = head->next;
        }
        return nullptr;
    }

    int loopLength(Node *head)
    {
        unordered_map<Node *, int> mp;
        Node *temp = head;
        int timer = 0;
        while (head != nullptr)
        {
            if (mp.find(head) != mp.end())
            {
                int length = timer - mp[temp];
                return length;
            }
            // Store the current node and its timer value
            mp[temp] = timer;

            // Move to the next node
            temp = temp->next;

            // Increment the timer
            timer++;
        }
        return 0;
    }
    // Leetcode 234. Palindrome Linked List

    bool isPalindrome(Node *head)
    {
        // Time Complexity: O(N) | Space Complexity: O(N)
        // Node *temp = head;
        stack<int> st;
        while (head != nullptr)
        {
            st.push(head->data);
            head = head->next;
        }
        head = head;
        while (head != nullptr)
        {
            if (head->data != st.top())
            {
                return false;
            }

            st.pop();

            head = head->next;
        }
        return true;
    }

    // Leetcode 328 : Odd Even List
    Node *oddEvenList(Node *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        Node *temp = head;
        vector<int> arr;
        while (temp != nullptr && temp->next != nullptr)
        {
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
        {
            arr.push_back(temp->data);
        }
        temp = head->next;
        while (temp != nullptr && temp->next != nullptr)
        {
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
        {
            arr.push_back(temp->data);
        }
        temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            temp->data = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }

    Node *removeNthFromEnd(Node *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        int cnt = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        if (cnt == n)
        {
            Node *newHead = head->next;
            delete head;
            return newHead;
        }
        int res = cnt - n;
        temp = head;
        while (temp != nullptr)
        {
            res--;

            if (res == 0)
            {
                break;
            }

            temp = temp->next;
        }
        Node *DelNode = temp->next;
        temp->next = temp->next->next;
        delete DelNode;
        return head;
    }

    Node *deleteMiddle(Node *head)
    {
        int cnt = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        int mid = cnt / 2;
        temp = head;
        while (temp != nullptr)
        {
            mid--;
            if (mid == 0)
                break;
            temp = temp->next;
        }
        Node *todel = temp->next;
        temp->next = temp->next->next;
        free(todel);
        return head;
    }

    Node *sortList(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(2*N + N*logN) | Space Complexity: O(N)
        vector<int> arr;
        Node *temp = head;
        while (temp != nullptr)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        sort(begin(arr), end(arr));
        temp = head;
        int i = 0;

        while (temp != nullptr)
        {
            temp->data = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
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
        // Optimal Approach: Iterative Aprroach
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

    Node *reverseListRecursively(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *newHead = reverseListRecursively(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
    bool detectCycle(Node *head)
    {
        // Optiaml Approach
        // Time Complexity: O(N) | Space Complexity: O(1)
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    Node *detectCycleII(Node *head)
    {
        // Optiaml Approach
        // Time Complexity: O(N) | Space Complexity: O(1)
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    int loopLength(Node *head)
    {
        // Optiaml Approach
        // Time Complexity: O(N) | Space Complexity: O(1)
        Node *slow = head;
        Node *fast = head;
        int cnt = 0;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                Node *temp = slow;
                int length = 1;
                while (temp->next != slow)
                {
                    temp = temp->next;
                    length++;
                }
                return length;
            }
        }
        return 0;
    }

    bool isPalindrome(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(1)

        Node *slow = head;
        Node *fast = head;
        if (head == nullptr || head->next == nullptr)
            return true;
        // Find middle of LL
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half i.e. list after the middle node
        Node *newHead = reverseListRecursively(slow->next);
        Node *firstHead = head;
        Node *secondHead = newHead;

        while (secondHead != nullptr)
        {

            if (firstHead->data != secondHead->data)
            {
                reverseListRecursively(newHead);
                return false;
            }
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }
        reverseListRecursively(newHead);
        return true;
    }

    Node *seperateEvenOdd(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *temp = head;
        Node *evenHead = new Node(-1);
        Node *evenTail = evenHead;
        Node *oddHead = new Node(-1);
        Node *oddTail = oddHead;

        while (temp != nullptr)
        {
            if (temp->data % 2 == 0)
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }

            temp = temp->next;
        }
        oddTail->next = evenHead->next;
        evenTail->next = nullptr;
        // Save the real result head before deleting the dummy anchors
        Node *newHead = oddHead->next;

        // Free up the dummy node memory to prevent leaks
        delete oddHead;
        delete evenHead;
        return newHead;
    }
    // Leetcode 328. Odd Even Linked List
    Node *oddEvenList(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(1)
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = head->next;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }

    Node *removeNthFromEnd(Node *head, int n)
    {
        // Optimal Approach
        // Time Complexity: O(N) | Space Complexity: O(1)
        Node *dummy = new Node(0, head);
        Node *slow = dummy;
        Node *fast = dummy;
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

    Node *deleteMiddle(Node *head)
    {
        // Optimal Approach
        // Time Complexity: O(N/2) | Space Complexity: O(1)
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        Node *slow = head;
        Node *fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *middle = slow->next;
        slow->next = slow->next->next;
        delete middle;
        return head;
    }

    // Function to find middle of the list
    Node *findMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // function to merge two sorted linked list
    Node *mergingTwoHalves(Node *list1, Node *list2)
    {
        Node *dummyNode = new Node(-1);
        Node *temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->data <= list2->data)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }
        return dummyNode->next;
    }
    // Leetcode 148. Sort List
    Node *sortLL(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *temp = head;

        Node *middle = findMiddle(head);

        Node *right = middle->next;
        middle->next = nullptr;
        Node *left = head;
        // Recursively split both halves of the list
        left = sortLL(left);
        right = sortLL(right);
        return mergingTwoHalves(left, right);
    }
    // Function to print the list
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

void testLoops()
{
    Solution sol;

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; // Create loop

    cout << "--- Testing Loop Length ---" << endl;
    int ans = sol.loopLength(head);
    if (ans > 0)
        cout << "Loop Length: " << ans << endl;
    else
        cout << "No Loop Found" << endl;
}

void testReverseList()
{
    Solution sol;

    // Creating a normal list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    sol.printList(head);

    head = sol.reverseList(head);

    cout << "Reversed List: ";
    sol.printList(head);
}
int main()
{
    // Create a simple linkedlist: 1->2->3->4->5
    Node *head = new Node(6);
    head->next = new Node(2);
    head->next->next = new Node(10);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Solution sol;
    SolutionBruteForce sbf;

    // testLoopLength();
    // testReverseList();

    // Original list
    cout << "Original List: ";
    sol.printList(head);
    head = sol.sortLL(head);

    cout << "List after operation: ";
    sol.printList(head);
    return 0;
}