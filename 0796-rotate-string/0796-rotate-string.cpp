class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size() , m = goal.size();
        if(n != m) return false;
        string doubled = s + s;
        return doubled.find(goal) < doubled.size();
    }
};