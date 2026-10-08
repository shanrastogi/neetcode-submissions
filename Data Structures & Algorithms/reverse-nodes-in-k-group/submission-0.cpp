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
    void reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }
    ListNode* getKthNode(ListNode* temp, int k) {
        k = k - 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while (temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if (temp == head) {
                head = kthNode;
            } else {
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
