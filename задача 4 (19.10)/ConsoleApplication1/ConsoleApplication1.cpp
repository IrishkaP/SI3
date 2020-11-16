#include <iostream>
#include <vector>
#include <string>
#include "edx-io.hpp"
using namespace std;


int main()
{
	char l;
	int k;
	io >> k;
	vector<int> res;
	for (int i = 0; i < k; i++) {
		io >> l;
		if (isdigit(l)) {
			int x = l - '0';
			res.push_back(x);
		}
		else {
			if (l == '+') {
				int right = res.back();
				res.pop_back();
				int left = res.back();
				res.pop_back();
				res.push_back(left + right);
			}
			if (l == '-') {
				int right = res.back();
				res.pop_back();
				int left = res.back();
				res.pop_back();
				res.push_back(left - right);
			}
			if (l == '*') {
				int right = res.back();
				res.pop_back();
				int left = res.back();
				res.pop_back();
				res.push_back(left * right);
			}
		}
	}
	int result = res.back();
	io << result;

}


