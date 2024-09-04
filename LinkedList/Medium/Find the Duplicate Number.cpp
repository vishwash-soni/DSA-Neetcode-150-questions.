287. Find the Duplicate Number

## Problem Description
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive, there is exactly one duplicate number in nums, but it can be repeated more than once. Your task is to find and return this duplicate number.

You must solve the problem without modifying the array and using only constant extra space.

## Approach
The approach used here is a variation of Floyd's Tortoise and Hare Algorithm (Cycle Detection Algorithm). The array can be visualized as a linked list where each index points to the next index determined by the value at the current index. The task of finding the duplicate is analogous to finding the cycle's entry point in a linked list.

Steps:
Initialization: Start both slow and fast pointers at the first element of the array.
Cycle Detection:
Move the slow pointer one step at a time.
Move the fast pointer two steps at a time.
Continue until the slow and fast pointers meet, indicating a cycle.
Finding the Cycle Start:
Reset one pointer (slow) to the start of the array.
Move both pointers one step at a time until they meet again. The meeting point is the start of the cycle, which is the duplicate number.
The algorithm leverages the properties of the cycle to locate the duplicate number without modifying the array.

## Time Complexity
O(n): The algorithm traverses the list in linear time. The two phases (detecting the cycle and finding the cycle's start) each take linear time.
## Space Complexity
O(1): This approach uses constant extra space since no additional data structures are used other than the two pointers.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow !=fast ){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
