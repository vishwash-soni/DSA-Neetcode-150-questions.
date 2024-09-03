# LeetCode Problem 206: Reverse Linked List

## Problem Description
Given the head of a singly linked list, reverse the list, and return the reversed list.

### Example:
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[5, 4, 3, 2, 1]`

### Constraints:
- The number of nodes in the list is in the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

## Solution

The solution uses a recursive approach to reverse the linked list.
It works by reversing the rest of the list after the current node,
then setting the next node's next pointer to the current node,
effectively reversing the link. 
The base cases are when the head is `NULL` or the list contains only one node.

## Time and Space Complexity
  
- Time Complexity: O(n)
The function traverses each node of the linked list exactly once, resulting in a linear time complexity where n is the number of nodes in the list.

- Space Complexity: O(n)
The recursive approach uses the call stack to store the function calls. In the worst case, this will use O(n) space, where n is the number of nodes in the linked list.

######################################## C++ Code: ######################################################################################3

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};

########################### video solution ####################################################################################
URL: https://youtu.be/RreHsOfi14w?si=p1B84sCVaov4asem
