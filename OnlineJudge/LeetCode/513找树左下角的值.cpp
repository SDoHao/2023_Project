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
    int BFS(TreeNode* root)
    {
        int val;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * top_tn;
        int n;
        while(!q.empty())
        {
            n = q.size();
            top_tn = q.front();
            val = top_tn->val;
            for(int i = 0;i < n;i++)
            {
                top_tn = q.front();
                q.pop();
                if(top_tn->left)
                    q.push(top_tn->left);
                if(top_tn->right)
                    q.push(top_tn->right);
            }
        }
        return val;
    }


    int findBottomLeftValue(TreeNode* root) 
    {
        return BFS(root);
    }
};