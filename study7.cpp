/****************************
*  7/23
*****************************/
typedef struct ListNode{
	int val;
	stuct ListNode* next;
	
	ListNode(int x) {
		val = x;
		next = NULL;
	}
}ListNode*;

// 从尾到头打印单链表
vector<int> PrintRemoveList(ListNode* head) {
	vector<int> ret;
	if (head == NULL )
		return ret;
	
	stack<ListNode*> s;
	ListNode* cur = head;
	while (cur != NULL) {
		s.push(cur);
		cur = cur->next;
	}
	while (!s.empty()) {
		ListNode* top = s.top();
		ret.push_back(top->val);
		s.pop();
	}
	
	return ret;
}