const int N = 10010;
class MagicDictionary {
    int son[N][26];
    int cnt[N];
    int idx;
public:
    bool dfs(string word, int p, int idx, int times) {
        if (idx == word.size()) {
            if (cnt[p] && times == 1) return true;
            return false;
        }
        if (times >= 2) return false;
        int u = word[idx] - 'a';
        if (son[p][u]) {
            if (true == dfs(word, son[p][u], idx + 1, times)) return true;
            for (int i = 0; i < 26; ++i) {
                if (son[p][i] && i != u) {
                    if (true == dfs(word, son[p][i], idx + 1, times + 1)) {
                        return true;
                    }
                }
            }
        } else {
            for (int i = 0; i < 26; ++i) {
                if (son[p][i]) {
                    if (true == dfs(word, son[p][i], idx + 1, times + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    /** Initialize your data structure here. */
    MagicDictionary() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 26; ++j) {
                son[i][j] = 0;
            }
            cnt[i] = 0;
        }
        idx = 0;
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto v : dict) {
            int p = 0;
            for (int i = 0; i < v.size(); ++i) {
                int u = v[i] - 'a';
                if (!son[p][u]) {
                    son[p][u] = ++idx;
                }
                p = son[p][u];
            }
            cnt[p]++;
        }
        return;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(word, 0, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */