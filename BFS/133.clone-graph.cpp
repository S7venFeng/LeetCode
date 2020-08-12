class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        map<Node*, Node*> mp;
        queue<Node*> q;
        Node* begin = new Node(node->val);
        mp[node] = begin;
        q.push(node);
        while (!q.empty()) {
            Node* now = q.front();
            q.pop();
            for (auto x : now->neighbors) {
                if (!mp[x]) {
                    Node *n = new Node(x->val);
                    mp[x] = n;
                    q.push(x);
                }
                mp[now]->neighbors.push_back(mp[x]);
            }
        }
        return mp[node];
    }
};