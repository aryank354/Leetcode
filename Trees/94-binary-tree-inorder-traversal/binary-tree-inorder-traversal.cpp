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
    void Inorder(TreeNode * root , vector<int> & vec){
        if(!root){
            return;
        }

        Inorder(root->left , vec);
        vec.push_back(root->val);
        Inorder(root->right , vec);
    }


    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>vec;
        Inorder(root , vec);

        return vec;
        
    }
};