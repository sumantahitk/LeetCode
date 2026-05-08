class Solution {
public:
    int ladderLength(string str, string end, vector<string>& list) {
        queue<pair<string,int>>q;
        q.push({str,1});
        set<string>st(list.begin(),list.end());
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            if(word==end) return step;
            q.pop();
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};