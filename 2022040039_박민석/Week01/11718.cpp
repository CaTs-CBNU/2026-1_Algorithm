#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	int T = 0;
	string c[100];
	string Char;
	while (1)
	{
		getline(cin, Char);
		if (Char.length() == 0)
		{
			break;
		}
		c[T] = Char;
		T++;
	}

	for (int i = 0; i < T; i++)
	{
		cout << c[i] << "\n";
	}
	
}