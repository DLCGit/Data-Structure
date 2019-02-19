
#include "link_head.h"

/* 清理内存  */
void ClearUp_Memory( Node **pHead )
{
    Node *pSave = NULL;          /* 保存 *pHead 下个指向地址  */
    while ( NULL != *pHead ) {
        pSave = ( *pHead )->next; /* 将 *pHead 下个指向保存到 pSave 指针  */
	free( *pHead );          /* 释放链表内存  */
	*pHead = pSave;          /* 链接新的链表  */
    }
}
