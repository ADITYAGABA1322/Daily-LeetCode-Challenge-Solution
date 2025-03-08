class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //acc to question k we need to check that in we need to check len of str ok k and then in that we nned return min op to convert W to B string ok simple 
        int n = blocks.size();
        int  whiteCount = 0;
        for(int i=0; i<k; i++){
            if(blocks[i] == 'W') whiteCount++;
        }
        int minOp = whiteCount;
        for(int i=k; i<n; i++){
            if(blocks[i-k] == 'W') whiteCount--;
            if(blocks[i] == 'W')whiteCount++;
            minOp = min(minOp , whiteCount);
        }
        return minOp;
    }
};