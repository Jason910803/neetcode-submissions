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
    int count;
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
        count = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            moveToHead(cache[key]);
            return cache[key]->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            // update key
            cache[key]->val = value;
            moveToHead(cache[key]);
            return;
        }

        // insert new key-value pair
        if (count == size) {
            cache.erase(tail->prev->key);
            removeNode(tail->prev);
            count--;
        }

        count++;
        Node* node = new Node(key, value);
        cache[key] = node;
        addToHead(node);
    }
};
