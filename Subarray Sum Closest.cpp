class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    class Pair {
    public:
        int sum;
        int idx;
        Pair() {}
        ~Pair() {}
    };
    
    struct Compare{
        bool operator() (Pair p1, Pair p2)
        {
            return p1.sum > p2.sum;
        }
    };
     
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        
        vector<int> answer;
        if(nums.size()==1)
        {
            answer.push_back(0);
            answer.push_back(0);
            return answer;
        }
        vector<Pair> sums;
        sums.resize(nums.size());
        Compare myCompare;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sums[i].sum = sum;
            sums[i].idx = i;
        }
        
        sort(sums.begin(), sums.end(), myCompare);
        
        int diff = INT_MAX;
        for(int i = 1; i < nums.size(); i++)
        {
            int _diff = abs( sums[i].sum - sums[i-1].sum );
            if( _diff < diff )
            {
                answer.clear();
                answer.resize(2);
                answer[0] = sums[i-1].idx;
                answer[1] = sums[i].idx;
                sort(answer.begin(), answer.end());
                answer[0]++;
                diff = _diff;
            }
        }
        
        return answer;
    }
};












