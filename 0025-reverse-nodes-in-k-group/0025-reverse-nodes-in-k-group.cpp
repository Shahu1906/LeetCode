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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int count = 0;
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* groupPrev = dummy;
        while (temp) {
            count++;
            if (count == k) {
                temp = temp->next;
                ListNode* start = curr;
                while (count != 0) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    count--;
                }
                groupPrev->next = prev;
                start->next = temp;
                groupPrev = start;
                prev = nullptr;
                curr = temp;
            } else {
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};