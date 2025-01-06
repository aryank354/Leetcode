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

    void Leftorder(TreeNode * root , vector<vector<int>>&result){

        if(!root) return ;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<int>currentlevel;
            for(int i = 0 ; i<level ; i++){
                TreeNode * temp = q.front();
                q.pop();

                currentlevel.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            result.push_back(currentlevel);

        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        Leftorder(root , vec);

        return vec;
        
    }
};