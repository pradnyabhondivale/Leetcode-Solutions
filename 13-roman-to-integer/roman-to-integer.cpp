class Solution {
public:
    int value(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V' : return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        // unordered_map<char,int> mp;
        // mp['I'] = 1;
        // mp['V'] = 5;
        // mp['X'] = 10;
        // mp['L'] = 50;
        // mp['C'] = 100;
        // mp['D'] = 500;
        // mp['M'] = 1000;

        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            if(i<s.length()-1 && value(s[i])<value(s[i+1]))
                ans -= value(s[i]);
            else
                ans += value(s[i]);
        }
        return ans;
    }
};