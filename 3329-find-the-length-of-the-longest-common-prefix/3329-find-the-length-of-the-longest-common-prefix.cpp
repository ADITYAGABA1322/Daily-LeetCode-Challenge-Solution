#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode* children[10];
    bool isEndOfWord;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    for (int i = 0; i < 10; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, string key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

int commonPrefixSearch(TrieNode* root, string key) {
    TrieNode* pCrawl = root;
    int length = 0;
    for (int level = 0; level < key.length(); level++) {
        int index = key[level] - '0';
        if (!pCrawl->children[index])
            return length;
        pCrawl = pCrawl->children[index];
        length++;
    }
    return length;
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getNode();
        for (int num : arr1) {
            insert(root, to_string(num));
        }
        int maxLength = 0;
        for (int num : arr2) {
            maxLength = max(maxLength, commonPrefixSearch(root, to_string(num)));
        }
        return maxLength;
    }
};