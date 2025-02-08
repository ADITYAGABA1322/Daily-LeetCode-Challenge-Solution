class NumberContainers {
public:
    unordered_map<int , set<int>> numtoIdx; //  Maps each number to a set of indices
    unordered_map<int , int> mp; // check or count map each index to their currno
    NumberContainers() {
    }
    
    void change(int index, int number) {
        // now in this method we need to use map check that if index is linked to number we use the nc and hcek forn the start what we get is theri are index or no to this we use set to sotre idx if no idx form the strating we return 0 2 if have sotre adn using map and set we eaily insert the no and followe the operation given  input 
        if(mp.find(index) != mp.end()){
            int oldNum= mp[index];
            numtoIdx[oldNum].erase(index);
            if(numtoIdx[oldNum].empty()){
                numtoIdx.erase(oldNum);
            }
        }
        mp[index] = number;
        numtoIdx[number].insert(index);
    }
    int find(int number) {
        if(numtoIdx.find(number) != numtoIdx.end() && !numtoIdx[number].empty() ){
            return *numtoIdx[number].begin();
        }   
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */