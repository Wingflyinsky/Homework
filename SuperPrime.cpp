#include<stdio.h>

int isPrime(int n);
int isSuperPrime(int n);

int main() {
	int numberofSP=0;
	int sumofSP=0;
	int maxSP=0;
	for (int j = 100; j < 1000; j++) {
		if (isSuperPrime(j)==1) {
			numberofSP++;
			sumofSP += j;
			maxSP = j;
		}
	}
	printf("%d %d %d\n",numberofSP, sumofSP, maxSP);
	return 0;
}

int isPrime(int n) {
	if (n <= 1) {
		return 0;
	}
	for (int i = 2; i <= n/2; i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int isSuperPrime(int n) {
	int a[3];
	a[0] = n / 100;
	a[1] = n / 10 % 10;
	a[2] = n % 10;
	if (isPrime(n) == 1 && isPrime(a[0] + a[1] + a[2]) == 1 && isPrime(a[0] * a[1] * a[2]) == 1 && isPrime(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}