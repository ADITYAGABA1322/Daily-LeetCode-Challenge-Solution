class Solution {
public:
    vector<int> partitionLabels(string s) {
        // we want to partition the string so each string coming at most once means only 1 time or not just do one thing use map or set we solve this one but how lets start we want to return size of that string  which is possible  and return their len just check the first their freq use 2 pointer for what just check that if that elel is present on that or not reutn the res with size of that all possible string ok 
        unordered_map<char , int> lastOccurence;
        for(int i=0; i<s.size(); i++) {
            lastOccurence[s[i]] = i;
        }
        vector<int> res;
        int start = 0 , end = 0;
        for(int i=0; i<s.size(); i++){
            end = max(end , lastOccurence[s[i]]);
            if(i == end){
                res.push_back(end-start+1);
                start = i+1;
            }
       
        }
        return res;
    }
};