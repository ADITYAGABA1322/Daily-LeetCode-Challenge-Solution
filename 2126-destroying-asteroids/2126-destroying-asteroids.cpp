class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end());
        for(auto m : asteroids){
            if(mass < m) return false;
            else if(mass >= 1e5) return true;
            mass += m;
        }
        return true;
    }
};