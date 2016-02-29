int s2i(char c)
{
    switch (c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(string s) {
    int i = 0;
    int sum = 0;
    while(i < s.size())
    {
        if(i+1 < s.size())
        {
            int curr = s2i(s[i]);
            int next = s2i(s[i+1]);
            if(curr < next)
            {
                sum += (next-curr);
                i = i+2;
            }
            else
            {
                sum += curr;
                i++;
            }
        }
        else
        {
            int curr = s2i(s[i]);
            sum += curr;
            i++;
        }
    }
    return sum;
}