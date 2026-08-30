/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    // original node -> clone node
    unordered_map<Node*, Node*> cloneMap;

public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        if (cloneMap.count(node)) {
            return cloneMap[node];
        }

        Node* copy = new Node(node->val);
        cloneMap[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }

        return copy;
    }
};
