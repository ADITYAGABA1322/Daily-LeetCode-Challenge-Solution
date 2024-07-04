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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(0); // Create a dummy node to simplify operations
        ListNode* tail = &dummy; // Tail will be used to build the new list
        int sum = 0; // Initialize sum to 0

        // Start from head->next because the first node is a dummy 0 node as per problem statement
        for (ListNode* curr = head->next; curr != nullptr; curr = curr->next) {
            if (curr->val != 0) {
                // Accumulate sum if current node is not 0
                sum += curr->val;
            } else {
                // If current node is 0, it means we need to finish the current segment
                // Create a new node with the accumulated sum and reset sum to 0
                tail->next = new ListNode(sum);
                tail = tail->next; // Move the tail to the last node
                sum = 0; // Reset sum for the next segment
            }
        }

        return dummy.next; // Return the next of dummy node which is the head of the new list
    }
};