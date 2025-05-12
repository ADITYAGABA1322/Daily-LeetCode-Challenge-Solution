class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        for(int i=0; i<n; i++){
            if(digits[i] == 0) continue;
            for(int j=0; j<n; j++){
                if(j == i) continue;
                for(int k=0; k<n; k++){
                    if(k == i || k == j) continue;
                    if(digits[k] % 2 == 0){
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        st.insert(num);
                    }
                }
            }
        }
        vector<int> res(st.begin() , st.end());
        return res;
    }
};