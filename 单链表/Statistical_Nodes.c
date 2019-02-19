
#include "link_head.h"

/* 统计结点  */
typedef unsigned int UINT;
UINT Statistical_Nodes( Node *root )
{
	/* 统计  */
	UINT count = 0;
	while ( NULL != root ) {
		++count; /* 计数  */
		root = root->next;
	}
	return count;
}
