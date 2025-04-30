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
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                dummy->next = l1;
                l1 = l1->next;
                dummy = dummy->next;
            }
            else {
                dummy->next = l2;
                l2 = l2->next;
                dummy = dummy->next;
            }
        }
        while(l1) {
            dummy->next = l1;
            l1 = l1->next;
            dummy = dummy->next;
        }
        while(l2) {
            dummy->next = l2;
            l2 = l2->next;
            dummy = dummy->next;
        }
        return temp->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            if(!lists[i]) continue;
            head = merge(head, lists[i]);
        }
        return head;
    }
};