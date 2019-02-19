
#include "link_head.h"

/* 添加结点  */
bool Insert_Nodes( Node **pHead, int new_val )
{
    Node *new_N = NULL; /* 保存新插入的数据  */
    Node *prev  = NULL; /* 保存上一个值  */
    Node *curr  = NULL; /* 保存 *pHead 值  */

    curr = *pHead;
    /* curr 内存不为空 and 新插入的值不小于头结点指向的值, （ 下同 ）  */
    while ( ( NULL != curr ) and ( new_val > curr->data ) ) {
	prev = curr;      /* 将 curr 值暂存到 prev 指针  */
	curr = curr->next; /* 将 curr 地址改成下一个  */
    }

    /* 为 new_N 指针分配一块指向内存的空间存入新插入的数据  */
    new_N = ( Node * )malloc( sizeof( Node ) );
    if ( NULL == new_N )
	return FALSE;
    new_N->data = new_val; /* 保存新插入的值  */
    new_N->next = curr;    /* 保存 curr（ *pHead ） 地址  */

    if ( NULL == prev ) 
	*pHead = new_N;   /* 保存新的值到 *pHead 地址  */
    else
	prev->next = new_N; /* 将新值保存到 prev   */

    return TRUE;
}
