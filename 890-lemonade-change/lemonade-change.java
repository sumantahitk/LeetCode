class Solution {
    public boolean lemonadeChange(int[] b) {
        int n=b.length;
        int c5=0,c10=0;
        for(int i=0;i<n;i++){
            if(b[i]==5){
                c5++;
            }
            else if(b[i]==10){
                if( c5>=1)
                { c5--;
                 c10++;
                }
                else{
                    return false;
                }
            }
            else if(b[i]==20){
                if(c10>=1 && c5>=1){
                    c10--;
                    c5--;
                }
                else if(c5>=3){
                    c5-=3;
                }
                else{
                    return false;
                }
            }
           
        } 
        System.out.println(c5 +" "+c10);
        return true;

    }
}