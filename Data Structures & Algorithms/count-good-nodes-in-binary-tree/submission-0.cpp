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
    void solve(TreeNode* root,int maxi,int& count){
        if(root==NULL){
            return;
        }
        if(root->val>=maxi){
            count++;
        }
        maxi = max(maxi, root->val);
        if(root->left){
            solve(root->left,maxi,count);
        }
        if(root->right){
            solve(root->right,maxi,count);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count1=0;
        int count2=0;
        int max1=root->val;
        solve(root->left,max1,count1);
        solve(root->right,max1,count2);
        return count1+count2+1;
    }
};
