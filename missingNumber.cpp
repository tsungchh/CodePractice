int missingNumber(vector<int>& nums) {
    
    int i = 0;
    while(i < nums.size())
    {
        if(nums[i] != 0 && nums[i] != i+1)
        {
            int tmp = nums[i];
            nums[i] = nums[tmp-1];
            nums[tmp-1] = tmp;
        }
        else
        {
            i++;
        }
    }
    
    for(i = 0; i < nums.size(); i++)
        if(nums[i] == 0) return i+1;
        
    return -1;
}



int res = 0;
for (int i = 0; i < nums.size(); ++i) {
    res ^= (i + 1) ^ nums[i];
}
return res;