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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ret;
        if(!root)return ret;
        queue<TreeNode*> q;
        int n;
        TreeNode* _tn;
        q.push(root);
        while(!q.empty())
        {
            n = q.size();
            vector<int> temp;
            ret.push_back(temp);
            for(int i = 0;i < n;i++)
            {
                _tn = q.front();
                q.pop();
                ret.back().push_back(_tn->val);
                if(_tn->left)q.push(_tn->left);
                if(_tn->right)q.push(_tn->right);
            }
        }
        return ret;
    }
};