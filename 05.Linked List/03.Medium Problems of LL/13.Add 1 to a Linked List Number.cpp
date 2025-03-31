//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next; // ✅ Corrected: Store next before changing curr->next
        curr->next = prev; // Reverse the link
        prev = curr;
        curr = next; // Move forward
    }
    return prev;
}
    
    Node* addOne(Node* head) {
        //Approach 2 - reverse the ll
        
        Node* revhead = reverse(head);
        Node* temp = revhead;
        int carry = 1;
        while(temp != NULL){
            temp->data += carry;
            carry = (temp->data) /10;
            temp->data %= 10;
            
            if(!carry){
                break;
            }
            
            temp = temp->next;
            
        }
        
        temp = reverse(revhead);
        
        if(carry){
            Node* n = new Node(carry);
            n->next = head;
            head = n;
        }
        return head;
        
        
        
        
        //Approach1 - Brute Force - Runtime error - stoi will not work 
        //for too large (e.g., more than 2147483647).
    
        //  // Convert linked list to string
        // string num = "";
        // Node* temp = head;
        // while (temp != NULL) {
        //     num += to_string(temp->data);
        //     temp = temp->next;
        // }

        // // Convert string to integer, add 1, convert back to string
        // int x = stoi(num);
        // x++;
        // num = to_string(x);

        // // Convert string back to linked list
        // temp = head;
        // for (int i = 0; i < num.length(); i++) {
        //     if (temp == NULL) {
        //         // If list is shorter, create new node
        //         temp = new Node(num[i] - '0');
        //         head->next = temp;  // Fix: Attach new node correctly
        //     } else {
        //         temp->data = num[i] - '0';  // Convert character to integer
        //     }
        //     temp = temp->next;
        // }

        // return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.

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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends