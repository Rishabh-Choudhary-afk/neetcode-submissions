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
    bool solve(TreeNode* p, TreeNode* q){
        queue<pair<TreeNode*,TreeNode*>> pq;
        pq.push(make_pair(p,q));
        
        while(!pq.empty()){
            TreeNode* a=pq.front().first;
            TreeNode* b=pq.front().second;
            pq.pop();
            if(a->val!=b->val){
                return false;
            }
            if(a->left && b->left){
                pq.push(make_pair(a->left,b->left));
            }
            if(a->left && b->left==NULL){
                return false;
            }
            if(a->left==NULL && b->left){
                return false;
            }
            if(a->right==NULL && b->right){
                return false;
            }
            if(a->right && b->right==NULL){
                return false;
            }
            if(a->right && b->right){
                pq.push(make_pair(a->right,b->right));
            }
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;

        if(p == NULL || q == NULL)
            return false;
        return solve(p,q);
    }
};
