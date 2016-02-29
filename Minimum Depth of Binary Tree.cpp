int minDepth(TreeNode* root) {
        
    if(root == NULL)
        return 0;
        
    int depth = 1;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if( !curr->left && !curr->right)
                return depth;
                
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            
        }
        depth++;
    }
    
    return depth;
}