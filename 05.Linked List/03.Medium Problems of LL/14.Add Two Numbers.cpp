# Approach 1 - Iterative Addition with Carry

## Key Observations
- The problem requires adding two numbers represented as linked lists, where digits are stored in reverse order.
- A carry might be generated when summing two digits.
- If one list is longer, we continue addition using the remaining digits.
- If there’s a carry left after processing both lists, an extra node should be added.

## Steps
1. Create a **dummy node** to serve as the starting point.
2. Use a pointer (`temp`) to traverse and build the result list.
3. Maintain a **carry** variable to store overflow values.
4. Iterate through `l1` and `l2`:
   - Sum corresponding digits and the carry.
   - Create a new node for the resulting digit (`sum % 10`).
   - Update `carry = sum / 10`.
   - Move `l1` and `l2` forward if they exist.
5. If `carry > 0` after the loop, add a final node.
6. Return `dummy->next` as the result.

## Example Walkthrough
```
Input:
l1 = [2 -> 4 -> 3]  (represents 342)
l2 = [5 -> 6 -> 4]  (represents 465)

Processing:
2 + 5 = 7   (carry = 0)
4 + 6 = 10  (carry = 1, store 0)
3 + 4 + 1 = 8 (carry = 0)

Output:
[7 -> 0 -> 8] (represents 807)
```

## Complexity
- **Time Complexity:** `O(max(N, M))`, where `N` and `M` are the lengths of `l1` and `l2`.
- **Space Complexity:** `O(max(N, M))`, as we create a new linked list for the result.

## Code
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
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

        return dummy->next;
    }
};
```
