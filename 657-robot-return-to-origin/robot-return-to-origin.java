class Solution {
    public boolean judgeCircle(String m) {
        int l=0,r=0,u=0,d=0;
        for(char ch:m.toCharArray()){
            if(ch=='L')l++;
            else if(ch=='R') r++;
            else if(ch=='U') u++;
            else{
                d++;
            }
        }
       
        return l==r && u==d;
    }
}