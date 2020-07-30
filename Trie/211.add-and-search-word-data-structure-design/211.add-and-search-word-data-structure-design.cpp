class WordDictionary {
        public:
        typedef struct trie {
            trie *next[26];
            int isEnd;
        } Trie;
        Trie *tri;

        bool helper(string word, Trie *t, int index) {
            if (index > word.size() - 1) {
                if (word[index] == '.') {
                    for (int i = 0; i < 26; ++i) {
                        if (t->next[i] && t->isEnd) return true;
                    }
                    return false;
                } else {
                    return t->isEnd == 1;
                }
            }
            if (word[index] == '.') {
                for (int i = 0; i < 26; ++i) {
                    if (t->next[i]) {
                        if (true == helper(word, t->next[i], index + 1)) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                if (!t->next[word[index] - 'a']) return false;
                return helper(word, t->next[word[index] - 'a'], index + 1);
            }
        }
        /** Initialize your data structure here. */
        WordDictionary() {
            tri = new Trie();
        }

        /** Adds a word into the data structure. */
        void addWord(string word) {
            Trie *p = tri;
            for (int i = 0; i < word.size(); ++i) {
                if (!p->next[word[i] - 'a']) {
                    p->next[word[i] - 'a'] = new Trie();
                }
                p = p->next[word[i] - 'a'];
            }
            p->isEnd = 1;
        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            Trie *p = tri;
            return helper(word, p, 0);
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */