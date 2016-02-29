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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        
        vector<int> ans;
        vector<vector<int>> result;
        dfs(root, target, ans, result);
        return result;
    }
    
    void dfs(TreeNode* node, int target, vector<int> answer, vector<vector<int>>& result)
    {
        
        if(node == NULL)
            return;
        
        target = target - node->val;
        answer.push_back(node->val);
        if(target == 0 && node->left == NULL && node->right == NULL)
        {
            result.push_back(answer);
            return;
        }
        
        if(node->left)
        {
            dfs(node->left, target, answer, result);
        }
        
        if(node->right)
        {
            dfs(node->right, target, answer, result);
        }
        
        answer.pop_back();
        return;
        
    }
};
