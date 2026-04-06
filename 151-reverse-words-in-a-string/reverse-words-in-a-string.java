class Solution {
    public String reverseWords(String s) {
        s=s.trim();
        String[] str= s.split("\\s+");
        int i=0,j=str.length-1;
        while(i<=j){
            String temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            i++;
            j--;
        }
    String ans="";
    for(String s1:str){
        // System.out.println(s1);
        ans+=s1;
        ans+=" ";
    }
        ans=ans.substring(0,ans.length()-1);
        return ans;
        // return String.join(" ",str);
    }
}