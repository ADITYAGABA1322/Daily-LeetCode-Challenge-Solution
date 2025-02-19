class Solution {
public:
    string getHappyString(int n, int k) {
        // find happy string consist a  b  c and s[i] != s[i+1] i to 1 , "abc" , "ac" , "b" , "abcbabcbcb" waht we do we need to find waht is give na nd k acc to that we need to dfind thoose elel means we nned to make pairs acc to given n and k if the pair we check is leass than k no then return empty ok and we nned to use these ele a b and c ok. we go with backtrack using vector or set and we return string of ans and in which we create check pair means all pssibilities first acc to given n and k means n size string and k means that no of pairs exist or not and we make that pair and. check lexo order string and reutn in ans and in between we nned to check this condition first s[i] != s[i+1]  ok we need to do this
        string res;
        int cnt = 0;

        function<void(string)> backtrack = [&](string curr){
            if(curr.size() == n){
                cnt++;
                if(cnt == k){
                    res = curr;
                }
                 return;
            }
            for(auto c : {'a' ,'b' , 'c'}){
                if(curr.empty() || curr.back() != c){
                    backtrack(curr + c);
                    if(!res.empty()) return;
                }
            }
        };
        backtrack("");
        return res;
    }
};