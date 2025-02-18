class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        int cnt = 1;
        string res;
        stack<int> st;
        for(int i=0; i<=n; i++){
            st.push(cnt++);
            if(i == n ||  pattern[i] == 'I'){
                while(!st.empty()){
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};