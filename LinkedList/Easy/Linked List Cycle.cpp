141. Linked List Cycle.

##Approach
The approach used here is known as the Floyd's Tortoise and Hare Algorithm (Cycle Detection Algorithm). The idea is to have two pointers, one moving slowly (slow pointer) and the other moving quickly (fast pointer). The slow pointer advances one node at a time, while the fast pointer advances two nodes at a time.

Initialization: Start both slow and fast pointers at the head of the linked list.
Traversal: Move the slow pointer one step at a time and the fast pointer two steps at a time.
Cycle Detection: If there is a cycle, the fast pointer will eventually meet the slow pointer inside the loop. If fast reaches the end of the list (NULL), then there is no cycle.
The function returns true if a cycle is detected, otherwise, it returns false.

Time Complexity
O(n): In the worst case, where there is no cycle, each pointer will traverse through the entire list, making the time complexity linear with respect to the number of nodes.
Space Complexity
O(1): This approach uses constant extra space since no additional data structures are used other than the two pointers.

##################### C++ #################################################

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=NULL && fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
