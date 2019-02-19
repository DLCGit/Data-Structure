
#include "link_head.h"

/* 输入结点  */
void Input_Nodes( Node **pHead ) 
{
	root = *pHead;
	Node *curr = NULL; /* 动态分配内存保存新输入的数据  */
	Node *prev = NULL; /* 暂存之前的值  */
	int val;

	printf( "输入一个数: " );
	while ( TRUE == scanf_s( "%d", &val ) )
	{
		/* 读掉多余空白符  */
		while ( '\n' != getchar() )
			continue;

		/* 每次循环输入都为 curr 指针分配一块指向内存的空间存入新输入的数据  */
		curr = ( Node * )malloc( sizeof( Node ) );

		/* 如果 root 为空（ NULL ）, 此时 root 将获得 curr 的内存空间, 否则（ 下同 ）  */
		if ( root == NULL )
			root = curr;
		else /* 将 curr 内存空间作为 prev 指针的下一指向  */
			prev->next = curr;

		curr->next = NULL; /* 将表中连续的 n + 1 个内存空间设置为空 （ NULL ）  */
		curr->data = val;  /* 保存新的值  */

		printf( "再输入一个数: " );
		prev = curr;
	}
}
