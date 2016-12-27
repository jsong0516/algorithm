#include <stdio.h>

void test(int *&a, int *&b) {
	printf("%d\n", a[0] + b[1]);
}

int main(void) {
	int *a = new int[10];
	int *b = new int[30];
	a[0] = 100;
	b[1] = 200;
	test(a,b);
	return 1;
}