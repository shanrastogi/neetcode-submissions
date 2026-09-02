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
    bool sameTree(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 && root2 && root1->val == root2->val){
            return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
        } else {
            return false;
        }

    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(subroot == NULL)
            return true;
        if(root == NULL)
            return false;
        if(sameTree(root, subroot))
            return true;
        return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);      
    }
};
