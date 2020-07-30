const int N = 100010;
class Trie {
        int son[N][26];
        int cnt[N];
        int idx = 0;
        public:
        /** Initialize your data structure here. */
        Trie() {
            memset(son, 0, N * 26 * sizeof(int));
            memset(cnt, 0, N * sizeof(int));
            idx = 0;
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            int n = word.size();
            int p = 0;
            for (int i = 0; i < n; ++i) {
                int u = word[i] - 'a';
                if (0 == son[p][u]) {
                    son[p][u] = ++idx;
                }
                p = son[p][u];
            }
            cnt[p]++;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            int p = 0;
            for (int i = 0; i < word.size(); ++i) {
                int u = word[i] - 'a';
                if (!son[p][u]) {
                    return false;
                }
                p = son[p][u];
            }
            if (!cnt[p]) return false;
            return true;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            int p = 0;
            for (int i = 0; i < prefix.size(); ++i) {
                int u = prefix[i] - 'a';
                if (!son[p][u]) return false;
                p = son[p][u];
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */