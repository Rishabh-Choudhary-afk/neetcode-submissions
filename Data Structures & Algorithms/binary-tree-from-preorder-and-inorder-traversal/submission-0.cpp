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
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &idx,int inStart, int inEnd,unordered_map<int,int> &m){
        if(idx>=inorder.size() || inStart>inEnd){
            return NULL;
        }
        int ele=preorder[idx++];
        TreeNode* root=new TreeNode(ele);
        int posi=m[ele];
        root->left=solve(inorder,preorder,idx,inStart,posi-1,m);
        root->right=solve(inorder,preorder,idx,posi+1,inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0){
            return NULL;
        }
        int idx=0;
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(inorder,preorder,idx,0,inorder.size()-1,m);
    }
};
