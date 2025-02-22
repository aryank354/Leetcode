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
TreeNode* recoverFromPreorder(string traversal) {
    stack<TreeNode*> st;
    int i = 0, n = traversal.size();
    
    while (i < n) {
        int depth = 0;
        while (i < n && traversal[i] == '-') {
            depth++;
            i++;
        }
        
        int value = 0;
        while (i < n && isdigit(traversal[i])) {
            value = value * 10 + (traversal[i] - '0');
            i++;
        }
        
        TreeNode* node = new TreeNode(value);
        
        
        while (st.size() > depth) {
            st.pop();
        }
        
        if (!st.empty()) {
            if (!st.top()->left)
                st.top()->left = node;
            else
                st.top()->right = node;
        }
        
        st.push(node);
    }
    
    while (st.size() > 1) {
        st.pop();
    }
    
    return st.top();
}
};