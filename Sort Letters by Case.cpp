class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        // quicksort
        int cutVal = 'A';
        int r = 0;
        int l = letters.size()-1;
        while( r < l )
        {
            while(r < letters.size() && letters[r] >= 'a' && letters[r] <= 'z')
            {
                r++;
            }
            
            while(letters[l] >= 'A' && letters[l] <= 'Z')
            {
                l--;
            }
            
            if(r < l)
            {
                char tmp = letters[r];
                letters[r] = letters[l];
                letters[l] = tmp;
            }
        }
        
    }
};

