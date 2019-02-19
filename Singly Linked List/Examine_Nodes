
#include "link_head.h"

/* 检查结点是否重复  */
bool Examine_Nodes( Node *root, int val ) 
{
	Node *curr = root;      /* 保存 root 值  */
	while ( NULL != curr ) {
		/* 如果输入数据与 curr 指向数据不匹配, 每次遍历将地址改成下一个; 
		 * 如果匹配, 那么 break  
		 */
		if ( val != curr->data )
			curr = curr->next;
		else
			break;
	}

	if ( NULL == curr )
		return TRUE;   /* 输入数据没有与表中数据重复, 返回一个真值（ TRUE ）  */
	else
		return FALSE;  /* 输入数据与表中数据重复, 返回一个假值（ FALSE ）  */
}
