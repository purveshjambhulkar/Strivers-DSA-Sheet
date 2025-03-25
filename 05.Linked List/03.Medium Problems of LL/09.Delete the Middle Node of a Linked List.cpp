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
        ListNode* deleteMiddle(ListNode* head) {
            // Approach 2 - Two Pointers
            if (head == nullptr || head->next == nullptr) {
                return nullptr;
            }
    
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = NULL;
    
            while (fast != NULL && fast->next != NULL) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
    
            prev->next = slow->next;
            return head;
    
            // Approach 1 - Brute Force
            // Edge case: If the list has only one node, return nullptr
            // if (head == nullptr || head->next == nullptr) {
            //     return nullptr;
            // }
    
            // // Count the length of the list
            // int len = 0;
            // ListNode* temp = head;
    
            // while (temp != nullptr) {
            //     len++;
            //     temp = temp->next;
            // }
    
            // // Find the node just before the middle
            // temp = head;
            // for (int i = 0; i < len / 2 - 1; i++) {
            //     temp = temp->next;
            // }
    
            // // Unlink the middle node
            // temp->next = temp->next->next;
    
            // return head;
        }
    };