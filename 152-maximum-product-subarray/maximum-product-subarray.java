class Solution {
    public int maxProduct(int[] nums) {

        int n = nums.length;
        int mx = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {

             int a = 1;
            for (int j = i; j < n; j++) {

                a *= nums[j];
                mx = Math.max(mx, a);
            }
        }

        return mx;
    }
}