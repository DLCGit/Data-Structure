
#ifndef __link_head_H__
#define __link_head_H__

/* ----------------------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
/* ----------------------------------------------------------------------  */


/* ----------------------------------------------------------------------  */
/* 相关特殊宏常量  */
#define TRUE  1
#define FALSE 0
/* ----------------------------------------------------------------------  */


/* ----------------------------------------------------------------------  */
/* 单链表结构  */
typedef struct node{
	int data;         /* 数据域  */
	struct node *next; /* 指针域  */
} Node;
extern Node *root;    /* 该 *root 变量应用于多个文件当中, 它不是一个指针  */
/* ----------------------------------------------------------------------  */


/* ----------------------------------------------------------------------  */
/* 函数原型  */
void Input_Nodes(Node **);               /* 输入结点                        */
bool Examine_Nodes(Node *root, int val); /* 检查结点是否重复                 */
bool Insert_Nodes(Node **, int);         /* 添加结点                        */
void Delete_Nodes(Node **, int);         /* 删除结点                        */
void Sorting_Nodes(Node *);              /* 排序结点                        */
void Print_Nodes(Node *);                /* 打印结点                        */
void ClearUp_Memory(Node **);            /* 清理内存                        */
unsigned int Statistical_Nodes(Node *);  /* 统计结点                        */
/* ----------------------------------------------------------------------  */

#endif
