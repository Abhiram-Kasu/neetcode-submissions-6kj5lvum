class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        })
        > heap{};

        for (auto* head : lists) {
            if (head) {
                heap.push(head);
            }
        }

        ListNode dummy;
        auto* tail = &dummy;

        while (not heap.empty()) {
            auto* node = heap.top();
            heap.pop();

            if (node->next) {
                heap.push(node->next);
            }

            tail->next = node;
            tail = node;
        }

        tail->next = nullptr;
        return dummy.next;
    }
};