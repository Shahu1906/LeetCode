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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int carry = 0;
        while (l1 || l2) {
            int x = 0;
            int y = 0;
            if (l1)
                x = l1->val;
            if (l2)
                y = l2->val;

            int z = x + y + carry;

            if (z >= 10) {
                carry = z / 10;
                int r = z % 10;
                ListNode* newNode = new ListNode(r);
                temp->next = newNode;
                temp = temp->next;
            } else {
                carry = 0;
                ListNode* newNode = new ListNode(z);
                temp->next = newNode;
                temp = temp->next;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return ans->next;
    }
};