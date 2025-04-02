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
        ListNode* rotateRight(ListNode* head, int k) {
            // Base cases
            if (!head || !head->next || k == 0) {
                return head;
            }
    
            // Compute the length of the list
            int len = 1;
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
                len++;
            }
    
            // Make the list circular
            temp->next = head;
    
            // Find the new tail (len - k % len - 1) and new head (len - k % len)
            k = k % len;
            int newTailPos = len - k - 1;
    
            temp = head;
            for (int i = 0; i < newTailPos; i++) {
                temp = temp->next;
            }
    
            // Set new head and break the cycle
            head = temp->next;
            temp->next = nullptr;
    
            return head;
        }
    };