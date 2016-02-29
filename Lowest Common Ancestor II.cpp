/**
 * Definition of ParentParentTreeNode:
 * class ParentParentTreeNode {
 * public:
 *     int val;
 *     ParentParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        // Write your code here
        
        unordered_set<ParentTreeNode*> visited;
        
        ParentTreeNode* curr = A;
        while(curr != NULL)
        {
            visited.insert(curr);
            curr = curr->parent;
        }
        curr = B;
        while(curr != NULL)
        {
            if(visited.find(curr) != visited.end())
            {
                return curr;
            }
            curr = curr->parent;
        }
        
        return NULL;
        
    }
};
