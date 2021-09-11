#include <stdio.h>
#include <stdlib.h>

int boo(int** num) {
	return ++**num; // if we set an postfix increment with printf, value will not be changed
}

int main() {
	int num = 10;
	int* num_ptr;
	num_ptr = &num;

	printf("\n%d", boo(&num_ptr));
	return 0;
}