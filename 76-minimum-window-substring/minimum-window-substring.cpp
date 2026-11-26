class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=s.size(),m=t.size();
        vector<int>arr(128);
        for(int i=0;i<m;i++){
            arr[t[i]]++;
        }
        int k=m;
        int h=0,l=0,st=0,end=0,mn=INT_MAX;
        while(h<n){
           arr[s[h]]--;
           if(arr[s[h]]>=0){
                k--;
           }
           while(k==0){
            if(mn>(h-l+1)){
                mn=h-l+1;
                st=l;
                end=h;
            }
            arr[s[l]]++;
            if(arr[s[l]]>0){
                k++;
            }
            l++;
           }
             h++;
        }
        if(mn ==INT_MAX) return "";
        return s.substr(st,mn);
    }
};