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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> ret;
        vector< vector<int> > answer;
        vector<int> tmpAns;
        
        if(root == NULL)
            return ret;
        tmpAns.push_back(root->val);
        helper(answer, tmpAns, root);
        ret = convert2Str(answer);
        return ret;
    }
    
    vector<string> convert2Str(vector< vector<int> > answer)
    {
        vector<string> ret;
        for(int i = 0; i < answer.size(); i++)
        {
            string str = "";
            for(int j = 0; j < answer[i].size(); j++)
            {
                str = str + to_string(answer[i][j]) + "->";
            }
            str = str.substr(0, str.size()-2);
            ret.push_back(str);
        }
        
        return ret;
    }
    
    void helper(vector< vector<int> >& answer, vector<int> tmpAns, TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            answer.push_back(tmpAns);
            return;
        }
        
        if(root->left)
        {
            tmpAns.push_back(root->left->val);
            helper(answer, tmpAns, root->left);
            tmpAns.pop_back();
        }
        
        if(root->right)
        {
            tmpAns.push_back(root->right->val);
            helper(answer, tmpAns, root->right);
            tmpAns.pop_back();
        }
    }
};
