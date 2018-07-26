/**************************
*	7/26
**************************/
// 二叉树中序遍历的下一个节点
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        
        TreeLinkNode* next = NULL;
        // 当前结点的左树和本身以访问
        if (pNode->right != NULL) {  // 右树存在 ，右树最左节点
            TreeLinkNode* cur = pNode->right;
            while (cur->left != NULL) {
                cur = cur->left;
            }
            next = cur;
        } else { // 右树不存在
            TreeLinkNode* parent = pNode->next;
            TreeLinkNode* cur = pNode;
            while (parent != NULL && cur == parent->right) { // 右树代表当前树已经访问完
                cur = parent;
                parent = cur->next;
            }
            next = parent;
        }
        
        return next;
    }
};