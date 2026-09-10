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
    unordered_map<TreeNode*,pair<int,int>>m;

    void dfs(TreeNode*root){
        if(root == NULL){
            m[root] = {0,0};
            return;
        }

        dfs(root->left);
        dfs(root->right);

        m[root] = {(m[root->left].first + m[root->right].first + root->val) , (m[root->left].second + m[root->right].second + 1) };
        return;
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);

        int count = 0;
        for(auto &p : m){
            if(p.first != NULL )cout<<"NODE :"<<p.first->val<<" PAIR"<<p.second.first<<" , "<<p.second.second<<endl;
            if(p.first == NULL || p.second.second == 0) continue;

            if(p.second.first == 0 || p.second.first / p.second.second == p.first->val){
                count++;
            }
        }

        return count;
    }
};