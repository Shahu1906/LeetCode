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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        if (head == nullptr)
            return vector<ListNode*>(k, nullptr);
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            temp = temp->next;
            length++;
        }
        int base = length / k;
        int extra = length % k;
        vector<int> pec(k);
        for (int i = 0; i < k; i++) {
            pec[i] = base;
            if (i < extra)
                pec[i]++;
        }
        temp = head;
        vector<ListNode*> res;
        for (int i = 0; i < pec.size(); i++) {
            if(pec[i]==0){
                res.push_back(nullptr);
                continue;
            }
            ListNode* headpart = temp;
            for(int j = 1; j < pec[i]; j++)
               temp = temp->next;
            ListNode* nextpart = temp->next;
            temp->next = nullptr;
            res.push_back(headpart);
            temp = nextpart;
        }
        return res;
    }
};