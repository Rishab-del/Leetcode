class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* first = NULL;
        ListNode* last = NULL;
        int n = 0;
        //length and kth node from start
        while (temp != NULL) {
            n++;
            if (n == k) {
                first = temp;
            }
            temp = temp->next;
        }

        // kth node from end
        temp = head;
        int pos = n - k + 1;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        last = temp;
        // Swap values
        swap(first->val, last->val);
        return head;
    }
};