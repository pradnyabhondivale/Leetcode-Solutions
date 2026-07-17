class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> st;
        for(string word : words)
        {
            string code = "";
            for(char c : word)
            {
                code += morse[c - 'a'];
            }
            st.insert(code);
        }
        return st.size();
    }
};