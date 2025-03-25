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
        // Find the middle node of the list
        ListNode* findMid(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    
        // Merge two sorted lists
        ListNode* mergeList(ListNode* left, ListNode* right) {
            ListNode* head = new ListNode(-1); // Dummy node
            ListNode* temp = head;
    
            while (left != nullptr && right != nullptr) {
                if (left->val <= right->val) {
                    temp->next = left;
                    left = left->next;
                } else {
                    temp->next = right;
                    right = right->next;
                }
                temp = temp->next;
            }
    
            // Append the remaining nodes
            temp->next = (left != nullptr) ? left : right;
    
            return head->next;
        }
        ListNode* sortList(ListNode* head) {
            // Approach 2 - Merge Sort
            // Base case: 0 or 1 nodes
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
    
            // Find the midpoint of the list
            ListNode* mid = findMid(head);
            ListNode* left = head;
            ListNode* right = mid->next;
            mid->next = nullptr; // Split the list into two halves
    
            // Recursively sort both halves
            left = sortList(left);
            right = sortList(right);
    
            // Merge the sorted halves
            return mergeList(left, right);
    
            // Approach 1 - Brute Force
    
            // vector<int> LL;
            // ListNode* temp = head;
    
            // while(temp!= NULL){
            //     LL.push_back(temp->val);
            //     temp = temp->next;
            // }
    
            // temp = head;
            // sort(LL.begin() , LL.end());
    
            // for(int i : LL){
            //     temp->val = i;
            //     temp = temp->next;
            // }
    
            // return head;
        }
    };