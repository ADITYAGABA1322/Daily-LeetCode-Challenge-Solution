class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n , 0);
        int op = 0 , balls = 0;
        for(int i=0; i<n; i++){
            res[i] += op;
            if(boxes[i] == '1') balls++;
            op += balls;
        }
        balls = 0 , op = 0;
        for(int i=n-1; i>=0; i--){
            res[i] += op;
            if(boxes[i] == '1') balls++;
            op += balls;
        }
        return res;
    }
};