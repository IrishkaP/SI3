#include <iostream>
#include <vector>
#include "edx-io.hpp"
using namespace std;

bool proverka(string s) {
    int k_op = 0, k_cl = 0;
    vector <char> op;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            op.push_back(s[i]);
            k_op++;
        }
        if (s[i] == ')') {
            if (op.size() != 0 && op.back() == '(') {
                k_cl++;
                op.pop_back();
            }
            else
                return false;
        }
        if (s[i] == ']') {
            if (op.size() != 0 && op.back() == '[') {
                k_cl++;
                op.pop_back();
            }
            else
                return false;
        }
    }
    if (k_op == k_cl)
        return true;
    else
        return false;
}

int main()
{
    string s;
	int k;
	io >> k;
	for (int i = 0; i < k; i++) {
		io >> s;
		if (proverka(s))
			io << "YES" << "\n";
		else
			io << "NO" << "\n";
	}
}


