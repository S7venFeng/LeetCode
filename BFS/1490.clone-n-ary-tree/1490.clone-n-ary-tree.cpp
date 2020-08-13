class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return root;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(root);
        Node* begin = new Node(root->val);
        mp[root] = begin;
        while (!q.empty()) {
            Node* now = q.front();
            q.pop();
            for (auto &x : now->children) {
                if (!mp[x]) {
                    Node* next = new Node(x->val);
                    mp[x] = next;
                    q.push(x);
                }
                mp[now]->children.push_back(mp[x]);
            }
        }
        return mp[root];
    }
};