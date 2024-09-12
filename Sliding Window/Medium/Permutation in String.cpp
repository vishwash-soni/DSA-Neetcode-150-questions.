/* ## LeetCode : 567. Permutation in String

## Time Complexity
  - O(n): The code iterates through the string s2 once and performs operations for each character. Since the sliding window approach processes each character in constant time, the overall time complexity is linear with respect to the length of s2.
## Space Complexity
- O(1): The space complexity is constant because the space used for the frequency vectors map1 and map2 is fixed at 26 integers each (for the 26 letters of the alphabet), regardless of the size of the input strings.

######################################## c++ ################################################################ */

class Solution {
public:
    bool check(vector<int>map1,vector<int>map2){
        for(int i=0;i<26;i++){
            if(map1[i]!=map2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(n<m){
            return false;
        }
        vector<int>map1(26);
        vector<int>map2(26);
        
        for(int i=0;i<m;i++){
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }
        if(check(map1,map2)){
            return true;
        }

        for(int i=m;i<n;i++){
            map2[s2[i-m]-'a']--;
            map2[s2[i]-'a']++;
            if(check(map1,map2)){
            return true;
            }
        }
        return false;
    }
};

/* ################################### video solution ###################################################################

url: https://youtu.be/Z1DEoE4Mfmc?si=SXqGjokrkh7Ts1Ji

*/
