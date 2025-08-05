class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size() , m = baskets.size() , unPlaced = 0;
        vector<bool> used(m , false);
        for(int i=0; i<n; i++){
            bool isPlaced = false;
            for(int j=0; j<m; j++){
                if(!used[j] && baskets[j] >= fruits[i]){
                    used[j] = true;
                    isPlaced = true;
                    break;
                }
            }
            if(!isPlaced) unPlaced++;
        }
        return unPlaced;
    }
};