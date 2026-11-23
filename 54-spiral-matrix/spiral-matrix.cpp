class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int sr=0,sc=0,er=n-1,ec=m-1;
        vector<int>ans;
        while(sr<=er && sc<=ec){

           for(int i=sc;i<=ec;i++){
                ans.push_back(mat[sr][i]);
                
           }
           for(int i=sr+1;i<=er;i++){
            
            ans.push_back(mat[i][ec]);
           
           }
           for(int i=ec-1;i>=sc;i--){
            if(sr==er) break;
            ans.push_back(mat[er][i]);
           }
           for(int i=er-1;i>sr;i--){
             if(sc==ec) break;
            ans.push_back(mat[i][sc]);
           }
           sr++;
           sc++;
           er--;
           ec--;
        }
        return ans;
    }
};