#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void input(const int const *s, const int const *e, const int const n) {
    printf("分别以空格间隔输入 %d 个以十进制数组组成的数组元素: ", n);
    int i;
    for (i = 0; i < n; scanf("%d", &s[ i++ ])); 
}

void print(int cur, const int const *e, const int const n) { 
    for (cur = 0; cur < n; printf("%-3d", e[ cur++ ])); 
    printf( "\n" );
}

static void leftShift(const int const *s, int *e, const int const n) {
    int i, j, k, tmp;
	for (i = 0; i < n; ++i) { 
		for (j = 0; j < (n - i); ++j) e[ j ] = s[ i + j ];
		for (k = 0, tmp = (n - i); tmp < n; ++tmp, ++k) e[ tmp ] = s[ k ];
		printf("左移 %d 位后结果: ", i);
		print(i, e, n);
    }
}

static void rightShift(const int const *s, int *e, const int const n) {
    int i, j, k, tmp;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n - i; ++j) e[ i + j ] = s[ j ];
        for (k = 0, tmp = (n - i); tmp < n; ++tmp, ++k) e[ k ] = s[ tmp ];
		printf("右移 %d 位后结果: ", i);
		print(i, e, n);
    }
}

int main( ) {
	int len; printf("输入数组个数: "); scanf("%d", &len); assert(len != 0);
    int start[ len ], end[ len ]; assert(start != 0 && end != 0);
    input(start, end, len);
    leftShift(start, end, len); printf("\n");
    rightShift(start, end, len);printf("\n"); 
    return 0;
}
