class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int arys[3];
        memset(arys, 0, sizeof(int)*3);
        
        for(int i = 0; i < nums.size(); i++)
        {
            arys[nums[i]]++;
        }
        
        int i = 0;
        int idx = 0;
        while( i < 3)
        {
            while(arys[i] > 0)
            {
                nums[idx] = i;
                arys[i]--;
                idx++;
            }
            i++;
        }
    }
};