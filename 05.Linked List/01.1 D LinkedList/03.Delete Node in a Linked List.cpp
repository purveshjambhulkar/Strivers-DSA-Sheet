/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
    public:
        void deleteNode(ListNode* node) {
            // Approach 2
            node->val = node->next->val;
            node->next = node->next->next;
    
            //Approach 1
    
            // while (true) {
    
            //     // check if its second last node
            //     if (node->next->next == NULL) {
            //         node->val = node->next->val;
            //         node->next = NULL;
            //         return;
            //     }
    
            //     node->val = node->next->val;
            //     node = node ->next;
            // }
        }
    };