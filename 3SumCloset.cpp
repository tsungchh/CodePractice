#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int min = INT_MAX;
        int minV = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            //if(i > 0 && nums[i] == nums[i-1])
                //continue;
                
            int target_2Sum = target-nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start < end)
            {
                int sum_tmp = nums[start] + nums[end];
                if(sum_tmp == target_2Sum)
                {
                    return target;
                }
                else if( sum_tmp < target_2Sum)
                {
                    int diff = target - nums[i] - nums[start] - nums[end];

                    fprintf(stderr, "%d %d\n", abs(min), abs(diff));
                    if(abs(min) > abs(diff))
                    {
                        min = diff;
                        minV = nums[i] + nums[start] + nums[end];
                        fprintf(stderr, "%d %d %d\n", nums[i], nums[start], nums[end]);
                    }
                    start++;
                }
                else
                {
                    int diff = target - nums[i] - nums[start] - nums[end];
                    fprintf(stderr, "%d %d\n", abs(min), abs(diff));
                    if(abs(min) > abs(diff))
                    {
                        min = diff;
                        minV = nums[i] + nums[start] + nums[end];

                        fprintf(stderr, "%d %d(%d) %d(%d)\n", nums[i], nums[start],start, nums[end],end);
                    }
                    end--;
                }
            }
        }
        
        return minV;
    }
};



int main()
{
    Solution s;
    vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    fprintf(stderr, "%d\n", s.threeSumClosest(test, 0));

    return 0;
}