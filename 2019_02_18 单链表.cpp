
/* --------------------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h> 
#include <stdlib.h>
/* --------------------------------------------------------------------  */

/* --------------------------------------------------------------------  */
/* 链表结构  */
struct Node {
	int data;          /* 数据域  */
	struct Node *next; /* 指针域  */
};
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 函数原型  */
struct Node *createList( void );                            /* 创建链表  */
struct Node *createNode( int data );                        /* 创建结点  */
void insertNodeByHead( struct Node *headNode, int data );   /* 插入结点  */
void deleteNodeByAppoin( struct Node *headNode, int data ); /* 删除结点  */
void printList( struct Node *headNode );                    /* 打印结点  */
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
int main( int argc, char **argv )
{
	struct Node *list = createList();
	insertNodeByHead( list, 1 );
	insertNodeByHead( list, 2 );
	insertNodeByHead( list, 3 );
	insertNodeByHead( list, 4 );
	deleteNodeByAppoin( list, 2 );
	printList( list );

	system("pause");
	return 0;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 创建链表  */
struct Node *createList( void ) {
	struct Node *headNode = ( struct Node * )malloc( sizeof( struct Node ) );
	headNode->next        = NULL;
	return headNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 创建结点  */
struct Node *createNode( int data ) {
	/* 为结点分配一块指向内存的空间  */
	struct Node *newNode = ( struct Node * )malloc( sizeof( struct Node ) );
	newNode->data        = data; /* 初始化数据域  */
	newNode->next        = NULL; /* 初始化指针域  */
	return newNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 插入结点  */
void insertNodeByHead( struct Node *headNode, int data ) {
	struct Node *newNode = createNode( data ); /* 调用 createNode() 函数传入形参 data 创建链表结点  */
	newNode->next        = headNode->next;     /* 内存指向从头结点开始  */
	headNode->next       = newNode;            /* 保存结点值  */
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 删除结点  */
void deleteNodeByAppoin( struct Node *headNode, int data ) {
	struct Node *frontPosNode = headNode;
	struct Node *posNode      = headNode->next;
	
	/* 如果结点不等于头指针指向的值, （ 下同 ）  */
	while ( data != posNode->data ) {
		frontPosNode = posNode;            /* 每次循环将地址改成下一个  */
		posNode      = frontPosNode->next; /* 保存第一个结点的地址      */
		/* 如果第一个结点值为空, break  */
		if ( NULL == posNode )
			break;
	}
	
	/* 如果头指针指向的地址为空, 无信息, 否则（ 下同 ）  */
	if ( NULL == posNode ) {
		puts( "未找到信息!" );
		system("pause");
		return ;
	}
	else {
		frontPosNode->next = posNode->next; /* 保存第一个结点的地址  */
		free( posNode );                    /* 清除结点值            */
	}
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 打印结点（ 反向打印 ）  */
void printList( struct Node *headNode ) {
	struct Node *pMove = headNode->next;
	/* 从头结点开始遍历  */
	while ( pMove ) {
		printf( "%d-->", pMove->data );
		pMove = pMove->next; /* 将地址改成下一个  */
	}
	putchar( '\n' );
}
/* --------------------------------------------------------------------  */

