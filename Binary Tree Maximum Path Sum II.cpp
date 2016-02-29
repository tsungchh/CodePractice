/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree.
     * @return an integer
     */
    int maxPathSum2(TreeNode *root) {
        // Write your code here
        
        if(root == NULL)
            return 0;
        
        int left = maxPathSum2(root->left);
        int right = maxPathSum2(root->right);
        
        int max = left > right ? left : right;
        
        return max > 0 ? max + root->val : root->val;
    }
};
