/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        void insertCopyInBetween(Node* head) {
            Node* temp = head;
            while (temp != NULL) {
                Node* nextElement = temp->next;
                // Create a new node with the same data
                Node* copy = new Node(temp->val);
    
                // Point the copy's next to
                // the original node's next
                copy->next = nextElement;
    
                // Point the original
                // node's next to the copy
                temp->next = copy;
    
                // Move to the next original node
                temp = nextElement;
            }
        }
    
        // Function to connect random
        // pointers of the copied nodes
        void connectRandomPointers(Node* head) {
            Node* temp = head;
            while (temp != NULL) {
                // Access the copied node
                Node* copyNode = temp->next;
    
                // If the original node
                // has a random pointer
                if (temp->random) {
                    // Point the copied node's random to the
                    // corresponding copied random node
                    copyNode->random = temp->random->next;
                } else {
                    // Set the copied node's random to
                    // null if the original random is null
                    copyNode->random = NULL;
                }
    
                // Move to the next original node
                temp = temp->next->next;
            }
        }
    
        // Function to retrieve the
        // deep copy of the linked list
        Node* getDeepCopyList(Node* head) {
            Node* temp = head;
            // Create a dummy node
            Node* dummyNode = new Node(-1);
            // Initialize a result pointer
            Node* res = dummyNode;
    
            while (temp != NULL) {
                // Creating a new List by
                // pointing to copied nodes
                res->next = temp->next;
                res = res->next;
    
                // Disconnect and revert back to the
                // initial state of the original linked list
                temp->next = temp->next->next;
                temp = temp->next;
            }
    
            // Return the deep copy of the
            // list starting from the dummy node
            return dummyNode->next;
        }
    
        // Function to clone the linked list
        Node* cloneLL(Node* head) {
            // If the original list
            // is empty, return null
            if (!head)
                return nullptr;
    
            // Step 1: Insert copy of
            // nodes in between
            insertCopyInBetween(head);
            // Step 2: Connect random
            // pointers of copied nodes
            connectRandomPointers(head);
            // Step 3: Retrieve the deep
            // copy of the linked list
            return getDeepCopyList(head);
        }
        Node* copyRandomList(Node* head) {
    
           return cloneLL(head);
    
            // Approach 1 - Using hashmap
    
            // if (!head)
            //     return NULL; // Edge case: empty list
    
            // unordered_map<Node*, Node*> mpp; // Map original node -> copied node
            // Node* temp = head;
    
            // // Step 1: Create new nodes and store in the hashmap
            // while (temp != NULL) {
            //     mpp[temp] = new Node(temp->val);
            //     temp = temp->next;
            // }
    
            // // Step 2: Assign next and random pointers
            // temp = head;
            // while (temp) {
            //     mpp[temp]->next = mpp[temp->next];     // Assign next pointer
            //     mpp[temp]->random = mpp[temp->random]; // Assign random pointer
            //     temp = temp->next;
            // }
    
            // return mpp[head]; // Return deep copy of head
        }
    };