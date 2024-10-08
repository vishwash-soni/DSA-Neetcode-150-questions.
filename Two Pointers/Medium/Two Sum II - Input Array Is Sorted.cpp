/* Leetcode : 167. Two Sum II - Input Array Is Sorted

##Time Complexity: O(n) where n is the number of elements in the array. The two-pointer technique allows us to scan the array in linear time.

##Space Complexity: O(1) since the solution only uses a fixed amount of additional space, regardless of the input size.

############################ C++ ########################################### */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j = numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
            if(numbers[i]+numbers[j]<target){
                i++;
            }
            if(numbers[i]+numbers[j]>target){
                j--;
            }
        }
        return {-1,-1};
    }
};
