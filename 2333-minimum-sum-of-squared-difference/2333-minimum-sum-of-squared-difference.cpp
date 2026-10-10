class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxDiff = 0;
        for(int i = 0; i < n; i++){
            maxDiff = max(maxDiff,abs(nums1[i] - nums2[i]));
        }
        vector<int> countDiff(maxDiff+1, 0);
        for(int i = 0; i < n; i++){
            int d = abs(nums1[i] - nums2[i]);
            countDiff[d]++;
        }
        int k = k1 + k2;
    
        for(int currDiff = maxDiff; currDiff > 0 && k > 0; currDiff--){
            int countOps = min(countDiff[currDiff], k);
            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;
            k -= countOps;
        }
        long long result = 0;
        for(long long d = 1; d <= maxDiff; d++){
            result += (countDiff[d]*d*d);
        }
        return result;
    }
};