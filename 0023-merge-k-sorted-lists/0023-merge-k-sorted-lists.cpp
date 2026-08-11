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
    ListNode* merge(ListNode* L1, ListNode* L2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(L1 && L2){
            if(L1->val <= L2->val){
                temp->next = L1;
                L1 = L1->next;
            }else{
                temp->next = L2;
                L2 = L2->next;
            }
            temp = temp->next;
        }
        if(L1)
          temp->next = L1;
        else
          temp->next = L2;

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* Merged = nullptr;
        for(int i = 0; i < lists.size(); i++){
            ListNode* L2 = lists[i];
            Merged = merge(Merged,L2);
        }
        return Merged;
    }
};