/***********************
* 7/23
************************/

// 单链表逆置
void Remove(ListNode* head) {
	if (head == NULL)
		return;
	
	int cur = head;
	int prev = NULL;
	int next = head->next;
	
	while (cur != NULL) {
		cur->next = prev;
		prev = cur;
		cur = next;
		next = cur->next;
	}
	
	return;
}