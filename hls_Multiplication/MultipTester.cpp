
#include <iostream>
#include "multiplication.h"

using namespace std;

int main(int argc, char *argv[])
{
	int i, j;
	int pass = 1;
	int n32Multip;

	cout << ">> Start test!" << endl;

	for(i = 1; i < 10; i++) {
		cout << "------------------------" << endl;
		for(j = 1; j < 10; j++) {
			multip_2num(i, j, &n32Multip);

			cout << i << " * " << j << " = " << n32Multip << endl;
			if(n32Multip != (i * j)) {
				pass = 0;
			}
		}
	}
	cout << "------------------------" << endl;

	if(!pass) {
		cout << ">> Test failed!" << endl;
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;
}
