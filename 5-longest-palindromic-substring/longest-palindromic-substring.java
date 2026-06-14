class Solution {
    boolean isPal(String s){
        int n=s.length()-1;
        for(int i=0;i<s.length()/2;i++){
            if(s.charAt(i)!=s.charAt(n-i)) return false;
        }

        return true;
    }
    public String longestPalindrome(String s) {
        if(isPal(s)) return s;
        int st=0,end=0,mx=0;
        for(int j=0;j<s.length();j++){
            for(int i=s.length()-1;i>=j;i--){
            if(isPal(s.substring(j,i+1))){
                if(mx<(i-j+1)){
                    mx=(i-j+1);
                    st=j;
                    end=i;
                }
            }
        }
        }
        return s.substring(st,end+1);
    }
}