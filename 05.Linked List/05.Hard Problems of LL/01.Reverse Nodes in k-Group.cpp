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
         // Helper function to find the K-th node from `start`
        ListNode* findKthNode(ListNode* start, int k) {
            while (start && --k) {
                start = start->next;
            }
            return start;
        }
    
        // Helper function to reverse a linked list segment
        ListNode* reverse(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            while (curr) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            return prev;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (!head || k == 1) return head;
    
            ListNode* temp = head;
            ListNode* prevNode = NULL;
            ListNode* newHead = NULL;
    
            while (temp) {
                ListNode* kthNode = findKthNode(temp, k);
                if (!kthNode) { // If remaining nodes are less than k, do not reverse
                    if (prevNode) {
                        prevNode->next = temp;
                    }
                    break;
                }
    
                ListNode* nextNode = kthNode->next;
                kthNode->next = NULL; // Temporarily break the list
    
                // Reverse the current k-group
                ListNode* reversedHead = reverse(temp);
    
                // Update new head for the first k-group
                if (!newHead) {
                    newHead = reversedHead;
                }
    
                // Connect previous group's tail to reversed head
                if (prevNode) {
                    prevNode->next = reversedHead;
                }
    
                // Move `prevNode` to the last node of this reversed segment
                prevNode = temp;
                temp = nextNode;
            }
    
            return newHead ? newHead : head;
        }
    };