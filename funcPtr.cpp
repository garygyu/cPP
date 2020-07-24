#include <stdio.h>
#include "functions.H"
int addition (int x, int y);
int New(int x, int y);
int multiplication (int x, int y);

typedef int (*funcPtr) (int, int);

int main()
{
	// "funcPtr" represents a function pointer type
	// "funcPtr foo" means "foo" is a function pointer;
	funcPtr foo;
	foo = addition;
	printf("%d\n", foo(4, 6));

	funcPtr multiply(multiplication);
	printf("%d\n", multiply(6, 6));
	printf("%d\n", New(4, 6));


	return 0;
}
