#include <iostream>
#include <vector>
using namespace std;

int max(const vector <int>& result) {
	int max = result[result.size() - 1], ch = result.size() - 1;
	for (int i = 0; i < result.size(); i++)
		if (result[i] > max) {
			max = result[i];
			ch = i;
		}
	return ch;
}

int min(const vector <int>& result) {
	int min = result[result.size() - 1],ch = result.size() - 1;
	for (int i = 0; i < result.size(); i++)
		if (result[i] < min) {
			min = result[i];
			ch = i;
		}
	return ch;
}

vector <int> kol(const vector <string>& start) {
	vector <int> result;
	for (int i = 0; i < start.size(); i++) {
		result.push_back(start[i].size());
	}
	return result;
}

vector <string> sort(vector <string> start) {
	vector <string> sorti;
	for (int i = 0; i < start.size()-1; i++)
		for (int j = i+1; j < start.size(); j++)
			if (start[j] < start[i]) {
				swap(start[j], start[i]);
			}
	sorti.push_back(start[0]);
	sorti.push_back(start[start.size() - 1]);
	return sorti;
}


int main()
{
	vector <string> start = {"Stroka_1", "Vtoraya stroka", "Chto-to", "Kkkk","AAAAAAAA"};
	vector <int> result = kol(start);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	cout << endl << start[min(result)] << endl << start[max(result)];
	vector <string> sorti = sort(start);
	cout << endl << sorti[0] << endl << sorti[1];
}


