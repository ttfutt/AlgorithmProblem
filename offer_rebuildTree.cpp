//author : xcj
//date   : 20190126
//problem: 重建二叉树
//method : 根据先序遍历确定当前节点，然后根据中序遍历划分左右子树。

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
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        TreeNode *root = NULL;
        int i = 0;
        root = buildImp(i, 0, pre.size() - 1, pre, vin);
        return root;
    }
    TreeNode *buildImp(int &i, int l, int r, vector<int> &pre, vector<int> &vin) {
        if(l > r) return NULL;
        int m = -1;
        for(int j = l; j <= r; ++j)
            if(vin[j] == pre[i]) {
                m = j;
                break;
            }
        if(m != -1) {
            TreeNode *pNode = new TreeNode(pre[i++]);
            pNode->left = buildImp(i, l, m-1, pre, vin);
            pNode->right = buildImp(i, m+1, r, pre, vin);
            return pNode;
        }
        return NULL;
    }
};
