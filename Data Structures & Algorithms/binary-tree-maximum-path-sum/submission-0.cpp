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
    int ans = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftmax = max(dfs(node->left), 0);
        int rightmax = max(dfs(node->right), 0);

        ans = max(ans, node->val + leftmax + rightmax);

        return node->val + max(leftmax, rightmax);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};