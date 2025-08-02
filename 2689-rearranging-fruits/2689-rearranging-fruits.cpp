class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // Yeah, after analyzing the problem, what the insights I got by the problem is looking for that there are two baskets we got it, but we do now we sold both baskets competitor operator just we are using it and another thing we are using the table or the map we can say, and we stored the frequency of the in the map now what we do, we want to use our greedy approaches, but how greedy like if I think about there are two people, and I want to distribute them equally like something like an example of Apple now how should I distribute them? That's a greedy approach like to optimize the solution by providing them equality of frequency we just rated and check it like each element have saved frequency or not same frequency if not, we swap it if yes, we return 0 or it impossible return minus one and done.
        map<int , int> cnt;
        for(auto x : basket1) cnt[x]++;
        for(auto x : basket2) cnt[x]--;
        vector<int> excess;
        for(auto[fruit , freq] : cnt){
            if(freq % 2) return -1;
            for(int i=0; i<abs(freq)/2; i++){
                excess.push_back(fruit);
            }
        }
        sort(excess.begin() , excess.end());
        int globalMin = min(*min_element(basket1.begin() , basket1.end()) , *min_element(basket2.begin() , basket2.end()));
        long long res = 0 , n = excess.size();
        for(int i=0; i<n/2; i++){
            res += min(excess[i] , 2*globalMin);
        }
        return res;
    }
};