class Solution {
    public int totalFruit(int[] f) {
        
         int l=0,h=0,n=f.length,len=0,k=0;
        
        Map <Integer,Integer> arr=new HashMap<>();
        
        while(h<n){
           if(!arr.containsKey(f[h])){
            arr.put(f[h],1);
            k++;
           }else{
            arr.put(f[h],arr.get(f[h])+1);
           }
            
            while(k>2){
                arr.put(f[l],arr.get(f[l])-1);
                if(arr.get(f[l])==0){
                    k--;
                    arr.remove(f[l]);
                }
                l++;
            }
            len=Math.max(len,h-l+1);
            h++;

        }
        return len;
    }
}