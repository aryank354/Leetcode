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
    void Preorder(TreeNode* root , vector<int>&vec){
        if(!root){
            return;
        }

        vec.push_back(root->val);
        Preorder(root->left , vec);
        Preorder(root->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>preorder;

        Preorder(root , preorder);

        return preorder;
        
    }
};