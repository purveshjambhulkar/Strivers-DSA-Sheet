//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
  
  Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted lists
    Node* mergeList(Node* left, Node* right) {
        Node* head = new Node(-1); // Dummy node
        Node* temp = head;

        while (left != nullptr && right != nullptr) {
            if (left->data <= right->data) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        // Append the remaining nodes
        temp->next = (left != nullptr) ? left : right;

        return head->next;
    }
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        
        //Approach 2 - Merge Sort
        
        // Base case: 0 or 1 nodes
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find the midpoint of the list
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = nullptr; // Split the list into two halves

        // Recursively sort both halves
        left = segregate(left);
        right = segregate(right);

        // Merge the sorted halves
        return mergeList(left, right);
        

        // Add code here
        //Approach 1 - Brute Force

        // vector<int> LL;
        // Node* temp = head;

        // while(temp!= NULL){
        //     LL.push_back(temp->data);
        //     temp = temp->next;
        // }

        // temp = head;
        // sort(LL.begin() , LL.end());

        // for(int i : LL){
        //     temp->data = i;
        //     temp = temp->next;
        // }
        
        // return head;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends