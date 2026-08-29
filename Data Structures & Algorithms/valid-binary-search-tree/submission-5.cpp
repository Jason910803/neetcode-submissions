/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= low || root->val >= high) {
            return false;
        }

        return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        // return dfs(root, INT_MIN, INT_MAX);
        // iterative in-order traversal
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (prev != nullptr && curr->val <= prev->val) {
                return false;
            }

            prev = curr;
            curr = curr->right;
        }

        return true;
    }
};
