class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size() , m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0 , right = min(n , m);
        while(left <= right){
            int mid = left + (right - left)/2;
            if(canAssign(tasks , workers , pills , strength , mid)){
                left = mid+1;
            } else{
                right = mid - 1;
            }
        }
        return right;
    }
    private:
        bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength , int k){
            // k is sub taks from the left side acc to mid above ok 
            vector<int> subTask(tasks.begin() , tasks.begin() + k);
            vector<int> subWorkers(workers.end() - k , workers.end());
            multiset<int> mt(subWorkers.begin() , subWorkers.end());
            int leftPills = pills;
            for(int i=k-1; i>=0; i--){
                int task = subTask[i];
                auto it = mt.lower_bound(task);
                if(it != mt.end()) mt.erase(it);
                else if(leftPills > 0){
                    auto it = mt.lower_bound(task-strength);
                    if(it != mt.end()){
                        leftPills--;
                        mt.erase(it);
                    } else{
                        return false;
                    }
                }
                else return false;
            }
            return true;
        }
};