#include <iostream>
#include <vector>
using namespace std;

class oshibka{};
int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		vector <double> v,razn;
		int k;
		double ch, sum = 0;
		cout << "Пожалуйста, введите несколько чисел (для прекращения ввода нажмите клавишу -1):";
		while (cin >> ch, ch != -1.0) {
			v.push_back(ch);
		}
		cout << "Пожалуйста, введите количество чисел, которые хотите просуммировать :";
		cin >> k;
		if (k > v.size())
			throw oshibka();
		for (int i = 0; i < k; i++) {
			sum += v[i];
		}
		cout << "Сумма первых " << k << " чисел: ";
		for (int i = 0; i < k; i++) {
			cout << v[i];
			if (i < k - 1)
				cout << ',';
			else cout << ' ';
		}
		cout << "равна " << sum << endl;
		for (int i = 0; i < v.size() - 1;i++) {
			razn.push_back(v[i + 1] - v[i]);
			cout << razn[i]<<' ';
		}
	}
	catch (oshibka) {
		cout << "Недостаточно чисел";
	}
	return 0;
}
