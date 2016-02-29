TreeNode* insertNode(TreeNode* root, TreeNode* node) {
    // write your code here
    
    if(!root)
        return node;
    TreeNode* prev = NULL;
    TreeNode* curr = root;
    
    while(curr)
    {
        if(curr->val < node->val)
        {
            prev = curr;
            curr = curr->right;
        }
        else
        {
            prev = curr;
            curr = curr->left;
        }
    }
    if(prev->val < node->val)
    {
        prev->right = node;
    }
    else
    {
        prev->left = node;
    }
    
    return root;
    
    
    
    // return insertNodeHelper( root, node );
    
}
TreeNode* insertNodeHelper( TreeNode* root, TreeNode* node )
{
    if( root == NULL )
        return node;
    
    if( root->val > node->val )
    {
        root->left = insertNodeHelper( root->left, node );
    }
    else 
    {
        root->right = insertNodeHelper( root->right, node );
    }
    
    return root;
}