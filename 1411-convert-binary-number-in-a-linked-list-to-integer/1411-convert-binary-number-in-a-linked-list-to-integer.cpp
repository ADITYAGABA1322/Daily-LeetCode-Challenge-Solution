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
    int getDecimalValue(ListNode* head) {
        string binaryStr;
        ListNode* curr = head;
        while(curr != NULL){
            binaryStr += to_string(curr->val);
            curr = curr->next;
        }
        return stoi(binaryStr , nullptr, 2);
    }
};