#include <iostream>
#include <vector>
using namespace std;

vector <int> first(vector <int> one) {
	vector <int> local;
	for (int i = one.size() - 1; i >= 0; i--)
		local.push_back(one[i]);
	return local;
}

void second(vector <int> &one) {
	for (int i = 0; i < one.size() / 2; ++i)
	{
		swap(one[i], one[one.size()-1 - i]);
	}
}

int main()
{
	vector <int> one = { 1,3,5,9 };
	vector <int> two = first(one);
	second(one);
	for (int i = 0; i < two.size(); i++)
		cout << two[i]<< ' ';
	cout << endl;
	for (int i = 0; i < one.size(); i++)
		cout << one[i] << ' ';

}


