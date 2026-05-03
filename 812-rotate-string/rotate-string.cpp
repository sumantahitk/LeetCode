class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        //contains Method only applicable when c++ version moore that 20
        //Otherwise use find method;
        //both case it takes n^2 complexity
        
        // return (s+s).contains(goal);
        return (s+s).find(goal)!=string::npos;
        
    }
};