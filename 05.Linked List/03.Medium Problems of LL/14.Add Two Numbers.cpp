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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            //Approach 1 
           int carry = 0;
            ListNode* dummy = new ListNode(0); // Dummy node to simplify logic
            ListNode* temp = dummy;
    
            while (l1 != nullptr || l2 != nullptr || carry) {
                int sum = carry;
                if (l1) {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    sum += l2->val;
                    l2 = l2->next;
                }
    
                carry = sum / 10;
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
            }
    
            return dummy->next; // Skip the dummy node and return actual head
        }
    };