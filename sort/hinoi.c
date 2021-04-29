#include <stdio.h>
void h(int num, char from, char by, char to){
	if(num == 1){
		print("원반 1을 %c에서 %c로 이동\n", from, to);
	}
	else{
		h(num - 1, from, to, by);
		print("원반 %d을 %c에서 %c로 이동\n", num, from, to);
		h(num - 1, by, from to);

	}
}
