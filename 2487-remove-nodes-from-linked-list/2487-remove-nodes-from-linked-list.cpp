class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int maxx = head->val;
        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->val < maxx) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
                maxx = temp->val;
            }
        }
        return reverse(head);
    }
};