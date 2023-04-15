//需要先创建右子树，再创建左子树
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
    int posti;
    unordered_map<int,int> index;
public:
    TreeNode* make(vector<int>& inorder, vector<int>& postorder,int inst,int ined,int v)
    {
        std::cout<<posti<<' '<<inst<<' '<<ined<<' '<<v<<std::endl;
        if(posti < 0||inst <0 ||ined < 0)
        {
            std::cout<<"-1"<<std::endl;
            //return nullptr;
        }  
        if(inst > ined)
            return nullptr;
        int root_val = postorder[posti];
        int inroot_i = index[root_val];
        posti--;
        TreeNode *root = new TreeNode(root_val);
        root->right = make(inorder,postorder,inroot_i + 1,ined,1);
        root->left = make(inorder,postorder,inst,inroot_i - 1,0);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {   
        posti  = (int)postorder.size() - 1;
        std::cout<<posti<<std::endl;
        int idx = 0;
        for(auto &val:inorder)
            index[val] = idx++;
        return make(inorder,postorder,0,(int)inorder.size() - 1,2);
    }
};