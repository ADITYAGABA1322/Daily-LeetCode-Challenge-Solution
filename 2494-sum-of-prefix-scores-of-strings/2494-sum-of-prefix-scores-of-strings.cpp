struct TrieNode{
    TrieNode *children[26];
    int count = 0;
    TrieNode(){
        count = 0;
        for(int i=0; i<26; i++) children[i] = NULL;
    }
};

void insert(TrieNode *root , string &key){
    TrieNode* pcrawl = root;
    for(auto ch : key){
        int index = ch - 'a';
        if(!pcrawl->children[index]){
            pcrawl->children [index] = new  TrieNode();
        }
        pcrawl = pcrawl->children[index];
        pcrawl->count++;
    }
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        TrieNode *root = new TrieNode();
        for(auto word : words){
            insert(root , word);
        }      
        for(auto word : words){
            TrieNode* pcrawl = root;
            int sum = 0;
            for(auto ch : word){
                int index = ch - 'a';
                pcrawl = pcrawl->children[index];
                sum += pcrawl->count;
            }
            res.push_back(sum);
        }
        return res;
    }
};