
/* ---------------------------------------------------------------------------------------------  */
#include "construction.h"
/* ---------------------------------------------------------------------------------------------  */

int main( int argc, char **argv )
{
	Graph Gp = create_graph(); /* 创建图  */

	/* 深度优先  */
	printf( "对图进行深度优先遍历: \n" );

	printf( "从顶点A出发DFS的结果: " );
	DFS_traverse( Gp, 0 );
	printf( "\n" );

	printf( "从顶点H出发DFS的结果: " );
	DFS_traverse( Gp, 7 );
	printf( "\n" );

	printf( "从顶点E出发DFS的结果: " );
	DFS_traverse( Gp, 4 );
	puts( "\n" );


	/* 广度优先  */
	printf( "对图进行广度优先遍历: \n" );

	printf( "从顶点A出发BFS的结果: " );
	BFS_traverse( Gp, 0 );
	printf( "\n" );

	printf( "从顶点H出发BFS的结果: " );
	BFS_traverse( Gp, 7 );
	printf( "\n" );

	printf( "从顶点E出发BFS的结果: " );
	BFS_traverse( Gp, 4 );
	printf( "\n" );


	/* 释放掉每个单链表所分配的内存  */
	for ( int i = 0; VERTEXMAXSIZE > i; ++i ) {
		free( Gp[ i ].first );
		Gp[ i ].first = 0;    /* 防止悬垂指针产生  */
	}


	/* 释放掉顶点数组所分配的内存  */
	free( Gp );
	Gp = 0;

	system("pause");
	return 0;
}
