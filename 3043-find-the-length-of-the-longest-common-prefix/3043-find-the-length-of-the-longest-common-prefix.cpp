// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int n = arr1.size();
//         unordered_set<int> st;
//         for(auto val : arr1){
//             while(!st.contains(val) && val > 0){
//                 st.insert(val);
//                 val /= 10;
//             }
//         }

//         int res = 0;
//         for(auto num : arr2){
//             while(!st.contains(num) && num > 0){
//                 num  /= 10;
//             }
//             if(num > 0) res = max(res , static_cast<int>(log10(num) + 1));
//         }
//         return res;
//     }
// };

struct TrieNode{
    char digit;
    TrieNode* children[10];
};
class Solution {
public:
    TrieNode* getTrieNode(){
        TrieNode* node = new TrieNode();
        for(int i=0; i<10; i++){
            node->children[i] = NULL;
        }
        return node;
    }
    void insert(int num , TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);
        for(auto c : numStr){
            int idx = c-'0';
            if(!crawl->children[idx]){
                crawl->children[idx] = getTrieNode();
            }
            crawl = crawl->children[idx];
        }
    }
    int search(int num , TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);
        int len = 0;
        for(auto c: numStr){
            int idx = c - '0';
            if(crawl->children[idx]){
                len++;
                crawl = crawl->children[idx];
            } else{
                break;
            }
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode();
        for(auto num : arr1){
            insert(num , root);
        }
        int res = 0;
        for(auto num : arr2){
            res = max(res , search(num , root));
        }
        return res;
    }
};