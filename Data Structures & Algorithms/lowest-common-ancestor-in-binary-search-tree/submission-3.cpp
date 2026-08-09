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
    void createMap(TreeNode* root,map<TreeNode*,TreeNode*>& nodeToParent){
        if(root==NULL){
            return;
        }
        if(root->left){
            nodeToParent[root->left]=root;
            createMap(root->left,nodeToParent);
        }
        if(root->right){
            nodeToParent[root->right]=root;
            createMap(root->right,nodeToParent);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        map<TreeNode*,int> visited;
        map<TreeNode*,TreeNode*> nodeToParent;
        createMap(root,nodeToParent);
        nodeToParent[root] = NULL;
        while(p){
            visited[p]=1;
            p=nodeToParent[p];
        }
        while(q){
            if(visited[q]==1){
                return q;
            }
            q=nodeToParent[q];
        }
        return NULL;
    }
};
