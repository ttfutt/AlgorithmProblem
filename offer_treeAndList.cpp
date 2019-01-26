//author : xcj
//date   : 20190126
//problem: 二叉搜索树和双向链表
//method : 二叉搜索树的中序遍历就是有序的，根据中序遍历来构建双向链表即可。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pRootOfList = NULL;
        TreeNode* pTailOfList = NULL;
        ConvertImp(pRootOfTree, pRootOfList, pTailOfList);
        return pRootOfList;
    }
    
    void ConvertImp(TreeNode* p, TreeNode* &pRootOfList, TreeNode* &pTailOfList) {
        if(p == NULL) return;
        ConvertImp(p->left, pRootOfList, pTailOfList);
        TreeNode* pr = p->right;
        if(pRootOfList == NULL) {
            pRootOfList = p;
            pTailOfList = p;
        }
        else {
            pTailOfList->right = p;
            p->left = pTailOfList;
            p->right = NULL;
            pTailOfList = p;
        }
        ConvertImp(pr, pRootOfList, pTailOfList);
    }
};
