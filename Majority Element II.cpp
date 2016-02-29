class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // each time when doing cancel operation, it cancel 3 elements
        // => cancel at most n/3 times
        
        // if cancel < n/3 times => this array has elements occur >= n/3 times.
        
        // now the given condition is that this array has elements occur >= n/3 time
        // so it means => we must can only cancel less than n/3 times.
        // => the elements occur >= n/3 times will remain if one of the basket.
        
        // the problem now become: How the algorithm can cancel 3 different elements at a time?
        
        if(nums.size() == 0)
        {
            return vector<int>();
        }
        int basket1_val = 0;
        int basket1_ct = 0;
        int basket2_val = 0;
        int basket2_ct = 0;
        vector<int> ret;
        
        for(int i = 0; i < nums.size() ;i++)
        {
            if(basket1_ct != 0 && nums[i] == basket1_val)
            {
                basket1_ct++;    
            }
            else if(basket1_ct != 0 && nums[i] == basket2_val)
            {
                basket2_ct++;    
            }
            else if(basket1_ct == 0)
            {
                basket1_val = nums[i];
                basket1_ct++;
            }
            else if(basket2_ct == 0)
            {
                basket2_val = nums[i];
                basket2_ct++;
            }
            else
            {
                basket1_ct--;
                basket2_ct--;
            }
        }
        basket1_ct = 0;
        basket2_ct = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == basket1_val)
            {
                basket1_ct++;
                continue; // incase it only has one repeative element
            }
            
            if(nums[i] == basket2_val)
            {
                basket2_ct++;
                continue;
            }
        }
        
        if(basket1_ct > nums.size()/3 )
            ret.push_back(basket1_val);
        
        if(basket2_ct > nums.size()/3 )
            ret.push_back(basket2_val);
            
        return ret;
    }
};