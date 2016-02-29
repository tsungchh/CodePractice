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
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode* root) {
        // Write your code here
        if(root == NULL)
            return true;
            
        checkRec(root->left, root->right);
    }
    
    bool checkRec(TreeNode* nodeA, TreeNode* nodeB)
    {
        if(nodeA == NULL && nodeB == NULL)
            return true;
        
        if(nodeA == NULL || nodeB == NULL)
            return false;
        
        if(nodeA->val != nodeB->val)
            return false;
            
        //divide    
        bool checkLeft = checkRec(nodeA->left, nodeB->right);
        bool checkRight = checkRec(nodeA->right, nodeB->left);
        
        //conquer
        return checkLeft && checkRight;
    }
};