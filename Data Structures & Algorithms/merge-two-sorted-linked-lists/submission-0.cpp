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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* sorting;
        ListNode* new_head;
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        if(head1->val <= head2->val){
            sorting = head1;
            head1 = head1->next;
        } else {
            sorting = head2;
            head2 = head2->next;
        }
        new_head = sorting;
        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                sorting->next = head1;
                head1 = head1->next;
            } else {
                sorting->next = head2;
                head2 = head2->next;                
            }
            sorting = sorting->next;   
        }
        while(head1 != NULL){
            sorting->next = head1;
            head1 = head1->next;
            sorting = sorting->next;
        }
        while(head2 != NULL){
            sorting->next = head2;
            head2 = head2->next;
            sorting = sorting->next;
        }
        return new_head;
    }
};
