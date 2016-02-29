class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        
        
        
        sort(nums.begin(), nums.end());
        vector< vector<int> > answers;
        
        for(int f = 0; f < nums.size(); f++)
        {
            if ( f > 0 && nums[f] == nums[f - 1] ) 
                continue;
            
            int target_1 = target - nums[f];
            
            for(int t = f+1 ; t < nums.size(); t++)
            {
                if ( t > f+1 && nums[t] == nums[t - 1] ) 
                    continue;

                int target_2 = target_1 - nums[t];
                
                unordered_map<int, int> map;
                for(int i = t+1; i < nums.size(); i++)
                {
                    int diff = target_2 - nums[i];
                    if( map.find(diff) != map.end() )
                    {
                        vector<int> answer;
                        answer.push_back( nums[f] );
                        answer.push_back( nums[t] );
                        answer.push_back( diff );
                        answer.push_back( nums[i] );
                        if(answers.size() > 0)
                        {
                            vector<int> lastSet = answers[answers.size()-1];
                            if(lastSet[0] == answer[0] && 
                               lastSet[1] == answer[1] &&
                               lastSet[2] == answer[2] &&
                               lastSet[3] == answer[3] )
                            {
                                 continue;  
                            }
                        }
                        answers.push_back(answer);
                    }
                    map[ nums[i] ] = i; 
                }
            }
        }
        return answers;
    }
};

