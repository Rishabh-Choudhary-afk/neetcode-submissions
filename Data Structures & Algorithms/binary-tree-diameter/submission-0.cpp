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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> leftAns=solve(root->left);
        pair<int,int> rightAns=solve(root->right);
        int op1=leftAns.first;
        int op2=rightAns.first;
        int op3=leftAns.second+rightAns.second;
        int h=max(leftAns.second,rightAns.second)+1;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=h;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};
