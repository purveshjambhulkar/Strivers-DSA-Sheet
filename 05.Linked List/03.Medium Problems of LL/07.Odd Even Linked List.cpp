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
        ListNode* oddEvenList(ListNode* head) {
            //Approach 2 - Optimising
            //check
            if(!head){
                return head;
            }
    
    
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = head->next;
    
            while(even != NULL && even->next != NULL){
                odd->next = odd->next->next;
                even->next = even->next->next;
                odd = odd->next;
                even = even->next;
            } 
    
            odd->next =  evenHead;
            return head;
    
    
            // Approach 1 - Brute Force
    
            // vector<int> odd;
            // vector<int> even;
    
            // ListNode* temp = head;
            // int count = 0;
            // while (temp != NULL) {
            //     count++;
            //     if (count % 2 != 0) {
            //         odd.push_back(temp->val);
            //     } else {
            //         even.push_back(temp->val);
            //     }
    
            //     temp = temp->next;
            // }
    
            // temp = head;
            // for(int i : odd){
            //     temp->val=i;
            //     temp = temp->next;
            // }
            // for(int i : even){
            //     temp->val=i;
            //     temp = temp->next;
            // }
            // return head;
        }
    };