class Solution {
public:
    string smallestSubsequence(string s) {
        int lastIndex[26] = {0};
        bool inStack[26] = {false};
        stack<char> st;

        for(int i = 0; i < s.size(); i++) lastIndex[s[i] - 'a'] = i;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if (inStack[ch - 'a']) continue;
            while(!st.empty() && st.top() > ch && lastIndex[st.top() - 'a'] > i){
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};