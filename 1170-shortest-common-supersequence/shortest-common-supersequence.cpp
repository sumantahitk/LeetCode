class Solution {
public:
    string f1(string &t1,string &t2,int x,int y){
    vector<vector<int>>p(x+1,vector<int>(y+1,0));
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++){
            if(t1[i-1]==t2[j-1]){
               if(i>0 && j>0){
                 p[i][j]=1+p[i-1][j-1];
               }
            }else{
                p[i][j]=max(p[i][j-1],p[i-1][j]);
            }
        }
    }
     int i=x,j=y;
     string s="";
     while(i>0 && j>0){
        if(t1[i-1]==t2[j-1]){
            s.push_back(t1[i-1]);
            i--;
            j--;
        }
        else if(p[i][j-1]>p[i-1][j]){
            s.push_back(t2[j-1]);
            j--;
        }
        else{
            s.push_back(t1[i-1]);
            i--;
        }
     }
     while(i>0){
         s.push_back(t1[i-1]);
            i--;
     }
     while(j>0){
          s.push_back(t2[j-1]);
            j--;
     }
     reverse(s.begin(),s.end());
    return s;
}
    string shortestCommonSupersequence(string s1, string s2) {
         int x=s1.length();
         int y=s2.length();
        return f1(s1,s2,x,y); 
    }
};