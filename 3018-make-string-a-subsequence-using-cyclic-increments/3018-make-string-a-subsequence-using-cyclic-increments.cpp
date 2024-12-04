class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // simple using 2 pointer approach first take 26 char in string or in
        // vector like and we need to make str1 like str2 becomes subsequence ok
        // but first we need to check that we make a  to b or b to c and z to a
        // means  cyclic thing now come to apporach first start with 26 char
        // arrays a to z and z to a ok and we. take 2 pointers here one is chekc
        // str1 and 2nd one is str2 ok like i or j and we iterate the  str1 and
        // str2 and theirs is a base condition first bro like str2.size() >
        // str1.size()   retirn false and tkae over the pointer and chekc if we
        // make it to likesubseq of str2 in str1 just take cyclic operation and
        // we done it
        if (str2.size() > str1.size())
            return false;
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j] ||
                (str1[i] + 1 - 'a') % 26 + 'a' == str2[j]) {
                j++;
            }
            i++;
        }
        return j == str2.size();
    }
};