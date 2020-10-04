#include <iostream>
using namespace std;

int main() {
	int  a = 1,b = 1,c = 0;
	cout << 1 << endl << 1 << endl;
	while (c < 1836311903) {
		c = a + b;
		a = b;
		b = c;
		cout << c << endl;
	}
	return 0;
}