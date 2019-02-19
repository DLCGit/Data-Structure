
#include "link_head.h"

/* 删除结点  */
void Delete_Nodes( Node **pHead, int del_By_Val )
{
	Node *prev = NULL; /* 保存上一个值  */
	Node *next = NULL; /* 保存下一个值  */
	Node *curr = NULL; /* 保存 *pHead 值  */

	curr = *pHead;
	while ( del_By_Val != curr->data ) {
		prev = curr;      /* 将 curr 值保存到 prev 指针  */
		curr = curr->next; /* 将 curr 地址指向改成下一个  */
		next = curr->next; /* 将 curr 新指向地址保存到 next 指针  */
	}

	if ( NULL == prev )
		curr = next;      /* 将 curr 地址指向改成下一个  */
	else
		prev->next = next; /* 将新指向的地址保存到 *pHead 地址  */
	free( curr );  /* 释放删除的内存空间  */
}
