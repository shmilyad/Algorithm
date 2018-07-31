/***********************
* 7/31
************************/

// 合并有序链表
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)    return pHead2;
        if (pHead2 == NULL)    return pHead1;
        ListNode* tmp = new ListNode(0);
        ListNode* head = tmp;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        
        while (cur1 != NULL && cur2 != NULL) {
            if (cur1->val < cur2->val) {
                tmp->next = cur1;
                cur1 = cur1->next;
            }
            else {
                tmp->next = cur2;
                cur2 = cur2->next;
            }
            tmp = tmp->next;
        }
        
        if (cur1 != NULL)
            tmp->next = cur1;
        if (cur2 != NULL)
            tmp->next = cur2;
        
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};

// 复杂链表复制
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;

        // 扩充
        RandomListNode* cur = pHead;
        while (cur != NULL) {
            RandomListNode* next = cur->next;
            RandomListNode* list2 = new RandomListNode(cur->label);
            cur->next = list2;
            list2->next = next;
            cur = next;
        }
        // 拷贝随机
        cur = pHead;
        while (cur != NULL) {
            RandomListNode* cur2 = cur->next;
            if (cur->random != NULL) {
                cur2->random = cur->random->next;
            }
            cur = cur2->next;
        }
        // 断开
        cur = pHead;
        RandomListNode* head = cur->next;
        RandomListNode* cur2 = head;
        while (cur != NULL) {
            cur ->next = cur2->next;
            if (cur -> next != NULL)
                cur2->next = cur->next->next;
            cur = cur->next;
            cur2 = cur2->next;
        }
        return head;
    }
};