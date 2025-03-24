/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* recursiveRev(ListNode* head, ListNode* prev, ListNode* nxt) {
    
            // base case
            if (head == NULL) {
                return prev;
            }
            nxt = head->next;  // Store next node
            head->next = prev; // Reverse current node's pointer
            prev = head;       // Move prev to current node
            head = nxt;
    
            // recursive call
            return recursiveRev(head, prev, nxt);
        }
    
        ListNode* reverseList(ListNode* head) {
            // Approach 3 - Recursive Approach
            ListNode* prev = nullptr;
            ListNode* nxt = nullptr;
            return recursiveRev(head, prev, nxt);
    
            // Approach 2 - Optimising in one Traversal
            // Two Pointers
    
            // ListNode* prev = nullptr;
            // ListNode* nxt = nullptr;
    
            // // Traverse the list
            // while (head != nullptr) {
            //     nxt = head->next;  // Store next node
            //     head->next = prev; // Reverse current node's pointer
            //     prev = head;       // Move prev to current node
            //     head = nxt;        // Move to next node
            // }
    
            // // Return new head (previous tail)
            // return prev;
    
            // Approach 1 - Brute Force (Using Stacks)
    
            // stack<int> st;
            // ListNode* temp = head;
            // while(temp != NULL){
            //     st.push(temp->val);
            //     temp = temp->next;
            // }
            // temp = head;
            // while(temp != NULL){
            //     int data = st.top();
            //     st.pop();
            //     temp->val = data;
            //     temp = temp->next;
            // }
    
            // return head;
        }
    };