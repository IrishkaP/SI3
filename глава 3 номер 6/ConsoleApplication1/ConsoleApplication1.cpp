
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= b && a >= c)
		if (b >= c)
			cout << c << ',' << b << ',' << a;
		else
			cout << b << ',' << c << ',' << a;
	else
		if (b >= a && b >= c)
		   if (a >= c)
			   cout << c << ',' << a << ',' << b;
		   else
			   cout << a << ',' << c << ',' << b;
		else
			if (c >= b && c >= a)
				if (b >= a)
					cout << a << ',' << b << ',' << c;
				else
					cout << b << ',' << a << ',' << c;
}


