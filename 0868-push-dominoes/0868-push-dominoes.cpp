class Solution {
public:
    string pushDominoes(string dominoes) {
        // ok we just need to see the . find that and check one thing is . comes to l or r and check L>R then L and if R > L then R  ok lets take 2nd example dominoes = ".L.R...LR..L.."  means that first , . comes to L in left sode ok seems LL then 2nd dot comes to b/w L and R since R has another dot also so that meces R and then do cmes to left L that becomes L and R becomes R and then . dot becomes L and L and then 2 dots becuse there are no R in end side ok so we return that "LL.RR.LLRRLL.." 
        // approach we nned to use 2 pointer for left and right and check the dot ewhen it comes we check the proficiency the dot comes to L or R and then we  replace that char of string to L or R nad we retuurn final string ans 
        string res = dominoes;
        int n = dominoes.size();
        vector<int> forces(n , 0);
        int force = 0;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R') force = n;
            else if(dominoes[i] == 'L') force = 0;
            else force = max(force-1 , 0);
            forces[i] += force;
        }
        force = 0;
          for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L') force = n;
            else if(dominoes[i] == 'R') force = 0;
            else force = max(force-1 , 0);
            forces[i] -= force;
        }

        for(int i=0; i<n; i++){
            if(forces[i] > 0) res[i] = 'R';
            else if(forces[i] < 0) res[i] = 'L';
            else forces[i] = res[i];
        }
        return res;
    }
};