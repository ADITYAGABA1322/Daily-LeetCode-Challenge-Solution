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
    int pairSum(ListNode* head) {
        ListNode* curr = head;
        vector<int> res;
        while(curr != NULL){
            res.push_back(curr->val);
            curr = curr->next;
        }
        int i = 0 , j = res.size() - 1 , ans;
        while(i<j){
            ans = max(ans , res[i] + res[j]);
            i++;
            j--;
        }
        return ans;
    }
};