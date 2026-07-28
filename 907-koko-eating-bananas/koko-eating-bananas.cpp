class Solution {
public:
   // Function to calculate total hours for given speed
    long long calculateTotalHours(vector<int>& a, int hourly) {
    long long totalHours = 0;

    for (int pile : a) {
        totalHours += (1LL * pile + hourly - 1) / hourly;
    }

    return totalHours;
}

    // Function to find minimum eating speed
   int minEatingSpeed(vector<int>& piles, int h) {

    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long hours = calculateTotalHours(piles, mid);

        if (hours <= h) {
            high = mid - 1;      // Try a smaller speed
        } else {
            low = mid + 1;       // Need a faster speed
        }
    }

    return low;
}
};