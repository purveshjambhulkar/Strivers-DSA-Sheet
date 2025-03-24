//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// A node of the doubly linked list
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
Node *push(Node *tail, int new_data) {
    // Allocate node
    Node *newNode = new Node(new_data);

    // Since we are adding at the end, next is NULL
    newNode->next = NULL;

    // Make newNode's previous pointer point to the current tail
    newNode->prev = tail;

    // If the tail is not null, link it to the new node
    if (tail != NULL)
        tail->next = newNode;

    // Return the new node as the new tail
    return newNode;
}

bool verifyDLL(Node *head) {
    int c1 = 0;
    Node *tmp = head;
    while (tmp->next) {
        c1++;
        tmp = tmp->next;
    }
    int c2 = 0;
    while (tmp->prev) {
        c2++;
        tmp = tmp->prev;
    }
    return c1 == c2;
}

// Function to print nodes in a given doubly linked list
void printList(Node *head) {
    // If list is empty
    if (head == NULL)
        return;
    if (!verifyDLL(head))
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* deleteFirst(Node* head){
        Node* curr = head ;
        head = head ->next;
        curr->next = NULL;
        head->prev = NULL;
        delete curr;
        return head;
    }
  
  
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        // Base case: if first node is to be deleted
    if (x == 1) {
        return deleteFirst(head);
    }

    Node *curr = head;
    Node *prev = NULL;

    // Traverse to the x-th node
    int count = 1;
    while (count < x && curr != nullptr) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If we reached a valid node
    if (curr != nullptr) {
        prev->next = curr->next;

        // Update the next node's prev pointer if it's not the tail
        if (curr->next != nullptr) {
            curr->next->prev = prev;
        }

        // Clean up the current node
        delete curr;
    }

    return head;
        
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            tail = push(tail, arr[i]);
        }

        int x;
        cin >> x;
        cin.ignore();

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        cout << "\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends