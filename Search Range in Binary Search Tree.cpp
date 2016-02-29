

vector<int> searchRange(TreeNode* root, int k1, int k2) 
{
    
    vector<int> answer;
    helper(root, k1, k2, answer);
    
    return answer;
    
}

void helper(TreeNode* node, int k1, int k2, vector<int>& answer)
{
    if(node == NULL) return;
    
    if(node->val > k1)
        helper(node->left, k1, k2, answer);
    if(node->val >= k1 && node->val <= k2)
        answer.push_back(node->val);
    if(node->val < k2)
        helper(node->right, k1, k2, answer);
    
    return;
}