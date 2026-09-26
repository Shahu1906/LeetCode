class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long odd = 0;
        long long even = 0;

        for (int x : nums) {
            long long newOdd = max(odd, even + x);
            long long newEven = max(even, odd - x);

            odd = newOdd;
            even = newEven;
        }
        return odd;
    }
};