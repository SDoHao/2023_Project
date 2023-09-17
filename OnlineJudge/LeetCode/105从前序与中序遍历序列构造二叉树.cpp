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
private:
    unordered_map<int,int> index;
public:
    TreeNode* make(vector<int>& preorder, vector<int>& inorder,int prest,int preed,int inst,int ined)
    {
        if(prest>preed)
            return nullptr;
        int preroot = prest;
        int inroot = index[preorder[prest]];
        int left_size = inroot - inst;
        TreeNode * root = new TreeNode(preorder[prest]);
        root->left = make(preorder, inorder, prest + 1,prest + left_size,inst,inroot - 1);
        root->right = make(preorder, inorder, prest + left_size + 1,preed ,inroot + 1,ined);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0;i < n;i++)
            index[inorder[i]] = i;
        return  make(preorder,inorder,0,n - 1,0,n - 1);
    }
};