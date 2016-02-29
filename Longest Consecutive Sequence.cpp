int longestConsecutive(vector<int> &num) {
    // write you code here
    unordered_map<int, bool> map;
    for(int i = 0; i < num.size(); i++)
    {
        map[num[i]] = true;
    }
    
    int maxLength = 1;
    
    for(int i = 0; i < num.size(); i++)
    {
        int currVal = num[i];
        
        int length = 1;
        currVal++;
        
        while( map.find(currVal) != map.end() )
        {
            length++;
            map.erase(currVal);
            currVal++;   
        }
        
        currVal = num[i];
        currVal--;
        while( map.find(currVal) != map.end() )
        {
            length++;
            map.erase(currVal);
            currVal--;   
        }
        maxLength = maxLength > length ? maxLength : length;
    }
    
    return maxLength;
}