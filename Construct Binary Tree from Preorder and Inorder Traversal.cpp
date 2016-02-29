TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    return helper(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
}

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int is, int ie, int ps, int pe)
{
    if(ie < is)
        return NULL;
        
    
    int rootVal = preorder[ps];
    int numL = 0;
    int numR = 0;
    int i = is;
    while(inorder[i] != rootVal)
    {
        i++;
        numL++;
    }
    
    numR = ie-is+1-numL-1;
    
    TreeNode* curr = new TreeNode(rootVal);
    curr->left = helper(preorder, inorder, is, is+numL-1, ps+1, ps+numL);
    curr->right = helper(preorder, inorder, ie-numR+1, ie, pe-numR+1 , pe);
    
    return curr;
    
}