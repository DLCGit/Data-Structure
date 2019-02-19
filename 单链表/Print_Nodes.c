
#include "link_head.h"

/* 打印结点  */
void Print_Nodes( Node *root )
{
    Node *curr = NULL;  /* 保存 root 值  */
    if ( NULL == root ) 
	printf( "表中没有输入过数据!" );

    curr = root;
    while ( NULL != curr ) {
	printf( " %d ", curr->data );
	curr = curr->next; /* 将地址改成下一个  */
    }
    putchar( '\n' );
}
