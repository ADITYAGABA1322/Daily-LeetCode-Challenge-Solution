/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr = head;
        int n = 0;
        while(curr){
            curr = curr->next;
            n++;
        }
        int w = n/k , r = n%k;
        vector<ListNode*> ans(k);
        curr = head;
        for(int i=0; i<k; i++){
            ListNode *root = curr;
           for(int j = 0; j<w+(i<r?1:0)-1; j++){
               if(curr) curr = curr->next;
           }
           if(curr){
               ListNode* prev = curr;
               curr = curr->next;
               prev->next = NULL;
           }
           ans[i] = root;
        }
        return ans;
    }
};