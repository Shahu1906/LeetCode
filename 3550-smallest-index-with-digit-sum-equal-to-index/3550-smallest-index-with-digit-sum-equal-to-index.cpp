class Solution {
public:
    int sumd(int n) {
        int sum = 0;
        int r = n;
        while (r > 0) {
            sum += r % 10;
            r /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            int sum = sumd(nums[i]);
            if (sum == i)
                return i;
        }

        return -1;
    }
};