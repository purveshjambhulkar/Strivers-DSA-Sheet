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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // Approach 2 - Two Pointer
    
            ListNode* fast = head;
            ListNode* slow = head;
    
            // move fast n times
            for (int i = 0; i < n; i++) {
                fast = fast->next;
            }
    
            // If fast becomes nullptr, it means we need to remove the head
            if (fast == nullptr) {
                return head->next;
            }
    
            // now move fast and slow simutaneosly
            while ( fast->next != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
    
            slow->next = slow->next->next;
    
            return head;
    
            // Approach 1 - Brute Force
    
            // Step 1: Find the length of the linked list
            // int length = 0;
            // ListNode* temp = head;
    
            // while (temp != nullptr) {
            //     length++;
            //     temp = temp->next;
            // }
    
            // // Step 2: Handle the edge case where the head needs to be removed
            // if (n == length) {
            //     return head->next; // Skip the head
            // }
    
            // // Step 3: Find the node just before the one to remove
            // temp = head;
            // for (int i = 0; i < length - n - 1; i++) {
            //     temp = temp->next;
            // }
    
            // // Step 4: Remove the target node
            // temp->next = temp->next->next;
    
            // return head;
        }
    };