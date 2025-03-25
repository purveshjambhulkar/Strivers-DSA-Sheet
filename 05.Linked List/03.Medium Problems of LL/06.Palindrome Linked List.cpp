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
        bool isPalindromeUtil(vector<int> temp){
            int first = 0 ; 
            int last = temp.size() -1;
    
            while(first < last){
                if(temp[first] != temp[last]){
                    return false;
                }
                first++;
                last--;
            }
            return true;
        }
    
        bool isPalindrome(ListNode* head) {
            //Approach 3 - Slow & Fast Pointer
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            //find middle
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            //reverse the half LL
            ListNode* prev = NULL;
            ListNode* next = slow;
            ListNode* tempx = slow;
            while(next != NULL){
                next = tempx ->next;
                tempx ->next = prev;
                prev = tempx ;
                tempx= next;
            }
    
            //check palindrome
            while(head != slow){
                if(head->val != prev->val){
                    return false;
                }
                head= head->next;
                prev = prev->next;
            }
            return true;
    
          
            //Approach 2 - Using Stack
    
            // ListNode* temp = head;
            // stack<int> st;
            
            // while(temp != NULL){
            //     st.push(temp->val);
            //     temp = temp->next;
            // }
    
            // while(head != NULL){
            //     if(head->val != st.top()){
            //         return false;
            //     }
            //     st.pop();
            //     head = head->next;
            // }
    
            // return true;
    
    
            // //Approach 1 Brute Force
            // vector<int> temp;
            // while(head != NULL){
            //     temp.push_back(head->val);
            //     head = head->next;
            // }
    
            // return isPalindromeUtil(temp);
        }
    };