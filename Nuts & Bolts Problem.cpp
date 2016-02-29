/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        // quick sort solution
        quickSort(nuts, bolts, 0, nuts.size()-1, compare); 
        
    }
    
    void quickSort(vector<string> &nuts, vector<string> &bolts, int start, int end, Comparator compare)
    {
        // if(start < 0 || end >= nuts.size())
        //     return;
        
        if(start >= end)
            return;
        
        string pivot = bolts[(start+end)/2];
        
        int pvIdx = partition(nuts, pivot, start, end, compare);    
        
        partition(bolts, nuts[pvIdx], start, end, compare);
        
            
        quickSort(nuts, bolts, start, pvIdx-1, compare);
        quickSort(nuts, bolts, pvIdx+1, end, compare);
        
    }
    
    int partition(vector<string> &ary, string pv, int start, int end, Comparator compare)
    {
        // fprintf(stderr, "part st = %d, en = %d, pv = %s\n", start, end, pv.c_str());
        int lessIdx = start;
        int greatIdx = end;
        for(int i = start; i <= end; i++)
        {   
            if(i > greatIdx)
                break;
            
            //smaller than pivot
            if(compare.cmp(ary[i], pv) == -1 || compare.cmp(pv, ary[i]) == 1)
            {
                swap(ary, lessIdx, i);
                lessIdx++;
                // fprintf(stderr, "i=%d, small\n", i);
            }
            //equal to pivot
            else if(compare.cmp(ary[i], pv) == 0 || compare.cmp(pv, ary[i]) == 0)
            {
                
                // fprintf(stderr, "i=%d, equal\n", i);
                continue;
            }
            //bigger than pivot
            else if( compare.cmp(ary[i], pv) == 1 || compare.cmp(pv, ary[i]) == -1)
            {
                
                // fprintf(stderr, "i=%d, great = %d big\n", i, greatIdx);
                swap(ary, greatIdx, i);
                greatIdx--;
                i--;
            }
        }
        
        return lessIdx;
    }
    
    void swap(vector<string>& ary, int idxA, int idxB)
    {
        string tmp = ary[idxA];
        ary[idxA] = ary[idxB];
        ary[idxB] = tmp;
    }
};