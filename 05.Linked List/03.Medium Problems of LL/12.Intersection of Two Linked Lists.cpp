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
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    
            //Approach 3 - Optimal Approach
            
            if(headA == NULL || headB == NULL) return NULL;
            ListNode* temp1 = headA;
            ListNode* temp2 = headB;
    
            while(temp1 != temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
    
                if(temp1 == temp2){
                    return temp1;
                }
    
                if(temp1 == NULL) temp1 = headB;
                if(temp2 == NULL) temp2 = headA;
            }
            return temp1;
    
    
            // Approach 2 - using the length of LL
    
            // int len1 = 0;
            // ListNode* temp = headA;
            // while (temp != NULL) {
            //     len1++;
            //     temp = temp->next;
            // }
    
            // int len2 = 0;
            // temp = headB;
            // while (temp != NULL) {
            //     len2++;
            //     temp = temp->next;
            // }
    
            // if(len1 > len2){
            //     for(int i = 0 ; i < len1 - len2; i++){
            //         if(headA == headB){
            //             return headA;
            //         }else{
            //             headA = headA->next;
            //         }
            //     }
            // }else if(len2 > len1){
            //     for(int i = 0 ; i < len2 - len1 ; i++){
            //         if(headA == headB){
            //             return headA;
            //         }else{
            //             headB = headB->next;
            //         }
            //     }
            // }
    
            // while(headA!=NULL){
            //     if(headA == headB){
            //         return headA;
            //     }
            //     headA = headA ->next;
            //     headB = headB ->next;
            // }
    
            // return NULL;
    
    
    
    
            // //Approach 1 - Brute Force
    
            // unordered_map<ListNode* , int> mp;
            // while(headA != NULL){
            //     mp[headA] = 1;
            //     headA = headA->next;
            // }
    
            // while(headB != NULL){
            //     if(mp[headB] == 1){
            //         return headB;
            //     }else{
            //         mp[headB] = 1;
            //     }
    
            //     headB = headB -> next;
            // }
    
            // return NULL;
        }
    };