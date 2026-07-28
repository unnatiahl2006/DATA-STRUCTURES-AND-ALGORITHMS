class Solution {
public:
    int calculateSum(vector<int>& nums, int divisor) {
        int sum = 0;

        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;   // ceil(num/divisor)
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = calculateSum(nums, mid);

            if (sum <= threshold) {
                high = mid - 1;      // try smaller divisor
            }
            else {
                low = mid + 1;       // divisor too small
            }
        }

        return low;
    }
};