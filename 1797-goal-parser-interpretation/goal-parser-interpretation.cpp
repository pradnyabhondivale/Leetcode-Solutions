class Solution {
public:
    string interpret(string command) {
        string cmd="";
        for(int i=0;i<command.length();i++)
        {
            if(command[i]=='G')
            {
                cmd += 'G';
            }
            else if(command[i] =='(' && command[i+1] == ')')
            {
                cmd += 'o';
                i++;
            }
            else
            {
                cmd += "al";
                i+=3; 
            } 
        }
        return cmd;
    }
};