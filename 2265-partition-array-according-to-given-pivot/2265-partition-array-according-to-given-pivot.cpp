class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // we want to do one thing like we want to first check pivot in array if we got that ele ok next we maintan two check left and right  and we maintain an ele we get that and then acc to povot we maintin a pointer on  left and right and just check only left side is smallest of pivot and right side greater and the problem is not  complete we just want to swap the pos like we get big on left we want  and on right  samll we just swap their pos so that actual array is return in res ok
        vector<int> res , less , equal , greater;
        for(auto num : nums){
            if(num < pivot){
                less.push_back(num);
            }
            else if(num == pivot){
                equal.push_back(num);
            }
            else{
                greater.push_back(num);
            }
        }
        res.insert(res.end() , less.begin() , less.end());
        res.insert(res.end() , equal.begin() , equal.end());
        res.insert(res.end() , greater.begin() , greater.end());
        return res;
    }
};