class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Store value and its original index
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        
        // Sort according to values
        sort(arr.begin(), arr.end());
        
        int i = 0;
        
        while (i < n) {
            int j = i;
            
            // Find all elements belonging to the same group
            while (j + 1 < n && arr[j + 1].first - arr[j].first <= limit) {
                j++;
            }
            
            // Collect indices of this group
            vector<int> indices;
            
            for (int k = i; k <= j; k++) {
                indices.push_back(arr[k].second);
            }
            
            // Sort indices
            sort(indices.begin(), indices.end());
            
            // Values are already sorted because arr is sorted
            // Assign smallest values to smallest indices
            for (int k = 0; k < indices.size(); k++) {
                nums[indices[k]] = arr[i + k].first;
            }
            
            i = j + 1;
        }
        
        return nums;
    }
};