
#include "link_head.h"

/* 排序结点  */
void Sorting_Nodes( Node *root )
{
    /* 冒泡排序法  */
    for ( Node *p_i = root; NULL != p_i->next; p_i = p_i->next ) {
	for ( Node *p_j = root; NULL != p_j->next; p_j = p_j->next ) {
	    if ( p_j->data > p_j->next->data ) {
		int tmp        = p_j->data;
		p_j->data      = p_j->next->data;
		p_j->next->data = tmp;
	    }
	}
    }
}
