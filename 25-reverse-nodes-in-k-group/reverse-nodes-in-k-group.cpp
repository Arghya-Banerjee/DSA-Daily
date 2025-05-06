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
    ListNode* getKthNode(ListNode* head, int k) {
        while(--k && head) head = head->next;
        return head;
    }

    ListNode* revLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            ListNode* kthNode = getKthNode(temp, k);
            if (!kthNode) {
                if (prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = revLL(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prev->next = newHead;
            }

            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};
