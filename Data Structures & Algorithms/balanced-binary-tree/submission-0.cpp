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
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> leftAns=solve(root->left);
        pair<bool,int> rightAns=solve(root->right);
        pair<int,int> ans;
        if(leftAns.first && rightAns.first && abs(leftAns.second-rightAns.second)<=1){
            ans.first=true;
        }else{
            ans.first=false;
        }
        ans.second=max(leftAns.second,rightAns.second)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};
