/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // BFS solution
        
        queue<TreeLinkNode*> q;
        if(root)
        {
            q.push(root);
        }
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeLinkNode* curr = q.front();
                q.pop();
                if(i == size-1)
                {
                    curr->next = NULL;
                }
                else
                {
                    TreeLinkNode* next = q.front();
                    curr->next = next;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
    }
};