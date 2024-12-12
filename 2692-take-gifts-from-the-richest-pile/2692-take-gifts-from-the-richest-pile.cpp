class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin() , gifts.end());
        for(int i=0; i<k; i++){
            int maxEle = pq.top();
            pq.pop();
            int sqEle = sqrt(maxEle);
            pq.push(sqEle);
        }
        long long res = 0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};