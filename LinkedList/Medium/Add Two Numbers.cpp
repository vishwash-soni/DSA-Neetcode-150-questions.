/* ## Leetcode  2. Add Two Numbers

## Problem Description

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input:
l1 = [2,4,3]
l2 = [5,6,4]

Output:
[7,0,8]
Explanation: 342 + 465 = 807.

## Approach
Reverse List Function: A helper function reverseList reverses a linked list by iterating through the list and updating the next pointer of each node to point to the previous node. This step is useful if needed, but in this problem, the numbers are already stored in reverse order, so we do not need to reverse the lists for addition.

Addition of Two Lists (add):

We initialize two pointers (l1, l2) to traverse through both input lists.
We maintain a carry to handle sums greater than 9.
For each node in both lists, we add the values of corresponding nodes and the carry, create a new node for the sum's last digit, and adjust the carry for the next iteration.
If one list is longer than the other, we continue adding the remaining nodes with the carry.
After processing both lists, if there is still a non-zero carry, we append a new node with that value.
Final List: The result is returned as a new linked list representing the sum of the two numbers.

## Time Complexity
O(max(n, m)): Where n and m are the lengths of the two linked lists. We traverse both lists once, so the time complexity is linear with respect to the size of the larger list.

## Space Complexity
O(max(n, m)): The space complexity is determined by the size of the new list, which is the maximum length of the two input lists, plus one additional node for the carry (if necessary).

######################################## C++ ################################################################# */

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
    ListNode* reverseList(ListNode* head){
        if(head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1!=NULL && l2!=NULL){
            int sum = carry + l1->val + l2->val;
            int digit = sum%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL && tail == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1!=NULL){
            int sum = carry + l1->val;
            int digit = sum%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL && tail == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            carry = sum/10;
            l1 = l1->next;
        }

        while(l2 != NULL){
            int sum = carry + l2->val;
            int digit = sum%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL && tail == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            carry = sum/10;
            l2 = l2->next;
        }
        while(carry!=0){
            int sum = carry;
            int digit = sum%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL && tail == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            carry = sum/10;

        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1,l2);
        return ans;
    }
};
/* #################### video link ########################################

url : https://youtu.be/HiRlTPf9aCg?si=hX4IwZaY7V6waaxD

*/
