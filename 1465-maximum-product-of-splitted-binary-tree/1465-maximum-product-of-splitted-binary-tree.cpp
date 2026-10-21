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
    long SUM = 0; //Total sum of the tree
    long maxP = 0;

    //Total Sum
    int totalSum(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        long subTreeSum = root->val + leftSubtreeSum + rightSubtreeSum;

        long remainingSubTreeSum = SUM - subTreeSum; //S2
        maxP = max(maxP, subTreeSum * remainingSubTreeSum);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        if(root == NULL)
            return 0;

        maxP = 0;
        SUM = totalSum(root);
        totalSum(root);

        return maxP % (1000000007);
    }
};