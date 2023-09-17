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
class Solution 
{
public:
    void MakePre(TreeNode* root)
    {
        if(!root)
            return;
        TreeNode * right = root -> right;
        TreeNode * t;
        if(root -> left)
        {
            root -> right = root ->left;
            t = root -> left;
            while(t->right!=nullptr)
                t = t->right;
            t -> right = right;
            root ->left = nullptr;
        }
        MakePre(root->right);
    }
    void flatten(TreeNode* root) 
    {
        MakePre(root);
    }
};