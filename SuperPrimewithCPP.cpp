#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

class Prime {
private:
	int number;
	int size;
public:
	Prime(int n) {
		number = n;
		size = 1;
		int remain = n;
		while (remain>9) {
			size++;
			remain /= 10;
		}
	}

	int getSum() {
		int sum =0;
		int remain = number;
		for (int i = 0; i < size; i++) {
			sum += remain % 10 ;
			remain = remain / 10;
		}
		return sum;
	}

	int getProduct() {
		int product = 1;
		int remain = number;
		for (int i = 0; i < size; i++) {
			product *= remain % 10;
			remain = remain / 10;
		}
		return product;
	}

	int getSquare() {
		int square = 0;
		int remain = number;
		for (int i = 0; i < size; i++) {
			square += (remain % 10)*(remain % 10);
			remain = remain / 10;
		}
		return square;
	}

};

class SuperPrime {
private:
	int low, high;
	int numberofSP,sumofSP,maxSP;
public:
	SuperPrime(int l, int h) {
		low = l;
		high = h;
	}
	void Show() {
		numberofSP = 0;
		sumofSP = 0;
		maxSP = 0;
		for (int i = low; i <= high; i++) {
			if (isPrime(i) == true) {
				Prime p(i);
				if (isPrime(p.getSum()) == true && isPrime(p.getProduct())==true && isPrime(p.getSquare())==true) {
					numberofSP++;
					sumofSP += i;
					if (maxSP < i) {
						maxSP = i;
					}
				}
			}

		}
		cout << numberofSP << endl << sumofSP <<endl << maxSP << endl;
	}

};



int main() {
	SuperPrime sp(100, 999);
	sp.Show();
	return 0;
}