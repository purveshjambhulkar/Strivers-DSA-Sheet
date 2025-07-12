## **Linked List Reversal Patterns**

### Problem List

**Singly Linked List**
- [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list)
- [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group)

**Doubly Linked List**
- [Reverse a Doubly Linked List](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1)

---

## 1) Reverse Linked List  
🔗 [Problem Link](https://leetcode.com/problems/reverse-linked-list)

### Approach 1 - Stack Based (Brute Force)

#### TLDR
Push all node values into a stack and pop them while reassigning to the list. Only values are reversed.

#### Key Observations
- Does not change pointers.
- Space complexity is O(n).

#### Steps
1. Traverse and push all node values into a stack.
2. Traverse again and pop from stack, assigning new values to nodes.

#### TC SC
- Time: O(n)
- Space: O(n)

#### Code
```cpp
stack<int> st;
ListNode* temp = head;
while(temp != NULL){
    st.push(temp->val);
    temp = temp->next;
}
temp = head;
while(temp != NULL){
    int data = st.top();
    st.pop();
    temp->val = data;
    temp = temp->next;
}
return head;
```

---

### Approach 2 - Iterative Pointer Reversal

#### TLDR
Use 2 pointers: reverse the `next` of each node during traversal.

#### Key Observations
- In-place reversal.
- Space efficient.

#### Steps
1. Use `prev` and `next` pointers.
2. For each node:
   - Save `next`.
   - Reverse `next` pointer.
   - Advance both `prev` and `curr`.

#### TC SC
- Time: O(n)
- Space: O(1)

#### Code
```cpp
ListNode* prev = nullptr;
ListNode* nxt = nullptr;

while (head != nullptr) {
    nxt = head->next;
    head->next = prev;
    prev = head;
    head = nxt;
}
return prev;
```

---

### Approach 3 - Recursive Approach

#### TLDR
Recurse till end and reverse pointers while returning.

#### Key Observations
- Elegant and short.
- Stack space is used in recursion.

#### Steps
1. Base case: if head is NULL, return prev.
2. Store `head->next` in `nxt`.
3. Point `head->next = prev`.
4. Recurse for `nxt`.

#### TC SC
- Time: O(n)
- Space: O(n) (recursive stack)

#### Code
```cpp
class Solution {
public:
    ListNode* recursiveRev(ListNode* head, ListNode* prev, ListNode* nxt) {
        if (head == NULL) return prev;
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
        return recursiveRev(head, prev, nxt);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        return recursiveRev(head, prev, nxt);
    }
};
```

---

## 2) Reverse a Doubly Linked List  
🔗 [Problem Link](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1)

### Approach 1 - Swapping Pointers

#### TLDR
Swap `prev` and `next` for each node while moving through DLL.

#### Key Observations
- All nodes have both `prev` and `next`, so swap safely.
- Update head after loop.

#### Steps
1. Traverse the list.
2. Swap `prev` and `next` of each node.
3. Move to new `next` (which is the original `prev`).
4. Return the last valid `prev` (new head).

#### TC SC
- Time: O(n)
- Space: O(1)

#### Code
```cpp
class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* curr = head;
        DLLNode* prv = NULL;
        DLLNode* nxt = NULL;

        while(curr != NULL){
            nxt = curr->next;
            curr->prev = nxt;
            curr->next = prv;

            prv = curr;
            curr = nxt;
        }

        return prv;
    }
};
```

---

## 3) Reverse Nodes in k-Group  
🔗 [Problem Link](https://leetcode.com/problems/reverse-nodes-in-k-group)

### Approach 1 - Group Reversal with Helper Functions

#### TLDR
Reverse nodes in groups of `k`. Use helpers to find `k-th` node and reverse a segment.

#### Key Observations
- Reverses in-place.
- Handle edge case: less than `k` nodes remaining.
- Maintain `prevNode` to connect segments.

#### Steps
1. Use `findKthNode` to get `k-th` node from current.
2. If found:
   - Temporarily disconnect the group.
   - Reverse group using helper.
   - Connect with `prevNode`.
3. Continue from the next group.
4. If less than `k` nodes remain, leave them untouched.

#### TC SC
- Time: O(n)
- Space: O(1)

#### Code
```cpp
class Solution {
public:
    ListNode* findKthNode(ListNode* start, int k) {
        while (start && --k) {
            start = start->next;
        }
        return start;
    }

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
            if (!kthNode) {
                if (prevNode) {
                    prevNode->next = temp;
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* reversedHead = reverse(temp);

            if (!newHead) {
                newHead = reversedHead;
            }

            if (prevNode) {
                prevNode->next = reversedHead;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return newHead ? newHead : head;
    }
};
```
