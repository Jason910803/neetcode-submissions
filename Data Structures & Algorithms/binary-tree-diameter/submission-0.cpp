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
private:
    int ans = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);

        ans = max(ans, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
