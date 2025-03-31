class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size(); 
        if(k == 1 ||  k == n) return 0;
        vector<int> pairSum;
        for(int i=0; i<n-1; i++) pairSum.push_back(weights[i] + weights[i+1]);
        // we want to go with min heap ro max heap 
        // we intialize pq but in wrong way their no need of pair as clealy seen from the question now waht we do now just change pq and use the for llop first to iterate and push in pq and while loop check pq not empty ok. acc to give we split the arr in k  in pq ok  we want to use max_sum and min_sum two int and and int diff for res ok for max an min we use pq heap ok. 

        // priority_queue<int , vector<int> , greater<int>> minH(pairSum.begin() , pairSum.end());
        // priority_queue<int> maxH(pairSum.begin(), pairSum.end());
        // long long minScore = 0 , maxScore = 0;
        // for(int i=0; i<k-1; i++){
        //     minScore += minH.top();
        //     minH.pop();
        // }
        // cout<<minScore<<endl;
        // for(int i=0; i<k-1; i++){
        //     maxScore += maxH.top();
        //     maxH.pop();
        // }
        // cout<<maxScore;
        // return maxScore - minScore;

        // greedy 
        sort(pairSum.begin() , pairSum.end());
        long long maxScore = 0 , minScore = 0;
        for(int i=0; i<k-1; i++){
            minScore += pairSum[i];
            maxScore += pairSum[pairSum.size() - 1 - i];
        }
        return maxScore - minScore;
    }
};