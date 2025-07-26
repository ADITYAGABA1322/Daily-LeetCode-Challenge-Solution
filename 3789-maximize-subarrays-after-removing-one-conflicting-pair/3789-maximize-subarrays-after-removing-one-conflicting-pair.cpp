class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // In today's problem, what we do right now we go to remove the one conflicting pair taken an example. We removed the first pair only and rest of them pair. We need to calculate the ranges of how many pairs are possible maximum to the end size not and size it's a last number of N according to that number we want to create the number of different pairs in which pairs the conflicting pair of that remaining word does not go just a simple thing but I want to say like taking an N it rate through the end, create a number of pairs in the number of pairs just chec the pair of conflicting does not come and return. The number of count of pairs only just do one thing just remove the one pair of the conflicting pair first and then which I could it's done with it on the account but what is the approach? Should it possible in this? We want to check through the approach of like the two pointer approach or an just array approach but not its much omre about count and pairs acc to constrints we go with prefix or segment tree to  iterate the queries acc to no confilct pair hurts
//         long long maxCount = 0;
//         for(int remIdx =0; remIdx < conflictingPairs.size(); remIdx++){
//             vector<vector<int>> remP;
//             for(int i=0; i<conflictingPairs.size(); i++){
//                 if(i != remIdx) remP.push_back(conflictingPairs[i]);
//             }

//             long long count = validSub(n , remP);
//             maxCount = max(maxCount , count);
//         }
//         return maxCount;
//     }
// private:
//     long long validSub(int n , vector<vector<int>>& pairs){
//         long long totalCnt = 0;
//         for(int i=1; i<=n; i++){
//             for(int j=i; j<=n; j++){
//                 bool isValid = true;
//                 for(auto p : pairs){
//                     int a = p[0] , b = p[1];
//                     if(a>=i && a<=j && b>=i && b<=j){
//                         isValid = false;
//                         break;
//                     }
//                 }
//                 if(isValid) totalCnt++;
//             }
//         }
//         return totalCnt;

    // optimized
    vector<int> bMin1(n+1 , INT_MAX) ,bMin2(n+1 , INT_MAX);
    for(auto p : conflictingPairs){
        int a = min(p[0] , p[1]) , b = max(p[0] , p[1]);
        if(bMin1[a] > b){
            bMin2[a] = bMin1[a];
            bMin1[a] = b;
        } else if(bMin2[a] > b){
            bMin2[a] = b;
        }
    }
    long long res = 0;
    int ib1 = n , b2 = INT_MAX;
    vector<long long> delCnt(n+1 , 0);
    for(int i=n; i>=1; i--){
        if(bMin1[ib1] > bMin1[i]){
            b2 = min(b2 , bMin1[ib1]);
            ib1 = i;
        } else{
            b2 = min(b2 , bMin1[i]);
        }
        res+= min(bMin1[ib1] , n+1) - i;
        delCnt[ib1] +=
                min(min(b2, bMin2[ib1]), n + 1) - min(bMin1[ib1], n + 1);
    }
     return res + *max_element(delCnt.begin(), delCnt.end());
    }
};