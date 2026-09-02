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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // keepa laggin node;
        auto* dummy = new ListNode(0, head);

        auto* slow = dummy;
        auto* fast = dummy;

        // Create a gap of n nodes
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return dummy->next;
        
    }
};
