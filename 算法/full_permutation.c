#include <stdio.h> 
#include <stdint.h> 
#define SF(...) scanf (__VA_ARGS__) 
#define PF(...) printf(__VA_ARGS__) 
#define maxn 31 
#define _cst const 
#define bool int 
#define true 1
#define false 0

int base[ maxn << 1 ], hash[ maxn << 1 ]; 
int cnt; 
void DFS(_cst uint_fast32_t _cst step, _cst uint_fast32_t _cst size, _cst uint_fast32_t _cst state, _cst uint_fast32_t _cst all) { 
	if (state != all) { 
		uint_fast32_t getn, findrn; 
		for (getn = (~state) & all; getn; true) {    // 获得所有数 
			findrn = getn & (-getn), getn -= findrn; // 获得右边位置数, 将其取出来 
			base[ step ] = hash[ findrn % 37 ];      // 保留当前数的位置 
			DFS(step + 1, size, state + findrn, all); 
		}
	} else {
		uint_fast32_t i;
		for (i = 1; i < size; PF("%d", base[ i++ ])); 
		PF("%d\n", base[ size ]); 
		cnt++; 
	} 
} 

int main( ) { 
	const uint_fast32_t step = 1; 
	const uint_fast32_t state = 0; 
	int32_t n; 
	while (~SF("%d", &n) && n) { 
		cnt = 0; 
		uint_fast32_t i; 
		for (i = 0; i < n; ++i) hash[ (1 << i) % 37 ] = i + 1; // 创建哈希表 
		uint_fast32_t all = (1 << n) - 1;                      // 将 n 全部对应二进制位置 1 
		DFS(step, n, state, all), PF("%d\n", cnt);
	} 
	return 0;
}
