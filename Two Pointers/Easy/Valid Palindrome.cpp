## LeetCode Problem 125: Valid Palindrome

-Problem Statement
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

## Approach
  
- Remove Non-Alphanumeric Characters: The remove function iterates through the string and constructs a new string containing only alphanumeric characters (i.e., lowercase and uppercase letters, and digits).
  
- Convert to Lowercase: The small function converts all uppercase letters in the string to lowercase.
  
- Check Palindrome: The check function compares characters from the start and end of the string, moving towards the center. If any characters don't match, the string is not a palindrome.
Combine Steps: The isPalindrome function combines the above steps: it first removes non-alphanumeric characters, converts the string to lowercase, and then checks if the resulting string is a palindrome.


Solution Code:
################################### C++ #######################################################

class Solution {
public:
    string remove(string s) {
        string temp = "";
        for (auto x : s) {
            if (x >= 'a' && x <= 'z') {
                temp += x;
            }
            if (x >= 'A' && x <= 'Z') {
                temp += x;
            }
            if (x >= '0' && x <= '9') {
                temp += x;
            }
        }
        return temp;
    }
    
    string small(string s) {
        string temp = "";
        for (auto x : s) {
            if (x >= 'A' && x <= 'Z') {
                temp += x - 'A' + 'a';
            } else {
                temp += x;
            }
        }
        return temp;
    }
    
    bool check(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        string temp = remove(s);
        temp = small(temp);
        bool ans = check(temp);

        return ans;
    }
};


## Time Complexity

- Removing Non-Alphanumeric Characters: O(n), where n is the length of the string s. This is because we iterate through the string once.
- Converting to Lowercase: O(n), since we iterate through the string again.
- Checking Palindrome: O(n), as we compare characters from both ends of the string until we reach the middle.
Overall time complexity: O(n).

## Space Complexity

- Removing Non-Alphanumeric Characters: O(n) for the new string that stores the filtered characters.
- Converting to Lowercase: O(n) for the new string in which we store the converted lowercase characters.
- Checking Palindrome: O(1) for the space used during comparison.
Overall space complexity: O(n).

