
#include <stdio.h>
#include <stdlib.h>
#define NUL 0


/* -------------------------------------------------------------------------  */
/* ����ԭ��  */
void dataInput( int *start, int *end, int& len );            /* ��������      */
void leftShift( int *start, int *end, int& len );            /* ��������λ    */
void rightShift( int *start, int *end, int& len );           /* ��������λ    */
void print_LeftShift_Result( int cur, int& len, int *end );  /* ��ӡ���ƽ��  */
void print_RightShift_Result( int cur, int& len, int *end ); /* ��ӡ���ƽ��  */
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* ������  */
int main( int argc, char **argv )
{
	int *len = new int, *start = NUL, *end = NUL;
	dataInput( start, end, *len );
	
	system("pause");
	return 0;
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* ��������  */
void dataInput( int *start, int *end, int& len ) {
	printf( "�����������: " );
	scanf( "%d", &len );
	
	start = ( int * )malloc( len * sizeof( int ) );
	end   = ( int * )malloc( len * sizeof( int ) );
	
	printf( "�ֱ��Կո������� %d ����ʮ����������ɵ�����Ԫ��: ", len );
	for( int i = 0; len > i; ++i )
		scanf( "%d", &start[ i ] );
		
	leftShift( start, end, len );
	putchar( '\n' );
	rightShift( start, end, len );
	
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* ����  */
void leftShift( int *start, int *end, int& len ) {
	for( int cur = 0; ( len ) > cur; ++cur ) {
		for( int j = 0; ( len - cur ) > j; ++j )
			end[ j ] = start[ cur + j ];

		for( int k = 0, tmp = ( len - cur ); len > tmp; ++k, ++tmp )
			end[ tmp ] = start[ k ];

		printf( "���� %d λ����: ", cur );
		print_LeftShift_Result( cur, len, end );
	}
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* ����   */
void rightShift( int *start, int *end, int& len ) {
	for( int cur = 0; ( len ) > cur; ++cur ) {
		for( int j = 0; ( len - cur ) > j; ++j )
			end[ cur + j ] = start[ j ];
			
		for( int k = 0, tmp = ( len - cur ); len > tmp; ++k, ++tmp )
			end[ k ] = start[ tmp ];
			
		printf( "���� %d λ����: ", cur );
		print_RightShift_Result( cur, len, end );
	}
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* ��ӡ���ƽ��   */
void print_LeftShift_Result( int cur, int& len, int *end ) {
	for( int rslt = 0; len > rslt; ++rslt )
		printf( "%-3d", end[ rslt ] );
	printf( "\n" );
}
/* -------------------------------------------------------------------------  */


/* -------------------------------------------------------------------------  */
/* ��ӡ���ƽ��   */
void print_RightShift_Result( int cur, int& len, int *end ) {
	for( int rslt = 0; len > rslt; ++rslt )
		printf( "%-3d", end[ rslt ] );
	printf( "\n" );
}
/* -------------------------------------------------------------------------  */

