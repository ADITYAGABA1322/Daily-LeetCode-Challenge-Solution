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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // spiral matrix we top bottom left right this is main for us this wil; help to genrate the spiral matrix ok and now we think about like how shoudl we genrate we are m and n means size of matrix 
        // approach ->. create a 2d matrix of this size m and n size ok 
        //  now the game is sim-lpe take top and left. =0. and bototm - m-1 and right = n-1 if head == 0 return null and thn using 2 while lopops for this the concept reamin simple like in spiral matrix ok 
        vector<vector<int>> matrix(m , vector<int>(n , -1));
        int top = 0 , bottom = m-1 , left = 0 , right = n-1;
        while(head != NULL){
            for(int i=left; i<=right && head != NULL; i++){
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++;
            for(int i=top; i<=bottom && head != NULL; i++){
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;
            for(int i=right; i>=left && head != NULL; i--){
                matrix[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            for(int i=bottom; i>=top && head != NULL; i--){
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        return matrix;
    }
};