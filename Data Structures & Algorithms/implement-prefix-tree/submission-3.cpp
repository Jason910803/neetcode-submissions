class PrefixTree {
private:
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* cur = root;

        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;

        for (char c : prefix) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }

        return true;
    }
};
