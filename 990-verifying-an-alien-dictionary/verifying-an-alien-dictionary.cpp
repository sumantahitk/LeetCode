class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<int>rank(26);
        for(int i=0;i<order.size();i++){
            rank[order[i]-'a']=i;
        }
        // Step 1: Build graph
        for (int j = 0; j < n - 1; j++) {
            string s1 = words[j], s2 = words[j + 1];
            int len = min(s1.size(), s2.size());
            int i = 0;
            int flag=0;
            while (i < len) {
                if (s1[i] != s2[i]) {
                   flag=1;
                   if(rank[s1[i]-'a']>rank[s2[i]-'a']) return false;
                    
                    break;
                }
                i++;
            }

        
            if (!flag && s1.size() > s2.size()) return 0;
        }

       return 1;
    }
};