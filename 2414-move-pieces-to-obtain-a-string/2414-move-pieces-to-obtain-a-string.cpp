class Solution {
public:
    bool canChange(string start, string target) {
        /// again 2 pointer apporach works here what they ask for  takeing l and irght pointer and we need to acheive tget by foolow the rule simple if not make target return aflse then true
//         You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

// The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
// The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.

        int n = start.size() , i = 0 , j = 0;
        while(i<n && j<n){
            while(i<n && start[i] == '_') {i++;}
            while(j<n && target[j] == '_') {j++;}
            if(i == n && j == n) break;
            if(i == n || j == n) return false;
            if(start[i] != target[j]) return false;
            if(start[i] == 'L' && i <j) return false;
            if(start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }
        while(i<n){
            if(start[i] != '_') return false;
            i++;
        }
        while(j<n){
            if(target[j] != '_') return false;
            j++;
        }
        return true;
    }
};