

/* ------------------------------------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h>
#include <stdlib.h>
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 相关特殊宏常量  */
/* 哈希函数中的除数, 必须小于等于表长  */
#define TRUE  1
#define FALSE 0
#define M 7

typedef int ElemType;
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 链表结构, 采用链接法解决冲突问题  */
typedef struct Node {
    ElemType data;     /* 数据域  */
    struct Node *next; /* 指针域  */
} Node, *pNode;

/* 每个槽的结构  */
typedef struct HashNode {
    pNode first;       /* 指向链表第一个结点  */
} HashNode, *HashTable;
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 函数原型  */
HashTable create_HashTable( int n );                          /* 创建哈希表               */
pNode search_HashTable( HashTable hashtable, ElemType data ); /* 在哈希表中查找数据        */
bool insert_HashTable( HashTable hashtable, ElemType data );  /* 插入指定数据到哈希表      */
bool delete_HashTable( HashTable hashtable, ElemType data );  /* 从哈希表中删除指定数据    */
void destroy_HashTable( HashTable hashtable, int n );         /* 销毁哈希表               */
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 主测试  */
int main( int argc, char **argv )
{
    int len = 15;                                  /* 哈希表槽数长度  */
    printf( "哈希表槽数长度为: %d \n", len );
    HashTable hashtable = create_HashTable( len ); /* 创建哈希表并插入数据  */
	
    if ( insert_HashTable( hashtable, 1 ) )
	puts( "插入指定数据 1 成功!" );
    else
	puts( "插入指定数据 1 失败, 需要插入的数据在表中已经存在!" );
		
    if ( insert_HashTable( hashtable, 2 ) )
	puts( "插入指定数据 2 成功!" );
    else
	puts( "插入指定数据 2 失败, 需要插入的数据在表中已经存在!" );
		
    if ( insert_HashTable( hashtable, 3 ) )
	puts( "插入指定数据 3 成功!" );
    else
	puts( "插入指定数据 3 失败, 需要插入的数据在表中已经存在!" );
		
    if ( insert_HashTable( hashtable, 0 ) )
	puts( "插入指定数据 0 成功!" );
    else
	puts( "插入指定数据 0 失败, 需要插入的数据在表中已经存在!" );
		
    if ( insert_HashTable( hashtable, 10 ) )
	puts( "插入指定数据 10 成功!" );
    else
	puts( "插入指定数据 10 失败, 需要插入的数据在表中已经存在!" );



    /* 查找指定数据  */
    pNode pFind1 = search_HashTable( hashtable, 4 );
    if ( pFind1 )
	printf( "你要查找的数据为: %d \n", pFind1->data );
    else
	printf( "在表中查找不到 4 这个数据! \n" );
		
    pNode pFind2 = search_HashTable( hashtable, 21 );
    if ( pFind2 )
	printf( "你要查找的数据为: %d \n", pFind2->data );
    else
	printf( "在表中查找不到 21 这个数据! \n" );



    /* 删除指定数据  */
    if ( delete_HashTable( hashtable, 1 ) )
	puts( "删除指定数据 1 成功!" );
    else
	puts( "删除指定数据 1 失败!" );
		
    pNode pFind3 = search_HashTable( hashtable, 1 );
    if ( pFind3 )
        printf( "你要查找的数据为: %d \n", pFind3->data );
    else
	printf( "在表中查找不到这个值, 因为它已经被删除! \n" );


    /* 销毁哈希表  */
    destroy_HashTable( hashtable, len );
	
	
    system("pause");
    return 0;
}
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 创建一个槽数为 n 的哈希表  */
HashTable create_HashTable( int n ) {
    HashTable hashtable = ( HashTable )malloc( n * sizeof( HashNode ) );
    if ( !hashtable ) {
	printf( "为哈希表分配动态内存失败!" );
	exit( -1 );
    }

    /* 将哈希表初始化为 0  */
    for ( int i = 0; n > i; ++i )
	hashtable[ i ].first = NULL;
    
    return hashtable;
}
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 在哈希表中查找指定数据 data , 查找成功返回在链表中的位置,
 * 查找不成功则返回 NULL , 其中哈希槽数为 H( key ) = key % M
 */
pNode search_HashTable( HashTable hashtable, ElemType data ) {
    if ( !hashtable )
	return NULL;

    /* 以下写法包含了成功与不成功两种情况  */
    pNode pCur = hashtable[ data % M ].first;
    while ( pCur && pCur->data != data )
	pCur = pCur->next;
		
    return pCur;
}
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 在哈希表中插入指定数据 data , 如果 data 已存在, 返回 FALSE,
 * 否则插入对应链表的最后则返回 TRUE, 其中哈希槽数为 H( key ) = key % M
 */
bool insert_HashTable( HashTable hashtable, ElemType data ) {
    /* 如果已经存在，返回 FALSE  */
    if ( search_HashTable( hashtable, data ) )
	return FALSE;

    /* 否则为 data 分配一块内存空间  */
    pNode pNew = ( pNode )malloc( sizeof( Node ) );
    if ( !pNew ) {
	printf( "为槽结点分配动态内存失败!" );
	exit( -1 );
    }
    pNew->data = data;
    pNew->next = NULL;

    /* 将结点插入到对应链表的最后  */
    pNode pCur = hashtable[ data % M ].first;
    /* 如果插入的位置为链表第一个结点的情况  */
    if ( !pCur ) 
	hashtable[ data % M ].first = pNew;
    else { /* 否则插入的位置不是链表第一个结点的情况;
	    * 只有使用 pCur->next 才可以将 pNew 结点链接到链表,
	    * 而单单只使用 pCur 那么链接不到链表, 而是链接到了
	    * pCur 上
	    * /
           /* pCur 虽然最终指向链表中某个节点, 但它终究并不在链表中  */
            while ( pCur->next )
		pCur = pCur->next;
	    pCur->next = pNew;
    }

    return TRUE;
}
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 在哈希表中删除指定数据 data , 如果 data 不存在, 则返回FALSE,
 * 否则删除之后并返回 TRUE, 其中哈希表槽数为 H( key ) = key % M
 */
bool delete_HashTable( HashTable hashtable, ElemType data ) {
    /* 如果查找不到, 则返回 FALSE */
    if ( !search_HashTable( hashtable, data ) )
	return FALSE;
		
    /* 否则这个结点一定存在, 找到并将其删除  */
    pNode pCur = hashtable[ data % M ].first;
    pNode pPre = pCur;        /* 被删结点的前一个结点, 初始值与 pCur 相同  */
    if ( pCur->data == data ) /* 如果被删结点是链表第一个结点的情况  */
	hashtable[ data % M ].first = pCur->next;
    else { /* 否则被删结点不是链表第一个结点的情况  */
        while ( pCur && pCur->data != data ) {
	    pPre = pCur;
	    pCur = pCur->next;
	}
	pPre->next = pCur->next;
    }
    free( pCur );
    pCur = 0;
	
    return TRUE;
}
/* ------------------------------------------------------------------------------------  */


/* ------------------------------------------------------------------------------------  */
/* 销毁槽数为 n 的哈希表  */
void destroy_HashTable( HashTable hashtable, int n ) {
    for ( int i = 0; n > i; ++i ) {
	pNode pCur = hashtable[ i ].first;
	pNode pDel = NULL;
	/* 将链表结点逐个释放  */
	while ( pCur ) {
	    pDel = pCur;
	    pCur = pCur->next;
	    free( pDel );
	    pDel = NULL;
	}
    }
    free(hashtable);  /* 最后释放哈希表  */
    hashtable = NULL; /* 将哈希表置为空  */
}
/* ------------------------------------------------------------------------------------  */
