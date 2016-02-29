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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if( A.empty() ) return NULL;
        return helper(A, 0, A.size()-1);
    }
    
    SegmentTreeNode* helper(vector<int>& A, int start, int end)
    {
        if(start == end)
        {
            SegmentTreeNode* node = new SegmentTreeNode(start, end, A[start]);
            return node;
        }
        
        SegmentTreeNode* left = helper(A, start, (start+end)/2 );
        SegmentTreeNode* right = helper(A, 1+(start+end)/2, end);
        
        int maxVal = left->max > right->max ? left->max : right->max;
        SegmentTreeNode* node = new SegmentTreeNode(start, end, maxVal);
        node->left = left;
        node->right = right;
        
        return node;
    }
};
