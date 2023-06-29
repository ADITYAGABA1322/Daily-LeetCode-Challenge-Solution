# Daily-LeetCode-Challenge-Solution



131. Palindrome Partitioning

22 Jan 2023

Medium


C++:

// Time Complexity : O(2^n) where n is the length of the string and space complexity is O(n)

class Solution {
public:
    vector<vector<string>> partition(string s) {  // function to partition the string into palindrome partitions
        vector<vector<string>> ans;  // ans is the vector to store the palindrome partitions
        partition(s , ans , 0 , {});  // function call to partition the string into palindrome partitio
        return ans;  // return the vector of palindrome partitions
    }
    void partition(string s , vector<vector<string>>& ans , int index , vector<string> temp){  // function to partition the string into palindrome partitions
        if(index == s.length()){  // if the index is equal to the length of the string
            ans.push_back(temp);  // push the current palindrome partition into the vector of palindrome partitions
            return;  // return
        }
        for(int i=index; i<s.length(); i++){  // for each length of the substring
            if(isPalindrome(s , index , i)){  // if the substring is a palindrome
                temp.push_back(s.substr(index , i-index+1));  // push the substring into the current palindrome partition
                partition(s , ans , i+1 , temp);  // function call to partition the string into palindrome partitions
                temp.pop_back();  // pop the last element from the current palindrome partition
            }
        }
    }
    bool isPalindrome(string s , int start , int end){  // function to check if the substring is a palindrome
        while(start < end){  // while the start is less than the end
            if(s[start] != s[end]){  // if the characters at the start and end are not equal
                return false;  // return false
            }
            start++;  // increment the start
            end--;  // decrement the end
        }
        return true;  // return true
    }
};




Java:

// Time Complexity : O(2^n) where n is the length of the string and space complexity is O(n)

class Solution {
    public List<List<String>> partition(String s) {  // function to partition the string into palindrome partitions
        List<List<String>> ans = new ArrayList<>();  // ans is the list to store the palindrome partitions
        partition(s , ans , 0 , new ArrayList<>());  // function call to partition the string into palindrome partitions
        return ans;  // return the list of palindrome partitions
    }
    void partition(String s , List<List<String>> ans , int index , List<String> temp){  // function to partition the string into palindrome partitions
        if(index == s.length()){  // if the index is equal to the length of the string
            ans.add(new ArrayList<>(temp));  // add the current palindrome partition into the list of palindrome partitions
            return;  // return
        }
        for(int i=index; i<s.length(); i++){  // for each length of the substring
            if(isPalindrome(s , index , i)){  // if the substring is a palindrome
                temp.add(s.substring(index , i+1));  // add the substring into the current palindrome partition
                partition(s , ans , i+1 , temp);  // function call to partition the string into palindrome partitions
                temp.remove(temp.size()-1);  // remove the last element from the current palindrome partition
            }
        }
    }
    boolean isPalindrome(String s , int start , int end){  // function to check if the substring is a palindrome
        while(start < end){  // while the start is less than the end
            if(s.charAt(start) != s.charAt(end)){  // if the characters at the start and end are not equal
                return false;  // return false
            }
            start++;  // increment the start
            end--;  // decrement the end
        }
        return true;  // return true
    }
}


