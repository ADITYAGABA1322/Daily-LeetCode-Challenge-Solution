class Solution {
public:
    struct TrieNode {
        int idx;
        int children[26];

        TrieNode(int i) {
            idx = i;
            for (int j = 0; j < 26; j++) {
                children[j] = -1;
            }
        }
    };

    vector<TrieNode> trie;

    bool better(int currentIdx, int newIdx, vector<string>& wordsContainer) {
        if (wordsContainer[newIdx].size() < wordsContainer[currentIdx].size()) {
            return true;
        }

        if (wordsContainer[newIdx].size() == wordsContainer[currentIdx].size() &&
            newIdx < currentIdx) {
            return true;
        }

        return false;
    }

    void insert(int root, int i, vector<string>& wordsContainer) {
        const string& word = wordsContainer[i];
        int node = root;

        if (better(trie[node].idx, i, wordsContainer)) {
            trie[node].idx = i;
        }

        for (int j = word.size() - 1; j >= 0; j--) {
            int ch_idx = word[j] - 'a';

            if (trie[node].children[ch_idx] == -1) {
                trie[node].children[ch_idx] = trie.size();
                trie.push_back(TrieNode(i));
            }

            node = trie[node].children[ch_idx];

            if (better(trie[node].idx, i, wordsContainer)) {
                trie[node].idx = i;
            }
        }
    }

    int search(int root, const string& word) {
        int node = root;
        int res_idx = trie[node].idx;

        for (int i = word.size() - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';

            if (trie[node].children[ch_idx] == -1) {
                return res_idx;
            }

            node = trie[node].children[ch_idx];
            res_idx = trie[node].idx;
        }

        return res_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> res(n);

        trie.clear();
        trie.push_back(TrieNode(0));

        for (int i = 0; i < m; i++) {
            insert(0, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            res[i] = search(0, wordsQuery[i]);
        }

        return res;
    }
};