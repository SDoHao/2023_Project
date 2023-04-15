
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode()  val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x)  val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode left, TreeNode right)  val(x), left(left), right(right) {}
  };
 
class Solution {
public
    int Height(TreeNode root)
    {
        if(root == nullptr)
            return 0;
        int leftHleight = Height(root-left);
            if(leftHleight==-1)
                return -1;
        int rightHeight = Height(root-right);
            if(rightHeight==-1)
                return -1;
        if(abs(leftHleight - rightHeight)  1)
            return -1;
        return max(leftHleight,rightHeight) + 1;
    }

    bool isBalanced(TreeNode root) 
    {
        
        if(Height(root) != -1) 
            return true;
        else 
            return false;
    }
};