
/* --------------------------------------------------------------------  */
/* ��ؽӿ�  */
#include <stdio.h>
#include <stdlib.h> 
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ����ṹ  */
struct Node {
	int data;           /* ������  */
	struct Node *front; /* ǰ��ָ��  */
	struct Node *tail;  /* ���ָ��  */
};
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ����ԭ��  */
struct Node *createList( void );                      /* ��������        */
struct Node *createNode( int data );                  /* �������        */
void insertNodeByHead( struct Node *list, int data ); /* ������        */
void printOrderList( struct Node *list );             /* ǰ���ӡ���    */
void printReverseList( struct Node *list );           /* �����ӡ���    */
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ������  */
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
/* ��������  */
struct Node *createList( void ) {
	struct Node *headNode = ( struct Node * )malloc( sizeof( struct Node ) );
	headNode->front = headNode->tail = NULL;
	return headNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* �������  */
struct Node *createNode( int data ) {
	struct Node *newNode = ( struct Node * )malloc( sizeof( struct Node ) );
	newNode->data  = data;                 /* ��ʼ��������  */
	newNode->front = newNode->tail = NULL; /* ��ʼ��ָ����  */
	return newNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ������  */
void insertNodeByHead( struct Node *list, int data ) {
	/* ���� createNode() ���������β� data ����������  */
	struct Node *newNode = createNode( data );

	/* ͷ���ָ��ĵ�ַ��Ϊ��, �� ��ͬ ��  */
	if ( NULL != list->tail ) {
		newNode->tail     = list->tail; /* �ڴ�ָ���ͷ��㿪ʼ    */
		list->tail->front = newNode;    /* β��������һָ����ֵ  */
	} /* Ϊ��, ʲôҲ����  */
	else ;

	list->tail     = newNode; /* ������ָ��ָ��Ľ��ֵ  */
	newNode->front = list;    /* ����ǰ��ָ��ָ��Ľ��ֵ  */
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ǰ���ӡ���  */
void printOrderList( struct Node *list ) {
	struct Node *pMove = list->tail;
	/* ��ͷ��㿪ʼ����  */
	while ( pMove ) {
		printf( "%d-->", pMove->data );
		pMove = pMove->tail;
	}
	putchar( '\n' );
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* �����ӡ���  */
void printReverseList( struct Node *list ) {
	struct Node *pMove = list->tail;
	/* ����ʼ����  */
	while ( pMove->tail )
		pMove = pMove->tail; /* ÿ�α�������ַ�ĳ���һ��  */
	/* pMove ָ��ĵ�ַ���������� list, �� ��ͬ ��  */
	while ( pMove != list ) {
		printf( "%d-->", pMove->data ); /* �Ӻ���ǰ��ӡ���ֵ    */
		pMove = pMove->front;           /* ÿ�α�������ַ��ǰ��  */
	}
	putchar('\n');
}
/* --------------------------------------------------------------------  */

