/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeDFS(TreeNode* node, string& data) {
        if (!node) {
            data += "# ";
            return;
        }

        data += to_string(node->val) + " ";
        serializeDFS(node->left, data);
        serializeDFS(node->right, data);
    }

    TreeNode* deserializeDFS(istringstream& iss) {
        string token;
        iss >> token;

        if (token == "#") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeDFS(iss);
        node->right = deserializeDFS(iss);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serializeDFS(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeDFS(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));