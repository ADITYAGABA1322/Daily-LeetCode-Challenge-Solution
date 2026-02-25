class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [](int a , int b){
          int count1 = __builtin_popcount(a);
          int count2 = __builtin_popcount(b);
          if(count1<count2) return true;
          else if(count1>count2) return false;
          else return a<b;
        };
        sort(arr.begin() ,arr.end() , comp);
        return arr;
    }
};