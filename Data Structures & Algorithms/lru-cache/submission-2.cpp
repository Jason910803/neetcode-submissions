class LRUCache {
private:
    struct Node {
        int key; // to delete when full
        int val;
        Node* prev;
        Node* next;
        Node(int key = 0, int val = 0) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;
    unordered_map<int, Node*> cache;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

public:
    LRUCache(int capacity) {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            moveToHead(it->second);
            return it->second->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // update key
            it->second->val = value;
            moveToHead(it->second);
            return;
        }

        // insert new key-value pair
        if (cache.size() == size) {
            Node* deleteNode = tail->prev;
            cache.erase(deleteNode->key);
            removeNode(deleteNode);
            delete deleteNode;
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        addToHead(node);
    }
};
