class Solution {
public:

    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {

        // Empty node
        if (root == NULL)
            return {0, 0};

        // Get information from left subtree
        pair<int, int> left = dfs(root->left);

        // Get information from right subtree
        pair<int, int> right = dfs(root->right);

        // Calculate current subtree sum
        int sum = root->val + left.first + right.first;

        // Calculate current subtree node count
        int count = 1 + left.second + right.second;

        // Check if node value == floor(average)
        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        dfs(root);

        return ans;
    }
};