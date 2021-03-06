#include <iostream>
using namespace std;

class Number{
private:
	int num;
public:
	Number(int n) {
		this->num = n;
	}

	Number maxDivisor(Number n) {
		int md;
		for (int i = 1; i <= n.num && i <= this->num; i++) {
			if (n.num%i == 0 && this->num%i == 0) {
				md = i;
			}
		}
		return md;
	}

	void show() {
		cout << this->num << endl;
	}
};

int main() {
	int n, n1, n2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> n1 >> n2;
		Number no1(n1), no2(n2);
		Number no3 = no1.maxDivisor(no2);  //最大公约数
		no3.show();
	}
	return 0;
}
