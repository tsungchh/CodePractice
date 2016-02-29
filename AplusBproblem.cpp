#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int ary[32];
        
        int carry = 0;
        for(int i = 0; i < 32; i++)
        {
            int aBit = (a & (1 << i)) == 0 ? 0 : 1;
            int bBit = (b & (1 << i)) == 0 ? 0 : 1;
            int sum = aBit + bBit + carry;
            carry = sum / 2;
            ary[i] = sum % 2;
        }
        
        int ret = 0;
        for(int i = 31; i >= 0; i--)
        {
            ret = ret*2 + ary[i];
        }
        
        return ret;
    }
};


int main()
{
    Solution solution;
    int sum = solution.aplusb(100,-100);
    cout << sum << endl;
    return 0;
}