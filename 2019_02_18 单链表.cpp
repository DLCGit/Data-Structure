
/* --------------------------------------------------------------------  */
/* ��ؽӿ�  */
#include <stdio.h> 
#include <stdlib.h>
/* --------------------------------------------------------------------  */

/* --------------------------------------------------------------------  */
/* ����ṹ  */
struct Node {
	int data;          /* ������  */
	struct Node *next; /* ָ����  */
};
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ����ԭ��  */
struct Node *createList( void );                            /* ��������  */
struct Node *createNode( int data );                        /* �������  */
void insertNodeByHead( struct Node *headNode, int data );   /* ������  */
void deleteNodeByAppoin( struct Node *headNode, int data ); /* ɾ�����  */
void printList( struct Node *headNode );                    /* ��ӡ���  */
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
/* ��������  */
struct Node *createList( void ) {
	struct Node *headNode = ( struct Node * )malloc( sizeof( struct Node ) );
	headNode->next        = NULL;
	return headNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* �������  */
struct Node *createNode( int data ) {
	/* Ϊ������һ��ָ���ڴ�Ŀռ�  */
	struct Node *newNode = ( struct Node * )malloc( sizeof( struct Node ) );
	newNode->data        = data; /* ��ʼ��������  */
	newNode->next        = NULL; /* ��ʼ��ָ����  */
	return newNode;
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ������  */
void insertNodeByHead( struct Node *headNode, int data ) {
	struct Node *newNode = createNode( data ); /* ���� createNode() ���������β� data ����������  */
	newNode->next        = headNode->next;     /* �ڴ�ָ���ͷ��㿪ʼ  */
	headNode->next       = newNode;            /* ������ֵ  */
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ɾ�����  */
void deleteNodeByAppoin( struct Node *headNode, int data ) {
	struct Node *frontPosNode = headNode;
	struct Node *posNode      = headNode->next;
	
	/* �����㲻����ͷָ��ָ���ֵ, �� ��ͬ ��  */
	while ( data != posNode->data ) {
		frontPosNode = posNode;            /* ÿ��ѭ������ַ�ĳ���һ��  */
		posNode      = frontPosNode->next; /* �����һ�����ĵ�ַ      */
		/* �����һ�����ֵΪ��, break  */
		if ( NULL == posNode )
			break;
	}
	
	/* ���ͷָ��ָ��ĵ�ַΪ��, ����Ϣ, ���� ��ͬ ��  */
	if ( NULL == posNode ) {
		puts( "δ�ҵ���Ϣ!" );
		system("pause");
		return ;
	}
	else {
		frontPosNode->next = posNode->next; /* �����һ�����ĵ�ַ  */
		free( posNode );                    /* ������ֵ            */
	}
}
/* --------------------------------------------------------------------  */


/* --------------------------------------------------------------------  */
/* ��ӡ��㣨 �����ӡ ��  */
void printList( struct Node *headNode ) {
	struct Node *pMove = headNode->next;
	/* ��ͷ��㿪ʼ����  */
	while ( pMove ) {
		printf( "%d-->", pMove->data );
		pMove = pMove->next; /* ����ַ�ĳ���һ��  */
	}
	putchar( '\n' );
}
/* --------------------------------------------------------------------  */

