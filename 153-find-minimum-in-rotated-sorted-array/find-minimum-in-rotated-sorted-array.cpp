class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] <= arr[h]) {
                // Minimum is in the left half (including mid)
                h = mid;
            } else if (arr[mid] > arr[h]) {
                // Minimum is in the right half (excluding mid)
                l = mid + 1;
            } 
        }

        // l == h points to the minimum element
        return arr[l];
    }
};