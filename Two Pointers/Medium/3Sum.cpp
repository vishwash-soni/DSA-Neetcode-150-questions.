/*
## Approach
Sort the Array: Start by sorting the array to facilitate finding triplets efficiently and to handle duplicates easily.

Iterate with a Fixed Element: Iterate through the sorted array with a fixed element nums[i]. For each fixed element, use a two-pointer approach to find pairs that sum up to the negative of the fixed element (-nums[i]).

Two-Pointer Technique: For each fixed element, initialize two pointers: i + 1 (left) and n - 1 (right). Move these pointers towards each other based on the sum of the values at these pointers compared to the target value (-nums[i]):

If the sum of the values at the pointers is greater than the target, move the right pointer to the left.
If the sum is less than the target, move the left pointer to the right.
If the sum matches the target, add the triplet to the result, and move both pointers while skipping over duplicates.
Skip Duplicates: Ensure that no duplicate triplets are added by skipping over duplicate values for both the fixed element and the pair elements found by the two-pointer technique.

## Time Complexity
The time complexity is O(n^2), where n is the number of elements in the array. This is because:
Sorting the array takes O(n log n).
The two-pointer approach for each element involves scanning pairs, which takes O(n) time, resulting in a total of O(n^2).

## Space Complexity
The space complexity is O(1) if we disregard the space used by the output, as the algorithm uses only a constant amount of extra space for variables.

######################################## C++ ####################################################################
*/
class Solution {
public:
    void twoSum(vector<int>& nums,int target,int i , int j, vector<vector<int>>& result){
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                while( i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }

                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int n1 = nums[i];
            int target = -n1;

            twoSum(nums,target,i+1,n-1,result);
        }
        return result;
    }
};

/* ################### Video solution #####################################

URL : https://youtu.be/_cBWWebTVpI?si=3_QdFFYssJc5hmjr

*/
