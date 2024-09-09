/* 
## LeetCode Problem 19 - Remove Nth Node From End of List

## Problem Description
- Given the head of a singly linked list and an integer n, remove the nth node from the end of the list and return its head. The solution must operate in one pass, but this approach uses two passes to determine the length and then locate the node.

## Approach:
  
## The solution is divided into two phases:
  
  ## First Pass - Find the Length of the List:
  - We iterate through the linked list to calculate its length.
  - During this traversal, we keep count of how many nodes exist in the list.

  ## Second Pass - Remove the Nth Node:
  - After determining the length, we subtract n from the length to find the position of the node to be removed from the beginning.
  - We traverse the list again, stopping one node before the node to be removed.
  - Finally, we modify the next pointer of this node to skip the node to be removed.
  - This approach ensures that we can efficiently remove the nth node from the end by first identifying its position relative to the start of the list.

## Time Complexity
  O(n): We traverse the list twice:
    - Once to calculate the length of the list.
    - Once to find and remove the nth node from the end.
    - This results in a linear time complexity relative to the number of nodes n.

## Space Complexity
  O(1): We use a constant amount of extra space, regardless of the size of the input list.

  #################################### C++ ######################################################### */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len =0;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        if(len == n){
            return head->next;
        }
        len = len - n;
        temp = head;
        int count = 1;
        while(count<len){
            temp = temp->next;
            count++;
        }
        if(temp->next!=NULL){
            temp->next = temp->next->next;
        }
        return head;
    }
};
