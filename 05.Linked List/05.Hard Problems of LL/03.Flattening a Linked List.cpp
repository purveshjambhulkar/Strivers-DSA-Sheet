//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  
    Node* merge(Node* first , Node* second){
        Node* nextNode = second->next;
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(first && second){
            if(first->data <= second->data){
                temp->bottom = first;
                first = first->bottom;
            }else{
                temp->bottom = second;
                second = second->bottom;
            }
            temp = temp->bottom;
        }
        
        if(first){
            temp->bottom = first;
        }
        if(second){
            temp->bottom = second;
        }
        
        dummyNode->bottom->next = nextNode;
        
        return dummyNode->bottom;
    }
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        
        //Approach 2 - Merging ll
        
        //base case
        if(!root || !root->next){
            return root;
        }
        
        Node* temp = root;
        
        while(temp->next != NULL){
            temp = merge(temp , temp->next);
        }
        
        return temp;
        
        //Approach 1 - Brute Force
        
        // Base case
        // if (!root || !root->next) {
        //     return root;
        // }

        // // Store all elements in a vector
        // vector<int> v;
        // Node* temp = root;

        // while (temp != NULL) {
        //     Node* btm = temp;
        //     while (btm != NULL) {
        //         v.push_back(btm->data);
        //         btm = btm->bottom;
        //     }
        //     temp = temp->next;
        // }

        // // Sort the vector
        // sort(v.begin(), v.end());

        // // Create a new linked list using sorted values
        // Node* newHead = new Node(-1);  // Dummy node
        // temp = newHead;

        // for (int i : v) {
        //     temp->bottom = new Node(i);
        //     temp = temp->bottom;
        // }

        // return newHead->bottom;
        
        
      
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends