struct Node{
    Node* link[2]={NULL,NULL};

    bool contain(int bit){
        return link[bit] != nullptr;
    }

    Node* get(int bit){
        return link[bit];
    }

    void put(int bit,Node* node){
        link[bit]=node;
    }
};

class Solution {

private: 
    Node* root;

public:
    Solution(){
        root= new Node();
    }
    void insert(int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(!temp->contain(bit)){
                temp->put(bit,new Node);
            }
            temp=temp->get(bit);
        }
    }
    int getmax(int n){
        Node* temp=root;
        int maxx=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(temp->contain(1-bit)){
                maxx=maxx | (1<<i) ;
                temp=temp->get(1-bit);
            }
            else temp=temp->get(bit);
        }
        return maxx;
    }
    int findMaximumXOR(vector<int>& nums) {
        Solution trie;
        int high=0;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            high = max(high,trie.getmax(nums[i]));
        }
        return high;

    }
};