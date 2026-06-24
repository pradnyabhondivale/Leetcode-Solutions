class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> num;
        for(int i=left ; i<=right ; i++)
        {
            if(isSelfDividingNum(i))
                num.push_back(i);
        }
        return num;
        
    }
    bool isSelfDividingNum(int n)
    {
        int ori = n;
        while(n>0)
        {
            int digit = n%10;
            if(digit==0)
                return false;
            
            if(ori % digit != 0 )
                return false;
            
            n /= 10;
        }
        return true;
    }
};