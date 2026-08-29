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
    int kthSmallest(TreeNode* root, int k) {
        // iterative in-order traversal
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        int count = 0;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            // increment count and check if it equals to k
            count++;
            if (count == k) {
                return curr->val;
            }

            prev = curr;
            curr = curr->right;
        }

        return true;
    }
};
