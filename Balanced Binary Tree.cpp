/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

initial code:
*/

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL)
        return 0;
        int nleft = minDepth(root->left);
        int nright = minDepth(root->right);
        return (nleft<nright)?(nleft+1):(nright+1);
    }
    int maxDepth(TreeNode *root) {
        if (root == NULL)
        return 0;
        int nleft = maxDepth(root->left);
        int nright = maxDepth(root->right);
        return (nleft>nright)?(nleft+1):(nright+1);
    }
    bool isBalanced(TreeNode *root) {
        int maxed = maxDepth(root);
        int mined = minDepth(root);
        if (abs(maxed - mined)<= 1) return true;
        else return false;
    }
};

/*
This is the answer for Cracking the Code 4.1
This won't work. Because of the definition of BALANCED here is not defined by all the node differs in depth less than or equal to 1. But is defined the difference of max depth of left tree and right tree are less than or equal to 1.

The key idea is from the 4.1, where compute the max and min depth of the whole tree and see the difference. Here, we compute the max depth of two sub tree of a node, if the difference is > 1, output false.

Code below: 
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
        return 0;
        int nleft = maxDepth(root->left);
        int nright = maxDepth(root->right);
        return (nleft>nright)?(nleft+1):(nright+1);
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (abs(left - right)> 1) return false;
        //else return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};
