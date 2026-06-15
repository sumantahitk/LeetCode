class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer>st=new Stack<>();
        // ArrayList<Integer>arr=new ArrayList<>();
        int n=nums.length;
        int[] arr=new int[n];
        Arrays.fill(arr,-1);
        for(int i=0;i<(2*nums.length);i++){
            while(!st.isEmpty() && nums[st.peek()]<nums[i%n]){
                arr[st.peek()]=nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return arr;
    }
}