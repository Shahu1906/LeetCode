class Solution {
public:

    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if (left)
            temp->next = left;
        else
            temp->next = right;

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {

        // 0 or 1 node is already sorted
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* mid = findMiddle(head);

        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeList(left, right);
    }
};