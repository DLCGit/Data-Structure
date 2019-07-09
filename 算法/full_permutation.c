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
void DFS(_cst uint_fast32_t _cst step, _cst uint_fast32_t _cst size, 
	_cst uint_fast32_t _cst state, _cst uint_fast32_t _cst all) { 
	if (state != all) { 
		uint_fast32_t getn; 
		for (getn = (~state) & all; getn; true) { 
			uint_fast32_t findrn; 
			findrn = getn & (-getn), getn -= findrn; 
			base[ step ] = hash[ findrn % 37 ]; 
			DFS(step + 1, size, state + findrn, all); 
		}
	} else {
		uint_fast32_t i;
		for (i = 1; i < size; PF("%d", base[ i++ ])); 
		PF("%d\n", base[ size ]);  
	} 
} 

int main( ) { 
	const uint_fast32_t step = 1; 
	const uint_fast32_t state = 0; 
	int32_t n; 
	while (~SF("%d", &n) && n) { 
		uint_fast32_t i; 
		for (i = 0; i < n; ++i) hash[ (1 << i) % 37 ] = i + 1; 
		uint_fast32_t all = (1 << n) - 1; 
		DFS(step, n, state, all);
	} 
	return 0;
}
