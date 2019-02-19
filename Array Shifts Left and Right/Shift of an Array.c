
/* -------------------------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h>
#include <stdlib.h>
#define NUL 0
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 函数原型  */
void dataInput( int *start, int *end, int& len );            /* 输入数据      */
void leftShift( int *start, int *end, int& len );            /* 数组左移位    */
void rightShift( int *start, int *end, int& len );           /* 数组右移位    */
void print_LeftShift_Result( int cur, int& len, int *end );  /* 打印左移结果  */
void print_RightShift_Result( int cur, int& len, int *end ); /* 打印右移结果  */
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 主测试  */
int main( int argc, char **argv )
{
    int *len = new int, *start = NUL, *end = NUL;
    dataInput( start, end, *len );
	
    system("pause");
    return 0;
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 数据输入  */
void dataInput( int *start, int *end, int& len ) {
    printf( "输入数组个数: " );
    scanf( "%d", &len );
	
    start = ( int * )malloc( len * sizeof( int ) );
    end   = ( int * )malloc( len * sizeof( int ) );
	
    printf( "分别以空格间隔输入 %d 个以十进制数组组成的数组元素: ", len );
    for( int i = 0; len > i; ++i )
        scanf( "%d", &start[ i ] );
		
    leftShift( start, end, len );
    putchar( '\n' );
    rightShift( start, end, len );
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 左移  */
void leftShift( int *start, int *end, int& len ) {
    for( int cur = 0; ( len ) > cur; ++cur ) {
	for( int j = 0; ( len - cur ) > j; ++j )
	    end[ j ] = start[ cur + j ];

	for( int k = 0, tmp = ( len - cur ); len > tmp; ++k, ++tmp )
	    end[ tmp ] = start[ k ];

	printf( "左移 %d 位后结果: ", cur );
	print_LeftShift_Result( cur, len, end );
    }
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 右移   */
void rightShift( int *start, int *end, int& len ) {
    for( int cur = 0; ( len ) > cur; ++cur ) {
	for( int j = 0; ( len - cur ) > j; ++j )
            end[ cur + j ] = start[ j ];
			
        for( int k = 0, tmp = ( len - cur ); len > tmp; ++k, ++tmp )
	    end[ k ] = start[ tmp ];
			
	printf( "右移 %d 位后结果: ", cur );
	print_RightShift_Result( cur, len, end );
    }
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 打印左移结果   */
void print_LeftShift_Result( int cur, int& len, int *end ) {
    for( int rslt = 0; len > rslt; ++rslt )
	printf( "%-3d", end[ rslt ] );
    printf( "\n" );
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* 打印右移结果   */
void print_RightShift_Result( int cur, int& len, int *end ) {
    for( int rslt = 0; len > rslt; ++rslt )
	printf( "%-3d", end[ rslt ] );
    printf( "\n" );
}
/* -------------------------------------------------------------------------  */
