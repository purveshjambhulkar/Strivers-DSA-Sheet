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
        bool hasCycle(ListNode *head) {
            //Approach 2 - Slow & Fast Pointer
    
            ListNode* slow = head;
            ListNode* fast= head;
            
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
    
                if(slow == fast){
                    return true;
                }
            }
            return false;
    
    
            // //Approach 1 - Brute force (hashing)
    
            // unordered_map<ListNode*  , int> mp;
            // ListNode* temp = head;
    
            // while(temp != NULL){
            //     //check
            //     if(mp[temp] == 1){
            //         return true;
            //     }else{
            //         mp[temp] = 1;
            //     }
    
            //     temp = temp->next;
            // }
    
            // return false;
            
        }
    };