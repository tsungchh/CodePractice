class Solution {
public:
    
    struct Pair
    {
        int idx;
        int val;
        Pair(int _idx, int _val) 
        {
            idx = _idx;
            val = _val;
        }
    };
    
    class Comparator
    {
    public:
        bool operator()(Pair a, Pair b)
        {
            return a.val < b.val;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        
        Comparator c;
        vector<Pair> pairAry;
        for(int i = 0; i < nums.size(); i++)
        {
            Pair p(i, nums[i]);
            pairAry.push_back(p);
        }
        sort(pairAry.begin(), pairAry.end(), c);
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            int sum = pairAry[start].val + pairAry[end].val;
            if(sum == target)
            {
                vector<int> ret;
                ret.push_back(pairAry[start].idx+1);
                ret.push_back(pairAry[end].idx+1);
                sort(ret.begin(), ret.end());
                return ret;
            }
            else if(sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return vector<int>();
    }
};