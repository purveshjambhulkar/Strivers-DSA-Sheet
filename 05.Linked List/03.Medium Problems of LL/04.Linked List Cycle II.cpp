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
        ListNode* detectCycle(ListNode* head) {
            // Approach 2 - Slow & Fast Pointer
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
    
                if (slow == fast) {
                    // find the start point
                    //                 ✅ Why does this work?
                    // The distance from the head to the start of the cycle is the
                    // same as the distance from the meeting point to the start of
                    // the cycle. This is a mathematical property of cycles in
                    // linked lists.
    
                    slow = head;
    
                    while (slow != fast) {
                        slow = slow->next;
                        fast = fast->next;
                    }
    
                    return slow;
                }
            }
    
            return NULL;
    
            // Approach 1 - Brute force (hashing)
    
            // unordered_map<ListNode*  , int> mp;
            // ListNode* temp = head;
    
            // while(temp != NULL){
            //     //check
            //     if(mp[temp] == 1){
            //         return temp;
            //     }else{
            //         mp[temp] = 1;
            //     }
    
            //     temp = temp->next;
            // }
    
            // return NULL;
        }
    };