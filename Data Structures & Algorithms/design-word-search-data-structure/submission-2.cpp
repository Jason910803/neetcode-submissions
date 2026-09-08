class WordDictionary {
private:
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root;

    bool dfs(const string& word, int index, Node* node) {
        if (index == word.size()) return node->isEnd;

        char c = word[index];
        if (c != '.') {
            int i = c - 'a';
            if (!node->children[i]) {
                return false;
            }

            return dfs(word, index + 1, node->children[i]);
        }

        for (Node* child : node->children) {
            if (child && dfs(word, index + 1, child)) {
                return true;
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;

        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
