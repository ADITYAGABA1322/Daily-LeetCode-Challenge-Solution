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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {-1 , -1};
        int minDis = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currIdx = 1 , prevCriticalIdx = 0 , firstCriticalIdx = 0;
        while(curr->next != NULL){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){
                if(prevCriticalIdx == 0){
                    prevCriticalIdx = currIdx;
                    firstCriticalIdx = currIdx;
                } else{
                    minDis = min(minDis , currIdx - prevCriticalIdx);
                    prevCriticalIdx = currIdx;
                }
            }
            currIdx++;
            prev = curr;
            curr = curr->next;
        }
        if(minDis != INT_MAX){
            int maxDis = prevCriticalIdx - firstCriticalIdx;
            res = {minDis , maxDis};
        }
        return res;
    }
};