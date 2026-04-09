#include<stdio.h>


int fibo(int n) {
	if (n <= 2) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int main() {

	
	int n = fibo(50);
	printf("%d\n", n);
	
}