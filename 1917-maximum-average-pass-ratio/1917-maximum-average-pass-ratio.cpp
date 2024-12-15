class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto potInc = [](int pass , int total){
            return (double)(pass+1) / (total+1) - (double) pass / total;
        };
        priority_queue<pair<double , pair<int , int>>> pq;
        for(auto c : classes){
            int pass  = c[0] , total = c[1];
            pq.push({potInc(pass , total) , {pass , total}});
        }
        for(int i=0 ; i<extraStudents; i++){
            auto [inc , cls] = pq.top();
            pq.pop();
            int pass = cls.first , total = cls.second;
            pass++;
            total++;
            pq.push({potInc(pass , total) , {pass , total}});
        }

        double avg = 0.0;
        while(!pq.empty()){
            auto[inc , cls] = pq.top();
            pq.pop();
             int pass = cls.first , total = cls.second;
            avg += (double) pass / total;
        }
        return avg/classes.size();
    }
};