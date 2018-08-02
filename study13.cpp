/*****************************
* 8/2
*****************************/
// 搜素二叉树转双向链表
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
    void _Convert(TreeNode* cur,TreeNode*& prev)
    {
        if (cur == NULL)
            return;
        _Convert(cur->left,prev);
        cur->left = prev;
        if (prev != NULL)
            prev->right = cur;
        prev = cur;
        _Convert(cur->right,prev);
        
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        
        TreeNode* head = pRootOfTree;
        while (head->left != NULL) // 最左节点是新链表的头节点
            head = head->left;
        TreeNode* prev = NULL;
        _Convert(pRootOfTree,prev);
        return head;
    }
};
// 不带环链表的公共节点
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
       ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};