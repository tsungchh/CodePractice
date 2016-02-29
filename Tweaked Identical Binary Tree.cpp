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
     * @aaram a, b, the root of binary trees.
     * @return true if they are tweaked identical, or false.
     */
    bool isTweakedIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        
        //base case
        
        if(a == NULL && b == NULL)
            return true;
        
        if(!(a && b && a->val == b->val))
            return false;
            
        
        TreeNode* left = a->left;
        TreeNode* right = a->right;
        
        TreeNode* leftB = b->left;
        TreeNode* rightB = b->right;
        
        
        // two cases
        bool ret1 = false;
        bool ret2 = false;
        
        ret1 = isTweakedIdentical(left, leftB) && isTweakedIdentical(right, rightB);
        ret2 = isTweakedIdentical(right, leftB) && isTweakedIdentical(left, rightB);
        
        return ret1 || ret2;
    }
};