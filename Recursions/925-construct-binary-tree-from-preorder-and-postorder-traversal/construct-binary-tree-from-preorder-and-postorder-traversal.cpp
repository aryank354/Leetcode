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
    unordered_map<int, int> postIndexMap; // Stores index of elements in postorder
    int preIndex = 0;

    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]); // Create root node

        if (left == right) return root;  // If leaf node, return it

        int leftSubtreeRootIndex = postIndexMap[preorder[preIndex]]; // Find left subtree root in postorder

        // Recursively construct left and right subtrees
        root->left = construct(preorder, postorder, left, leftSubtreeRootIndex);
        root->right = construct(preorder, postorder, leftSubtreeRootIndex + 1, right - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            postIndexMap[postorder[i]] = i;  // Store index of each element in postorder
        }
        return construct(preorder, postorder, 0, n - 1);
    }
};