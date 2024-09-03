# LeetCode Problem 21: Merge Two Sorted Lists

## Problem Statement

You are given the heads of two sorted linked lists, `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Approach

To solve this problem, we will use a recursive approach:

1. **Base Cases**: 
    - If `list1` is `NULL`, return `list2` because there are no elements to merge from `list1`.
    - If `list2` is `NULL`, return `list1` because there are no elements to merge from `list2`.

2. **Recursive Case**:
    - Compare the current nodes of `list1` and `list2`.
    - Attach the node with the smaller value to the result list.
    - Recursively call the function to merge the next nodes.

## Algorithm

1. If `list1` is `NULL`, return `list2`.
2. If `list2` is `NULL`, return `list1`.
3. Initialize a pointer `result` to store the head of the merged list.
4. Compare the values of `list1` and `list2`:
   - If `list1->val` is less than `list2->val`, set `result` to `list1` and recursively merge the next node of `list1` with `list2`.
   - Otherwise, set `result` to `list2` and recursively merge `list1` with the next node of `list2`.
5. Return `result`.

## Time Complexity

- The time complexity of this algorithm is **O(n + m)**, where `n` is the number of nodes in `list1` and `m` is the number of nodes in `list2`. This is because we process each node in both lists exactly once.

## Space Complexity

- The space complexity of this algorithm is **O(n + m)** as well, due to the recursive call stack. Each recursive call adds a new frame to the stack until all nodes are processed.

################################# C++ Solution ####################################################################################################

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        }
        if(list2 == NULL) {
            return list1;
        }
        
        ListNode* result;
        
        if(list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        
        return result;
    }
};

################################# video solution #####################################################################################
URL : https://youtu.be/RreHsOfi14w?si=aKSaCiBcm1T_KA9o
