class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[j - 1] + 1) {
                sum += nums[j];
            }
            else {
                break;
            }
        }
        int x = sum;
        while(true){
            bool found = false;
            for (int n : nums) {
                if (n == x) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return x;
            x++;
        }
    }
};