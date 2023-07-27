142. Linked List Cycle II





9 March 2023




Medium



C++:



// Time Complexity : O(n) where n is the number of nodes in the linked list and space complexity is O(1)





class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;  // slow pointer
        ListNode *fast = head;  // fast pointer
        while(fast != NULL && fast -> next != NULL){  // iterate until the fast pointer reaches the end
            slow = slow -> next;  // update the slow pointer
            fast = fast -> next -> next;  // update the fast pointer
            if(slow == fast){  // if the slow and fast pointers meet
                slow = head;  // update the slow pointer
                while(slow != fast){  // iterate until the slow and fast pointers meet
                    slow = slow -> next;  // update the slow pointer
                    fast = fast -> next;  // update the fast pointer
                }
                return slow;  // return the slow pointer
            }
        }
        return NULL;  // return NULL
    }
};


Java:




// Time Complexity : O(n) where n is the number of nodes in the linked list and space complexity is O(1)





class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;  // slow pointer
        ListNode fast = head;  // fast pointer
        while(fast != null && fast.next != null){  // iterate until the fast pointer reaches the end
            slow = slow.next;  // update the slow pointer
            fast = fast.next.next;  // update the fast pointer
            if(slow == fast){  // if the slow and fast pointers meet
                slow = head;  // update the slow pointer
                while(slow != fast){  // iterate until the slow and fast pointers meet
                    slow = slow.next;  // update the slow pointer
                    fast = fast.next;  // update the fast pointer
                }
                return slow;  // return the slow pointer
            }
        }
        return null;  // return null
    }
}


