
/* --------------------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h>
#include <stdlib.h> 
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 链表结构  */
struct Node {
	int data;           /* 数据域  */
	struct Node *front; /* 前驱指针  */
	struct Node *tail;  /* 后继指针  */
};
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 函数原型  */
struct Node *createList( void );                      /* 创建链表        */
struct Node *createNode( int data );                  /* 创建结点        */
void insertNodeByHead( struct Node *list, int data ); /* 插入结点        */
void printOrderList( struct Node *list );             /* 前向打印结点    */
void printReverseList( struct Node *list );           /* 反向打印结点    */
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 主测试  */
int main( int argc, char **argv )
{
	struct Node *list = createList();
	insertNodeByHead( list, 1 );
	insertNodeByHead( list, 2 );
	insertNodeByHead( list, 3 );
	deleteNodeByAppoin( list, 2 );
	printOrderList( list );
	printReverseList( list );
	
	system("pause");
	return 0;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 创建链表  */
struct Node *createList( void ) {
	struct Node *headNode = ( struct Node * )malloc( sizeof( struct Node ) );
	headNode->front = headNode->tail = NULL;
	return headNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 创建结点  */
struct Node *createNode( int data ) {
	struct Node *newNode = ( struct Node * )malloc( sizeof( struct Node ) );
	newNode->data  = data;                 /* 初始化数据域  */
	newNode->front = newNode->tail = NULL; /* 初始化指针域  */
	return newNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 插入结点  */
void insertNodeByHead( struct Node *list, int data ) {
	/* 调用 createNode() 函数传入形参 data 创建链表结点  */
	struct Node *newNode = createNode( data );

	/* 头结点指向的地址不为空, （ 下同 ）  */
	if ( NULL != list->tail ) {
		newNode->tail     = list->tail; /* 内存指向从头结点开始    */
		list->tail->front = newNode;    /* 尾部保存上一指向结点值  */
	} /* 为空, 什么也不做  */
	else ;

	list->tail     = newNode; /* 保存后继指针指向的结点值  */
	newNode->front = list;    /* 保存前驱指针指向的结点值  */
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 前向打印结点  */
void printOrderList( struct Node *list ) {
	struct Node *pMove = list->tail;
	/* 从头结点开始遍历  */
	while ( pMove ) {
		printf( "%d-->", pMove->data );
		pMove = pMove->tail;
	}
	putchar( '\n' );
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* 反向打印结点  */
void printReverseList( struct Node *list ) {
	struct Node *pMove = list->tail;
	/* 反向开始遍历  */
	while ( pMove->tail )
		pMove = pMove->tail; /* 每次遍历将地址改成下一个  */
	/* pMove 指向的地址不等于链表 list, （ 下同 ）  */
	while ( pMove != list ) {
		printf( "%d-->", pMove->data ); /* 从后往前打印结点值    */
		pMove = pMove->front;           /* 每次遍历将地址往前移  */
	}
	putchar('\n');
}
/* --------------------------------------------------------------------  */

