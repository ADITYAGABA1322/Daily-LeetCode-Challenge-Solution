class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // given arr nums distinct postive int return tuples a b c d a * b = c * d a, b, c  and d a != b != c != d. ok  we find a*b and c8d equal ok and smae suze of arr cnt we return it means  we make unique paris ok i am right shoudlwe use set here or map means ordered amesn we need to find uniq an dhwat we do we tkse a pair and check st.find() == st.end() and which is unique ok and 2nd one is we using hahstable and counting as u know we do in using map or set we eaily solve problme but how we decleare amp or set and pair to check that make unique pair and check they are equal
        int res = 0 , n = nums.size();
        unordered_map<int , int> mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int prod = nums[i] * nums[j];
                if(mp.find(prod) != mp.end()){
                    res += mp[prod];
                }
                mp[prod]++;
            }
        }
        return res*8;
    }
};