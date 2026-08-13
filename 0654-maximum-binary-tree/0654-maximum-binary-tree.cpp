/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(int l, int r, vector<int>&nums){
        if(l >= nums.size() || r < 0 || l > r) return NULL;

        int maxIdx = l;
        for(int i=l; i<=r; i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }

        TreeNode *newNode = new TreeNode(nums[maxIdx]);

        newNode->left = helper(l,maxIdx-1,nums);
        newNode->right = helper(maxIdx+1,r,nums);

        return newNode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n-1;

        return helper(l,r,nums);
    }
};