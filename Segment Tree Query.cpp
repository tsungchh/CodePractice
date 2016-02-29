/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        return helper(root, start, end);
    }
    
    int helper(SegmentTreeNode* node, int start, int end)
    {
        //assuming all number are positive.
        if(node == NULL)
            return -1;
        if(node->end < start)
            return -1;
        if(node->start > end)
            return -1;
        
        if(node->start >= start && node->end <= end)
            return node->max;
        
        int left = helper(node->left, start, end);
        int right = helper(node->right, start, end);
        
        return max(left, right);
    }
    
    int max(int left, int right)
    {
        return left > right ? left : right;
    }
};