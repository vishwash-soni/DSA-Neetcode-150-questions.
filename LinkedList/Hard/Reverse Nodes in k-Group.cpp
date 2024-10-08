# Reverse Nodes in k-Group (LeetCode 25)

## Problem Description

Given a linked list, reverse the nodes of the list `k` at a time and return its modified list. `k` is a positive integer, and it's given that `k` is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k`, then the nodes left out at the end should remain as they are.

- **Input**: The first node of a linked list and an integer `k`.
- **Output**: The head of the modified linked list.

### Example

- **Input**: `head = [1, 2, 3, 4, 5], k = 2`
- **Output**: `[2, 1, 4, 3, 5]`

- **Input**: `head = [1, 2, 3, 4, 5], k = 3`
- **Output**: `[3, 2, 1, 4, 5]`

## Solution Approach

The solution uses a recursive approach to reverse the nodes of the linked list in groups of `k`. Here's a step-by-step breakdown:

1. **Calculate the Length of the Linked List**:
   - First, traverse the linked list to find its total length. This helps in determining if there are enough nodes left to reverse in groups of `k`.

2. **Recursive Reversal Function**:
   - Use a helper function to reverse the first `k` nodes of the list.
   - Recursively call this function to reverse subsequent groups of `k` nodes.
   - Connect the reversed nodes with the rest of the list.

3. **Connect Segments**:
   - After reversing a group of `k` nodes, if more nodes are left, the end of the current reversed group is connected to the start of the next reversed group.

## Code

************************************************************ C++ ************************************************************
```cpp
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
    int length(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    ListNode* reverse(ListNode* head, int k, int len) {
        if(len < k) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;
        while(curr != NULL && count < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward != NULL) {
            head->next = reverse(forward, k, len - k);
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        return reverse(head, k, len);
    }
};

Time Complexity: O(N), where N is the number of nodes in the linked list. The linked list is traversed once to calculate its length and once more during the reversal process.

Space Complexity: O(N/k) due to recursion. Each recursive call handles a group of k nodes, leading to a recursion depth of N/k in the worst case. This can be optimized to O(1) if the iterative approach is used instead of recursion.


*********************************************************** Video Solution ************************************************************

Video Solution : https://youtu.be/vqaO4oIJqnI?si=8JLMrsykK60JJwIb

