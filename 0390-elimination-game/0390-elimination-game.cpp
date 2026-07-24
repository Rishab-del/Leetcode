class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int gap = 1;
        bool left = true;
        while(n>1){
            if(left || n%2 != 0) head=head+gap;
            n/=2;
            gap*=2;
            left = !left;
        }
        return head;
    }
};