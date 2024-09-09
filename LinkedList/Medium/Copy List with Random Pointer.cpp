/* LeetCode Problem 138 - Copy List with Random Pointer

## Problem Description
- You are given a linked list where each node contains an additional random pointer, which could point to any node in the list or be null. You need to create a deep copy of the linked list. The deep copy should contain all the nodes of the original list, and their respective next and random pointers should also be copied.

## Approach
 The approach is divided into two main steps:

## Cloning the Linked List:
- First, we create a simple copy (or clone) of the original linked list by iterating through the original list.
- We use a helper function makeClone to traverse through the original list and create new nodes that replicate the values of the original nodes.
- The new cloned list has the same next pointer structure as the original list but does not yet account for the random pointers.

## Mapping Original Nodes to Cloned Nodes:
- We maintain an unordered map to store the mapping between each node in the original list and its corresponding node in the cloned list.
- We then iterate through the original list and set the random pointers in the cloned list by using the map to find the corresponding cloned node for each original node’s random pointer.
- By the end, we have a deep copy of the original list with both next and random pointers properly assigned.

## Time Complexity
O(n): We traverse the original linked list twice:
 - Once to create the cloned list.
 - Once to assign the random pointers using the map.
 - Both operations take linear time relative to the number of nodes n in the list.
  
## Space Complexity
O(n): We use additional space for the unordered map to store the mapping between original and cloned nodes. The space required is proportional to the number of nodes in the list.

####################################3 C++ ############################################################## */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* makeClone(Node* &head){
        if(head->next == NULL){
            Node* newNode = new Node(head->val);
            return newNode;
        }
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            if(cloneHead == NULL){
                cloneHead = newNode;
                cloneTail = newNode;
                temp = temp->next;
            }
            else{
                cloneTail->next = newNode;
                cloneTail = cloneTail->next;
                temp=temp->next;
            }
        }
        delete(temp);
        return cloneHead;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* cloneHead = makeClone(head);

        unordered_map<Node*,Node*>mp;
        Node* originalTemp = head;
        Node* cloneTemp = cloneHead;
        while(originalTemp != NULL){
            mp[originalTemp] = cloneTemp;
            originalTemp = originalTemp->next;
            cloneTemp = cloneTemp ->next;
        }
        originalTemp = head;
        cloneTemp = cloneHead;
        while(originalTemp!=NULL){
            cloneTemp ->random = mp[originalTemp->random];
            originalTemp = originalTemp->next;
            cloneTemp = cloneTemp ->next;
        }
        return cloneHead;
    }
};

/*############################# video solution ##################################3

url : https://youtu.be/83mPr0i56Gg?si=a1caDdhLUTFZMRwc

*/
