/* Leetcode 11. Container With Most Water

## Problem Description
You have an array where each element represents the height of a vertical line. You need to find two lines that, together with the x-axis, form a container that can hold the most water.

Example:
If you have the heights [1,8,6,2,5,4,8,3,7], the largest container you can form holds 49 units of water.

## Approach
Two Pointers:

Start with two pointers: one at the beginning of the array and one at the end.
Calculate the width of the container (distance between the two pointers) and the height (shorter of the two lines).
The area of water the container can hold is width × height. Keep track of the maximum area found.
Move Pointers:

Move the pointer that points to the shorter line. This is because the height of the container is limited by the shorter line. Moving the shorter line might help find a taller line and increase the container’s height.
Repeat until the pointers meet. The maximum area found during this process is the answer.

## Time Complexity
O(n): This means the time it takes to find the answer grows linearly with the number of heights in the array.

## Space Complexity
O(1): The extra space used is constant and doesn’t grow with the size of the input array.

######################################### C++ ##############################################3*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int maxWater = 0;
        while(i<j){
            int currWidth = j-i;
            int currHeight = min(height[i],height[j]);
            int currMaxWater = currWidth*currHeight;
            maxWater = max(maxWater,currMaxWater);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxWater;
    }
};
/*############################## video solution #################################33

url : https://youtu.be/KVU4JNNJkVg?si=CNsBKzXvm3kLc8W2

*/
