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
     * @return true if it is a complete binary tree, or false.
     */
    bool isComplete(TreeNode* root) {
        // Write your code here
        // Write your code here
        
        queue<TreeNode*> q;
        if(root)
        {
            q.push(root);
        }
        
        bool end = false;
        
        while( !q.empty() )
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left)
                {
                    if(end)
                    {
                        return false;
                    }
                    else
                    {
                        q.push(node->left); 
                    }
                }
                else
                {
                    end = true;
                }
                    
                if(node->right)
                {
                    if(end)
                    {
                        return false;
                    }
                    else
                    {
                        q.push(node->right);
                    }
                }  
                else
                {
                    end = true;
                }
            }
            
            if(end)
                break;
        }
        
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left || node->right)
                return false;
        }
        
        return true;
        
    }
};