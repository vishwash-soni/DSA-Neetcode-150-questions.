/* ## LeetCode Problem 23: Merge k Sorted Lists
  
## Problem Description:
- You are given an array of k linked lists, where each linked list is sorted in ascending order. Your task is to merge all the linked lists into one sorted linked list and return it.

## Approach:
- The approach used here to merge k sorted linked lists is based on the Divide and Conquer strategy. Here's how the solution works:

- Merging Two Sorted Lists:
1) The function mergeTwoSortedLists merges two sorted linked lists recursively. It compares the head nodes of both lists, attaches the smaller node to the result, and recursively calls the function to merge the remaining nodes.

- Divide and Conquer (Partition and Merge):
1) The function partitionAndMerge divides the array of lists into two halves. It recursively processes each half until only two lists remain.
2) These two lists are then merged using the mergeTwoSortedLists function.
3) This process is repeated for the entire list array, reducing the problem size at each step.

- Base Cases:
If there are no lists (k == 0), return NULL.
If there's only one list (k == 1), return that list as it's already sorted.

## Time Complexity:
Merging two sorted lists takes O(N) time, where N is the total number of nodes in both lists combined.
The divide-and-conquer process divides the k lists, and merging them takes O(N log k) time, where N is the total number of nodes across all lists and k is the number of lists.
Overall Time Complexity: O(N log k).

## Space Complexity:
The space complexity is O(log k) due to the recursive stack depth used in the divide-and-conquer approach.
The space complexity is efficient as it only uses extra space for recursion. Other space usage is constant.

######################################### C++ ##########################################3 */

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
    ListNode* mergeTwoSortedLists(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoSortedLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoSortedLists(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(int start, int end,vector<ListNode*>& lists){
        
        if(start > end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }
        int mid = start + (end-start)/2;

        ListNode* L1 = partitionAndMerge(start,mid,lists);
        ListNode* L2 = partitionAndMerge(mid+1,end,lists);

        return mergeTwoSortedLists(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0){
            return NULL;
        }
        if(k==1){
            return lists[0];
        }
        return partitionAndMerge(0,k-1,lists);
    }
};

/*##################### Video solution ##################################

url : https://youtu.be/Q64u-W3l3mA?si=XjuS5LANQHIqCwP-

*/
