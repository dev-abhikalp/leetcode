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
    int cameras = 0;

    // 0 = covered
    // 1 = has camera
    // 2 = needs camera

    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 2 || right == 2) {
            cameras++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 0;
        }
        return 2;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 2)
            cameras++;

        return cameras;
    }
};