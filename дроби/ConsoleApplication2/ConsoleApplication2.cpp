#include <iostream>
#include "Rationall.h"
#include "functions.h"
#include "Bad_area.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	try {
		Rational a(2,3),b(2,4);
	}
	catch (Bad_area) {
		cout << "Ошибочка :(";
	}
}
