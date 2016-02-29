class Solution {
public:
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        // Write your code here
        
        return merge(0, arrays.size()-1, arrays);
        
    }
    
    vector<int> merge(int idx1, int idx2, vector<vector<int>>& arrays)
    {
        if(idx1 == idx2)
            return arrays[idx1];
            
        
        int midIdx = (idx1 + idx2) / 2;
        vector<int> ary1 = merge(idx1, midIdx, arrays);
        vector<int> ary2 = merge(midIdx+1, idx2, arrays);
        
        return mergeArys(ary1, ary2);
        
    }
    
    vector<int> mergeArys(vector<int> ary1, vector<int> ary2)
    {
        int idx1, idx2;
        idx1 = idx2 = 0;
        vector<int> ret;
        
        while(idx1 < ary1.size() && idx2 < ary2.size())
        {
            if(ary1[idx1] < ary2[idx2])
            {
                ret.push_back(ary1[idx1]);
                idx1++;
            }
            else
            {
                ret.push_back(ary2[idx2]);
                idx2++;
            }
        }
        
        while(idx1 < ary1.size())
        {
            ret.push_back(ary1[idx1]);
            idx1++;
        }
        
        while(idx2 < ary2.size())
        {
            ret.push_back(ary2[idx2]);
            idx2++;
        }
        
        return ret;
    }
};