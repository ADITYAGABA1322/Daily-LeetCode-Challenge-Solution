class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        int c = 0, curWord = 1;
        for (int i = 0; i < s.size(); ++i){
            if (c != -1 && s[i] == w[c]) ++c;
            else if (s[i] == ' ') c = 0, ++curWord;
            else c = -1;
            if (c == w.size()) return curWord;
        }
        return -1;
    }
};