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
    unordered_map<int,int>m;
    int pre = 0;

    TreeNode* build(vector<int>&preorder, vector<int>&inorder, int inL, int inR){
        if(inL > inR){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(preorder[pre]);

        int idx = m[preorder[pre++]];

        newNode->left = build(preorder,inorder,inL,idx-1);
        newNode->right = build(preorder,inorder,idx+1,inR);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        int n = inorder.size();

        return build(preorder,inorder,0,n-1);
    }
};