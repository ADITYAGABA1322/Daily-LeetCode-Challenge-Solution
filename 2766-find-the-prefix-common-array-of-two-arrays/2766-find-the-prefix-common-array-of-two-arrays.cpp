class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size() , cnt = 0;
        vector<int> f(n+1 , 0) , res(n);
        for(int i=0; i<n; i++){
            f[A[i]]++;
            if(f[A[i]] == 2) cnt++;
            f[B[i]]++;
            if(f[B[i]] == 2) cnt++;
            res[i] = cnt;
        }
        return res;
    }
};