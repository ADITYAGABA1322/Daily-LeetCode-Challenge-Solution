class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string , int> businessLineSort = {
            {"electronics" , 0},
            {"grocery" , 1},
            {"pharmacy" , 2},
            {"restaurant" , 3}
        };

        vector<pair<pair<int , string> , string>> sortableCoupons;
        for(int i=0; i<n; i++){
            if(!isActive[i]) continue;
            if(businessLineSort.find(businessLine[i]) == businessLineSort.end()) continue;
            if(code[i].empty()) continue;
            bool isCodeValid = true;
            for(auto c: code[i]){
                if(!(isalnum(c) || c == '_')){
                    isCodeValid = false;
                    break;
                }
            }
            if(!isCodeValid) continue;
            int sortIndex = businessLineSort[businessLine[i]];
            sortableCoupons.push_back({{sortIndex , code[i]} , code[i]});
        }
        sort(sortableCoupons.begin(), sortableCoupons.end());
        vector<string> sortedValues;
        for(auto it: sortableCoupons){
            sortedValues.push_back(it.second);
        }
        return sortedValues;
    }
};