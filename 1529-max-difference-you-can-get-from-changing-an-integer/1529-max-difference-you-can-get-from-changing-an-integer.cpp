class Solution {
public:
    int maxDiff(int num) {
        // we need to calculate the max diff  from changing an Integer but how of i go through example if we take an sample by yourself u see that how shoudl i get max diff by just now take max digit 9 and small is 1 put in a and b and get diff easily 8 but if i try to solve this i think we need to first moeve to string and declare more varobale to check large no to change and small acc to change that no and put inot 2 variables a and b 
        string numStr = to_string(num);
        string aStr = numStr;
        char digitToReplace = '0';
        for(auto c: aStr){
            if(c != '9'){
                digitToReplace = c;
                break;
            }
        }
        for(int i=0; i<aStr.size(); i++){
            if(aStr[i] ==  digitToReplace){
                aStr[i] = '9';
            } 
        }
        string bStr = numStr;
        digitToReplace = '0';
        char replacement = '0';
        if(numStr[0] != '1'){
            digitToReplace = numStr[0];
            replacement = '1';
        } else{
            bool found = false;
            for(int i=0; i<numStr.size(); i++){
                if(numStr[i] != '0' && numStr[i] != '1'){
                    digitToReplace = numStr[i];
                    found = true;
                    break;
                }
            }
        }
        for(int i=0; i<bStr.size(); i++){
            if(bStr[i] ==  digitToReplace) bStr[i] = replacement;
        }
        int a = stoi(aStr) , b = stoi(bStr);
        return a-b;
    }
};