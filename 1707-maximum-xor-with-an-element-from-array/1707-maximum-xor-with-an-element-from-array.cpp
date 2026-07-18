class Trie {
    struct Node {
        Node* link[2] = {nullptr, nullptr};

        bool contain(int bit) {
            return link[bit] != nullptr;
        }

        Node* get(int bit) {
            return link[bit];
        }

        void put(int bit, Node* node) {
            link[bit] = node;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->contain(bit))
                node->put(bit, new Node());

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->contain(1 - bit)) {
                ans |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> q;

        // {m, x, originalIndex}
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }

        sort(q.begin(), q.end());

        Trie trie;
        vector<int> ans(queries.size());

        int j = 0;

        for (int i = 0; i < q.size(); i++) {

            int m = q[i][0];
            int x = q[i][1];
            int idx = q[i][2];

            while (j < nums.size() && nums[j] <= m) {
                trie.insert(nums[j]);
                j++;
            }

            if (j == 0)
                ans[idx] = -1;
            else
                ans[idx] = trie.getMax(x);
        }

        return ans;
    }
};