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
    void solve(TreeNode* root){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->left!=NULL && root->right==NULL){
            root->right=root->left;
            root->left=NULL;
        }else if(root->right!=NULL && root->left==NULL){
            root->left=root->right;
            root->right=NULL;
        }else{
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        if(root->left){
            solve(root->left);
        }
        if(root->right){
            solve(root->right);      
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
