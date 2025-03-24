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
        ListNode* middleNode(ListNode* head) {
    
            //Approach 2 - Two Pointer
            //move one ptr by one pos at time and the other by two pos at time
            //when the 2nd ptr reaches the last node return the first ptr as it is pointing to the middle element now
    
    
            ListNode* first = head;
            ListNode* sec = head;
            while(sec != NULL&&sec->next != nullptr  ){
                first = first->next;
                sec= sec->next ->next;
            }
            return first;
    
    
            //Approach 1 - Brute Force
            //Find lenght and then traverse till middle element
    
            // //find length
            // ListNode* temp = head;
            // int count = 1;
            // while(temp->next != NULL){
            //     temp = temp->next;
            //     count++;
            // }
    
            // //traverse till middle
            // int mid =( count/ 2);
    
            // for(int i = 0 ; i < mid; i++){
            //     head = head->next;
            // }
            // return head;
    
        }
    };