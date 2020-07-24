#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include "string.h"
// pointer to functions
// pointer to class member functions
// array of pointers to functions/class functions
// use of alias declaration istead of typedef

void square(int&, int&);
void cube(int&, int&);
void swap(int&, int&);
void getVals(int&, int&);
void printVals(int, int);

// define a function pointer type, pf
using pf = void (*) (int&, int&);

int main()
{
    int valOne=1, valTwo=2;
    const int maxArray = 4;
	std::array<pf, maxArray> pFuncArray =
	{
		getVals, square, cube, swap
	};

    for (const auto& func : pFuncArray)
    {
        func(valOne, valTwo);
        printVals(valOne, valTwo);
    }
    return 0;
}

void printVals(int x, int y)
{
    std::cout << "x: " << x << " y: " << y << "\n";
}

void square(int &rX, int &rY)
{
    rX *= rX;
    rY *= rY;
}

void cube(int &rX, int &rY)
{
    int tmp;

    tmp = rX;
    rX *= rX;
    rX *= tmp;

    tmp = rY;
    rY *= rY;
    rY *= tmp;
}

void swap(int &rX, int &rY)
{
    int temp;
    temp = rX;
    rX = rY;
    rY = temp;
}

void getVals(int &rValOne, int &rValTwo)
{
    std::cout << "New value for valOne: ";
    std::cin >> rValOne;
    std::cout << "New value for valTwo: ";
    std::cin >> rValTwo;
}

class Dog
{
public:
    void speak() const { std::cout << "Woof!\n"; }
    void move() const { std::cout << "Walking to heel ...\n"; }
    void eat() const { std::cout << "Gobbling food ...\n"; }
    void growl() const { std::cout << "Grrrrr\n"; }
    void whimper() const { std::cout << "Whining noises ...\n"; }
    void rollOver() const { std::cout << "Rolling over ...\n"; }
    void playDead() const
        { std::cout << "Is this the end of Little Caesar?\n"; }
};

// define a pointer to class member function type, pCMF
// pointing function members of class "Dog"
using pCMF = void (Dog::*)() const;
//typedef void (Dog::*pCMF)() const;

int main()
{
    const int maxFuncs = 7;
	std::array<pCMF, maxFuncs> dogFunctions =
        {   &Dog::speak, // address of member function, Dog::speak
            &Dog::move,
            &Dog::eat,
            &Dog::growl,
            &Dog::whimper,
            &Dog::rollOver,
            &Dog::playDead
        };

    Dog* pDog(nullptr);
    int method;
    bool fQuit = false;

    while (!fQuit)
    {
        std::cout << "(0) Quit (1) Speak (2) Move (3) Eat (4) Growl";
        std::cout << " (5) Whimper (6) Roll Over (7) Play Dead: ";
        std::cin >> method;
        if (method == 0)
        {
            fQuit = true;
            break;
        }
        else
        {
			pDog = new Dog;
			(pDog->*dogFunctions[method-1])();
			delete pDog;
		}
    }
    return 0;
}

/*
./ funcPtr.cpp (containing main())
./lib for library files => libfunctions.a (static-linked library file) 
                           & libfunctions.so (dynamic-linked library file)
./obj for object files => functions.o
./inc for included files => functions.H
./src for source files => functions.cpp

// compile *.cpp to get *.o file
	g++ -c ./src/functions.cpp -I./inc -o ./obj/functions.o

// archive a set of *.o files into a single *.a file
	ar rcs ./lib/libfunctions.a ./obj/functions.o

// create executable file "run" with staticlinked library file "libfunctions.a"
// -I./inc: specifies the directory where included files stored, ./inc
// -L./lib: specifies the directory where library files stored, ./lib
// -lfunctions: specifies the library file name to be linked, "libfunctions.a" 
g++ -o run funcPtr.cpp -I./inc -L./lib -lfunctions

//  compile *.cpp to get *.o file, -fPIC: position independent code (PIC)
	g++ -c -fPIC ./src/functions.cpp -I./inc -o ./obj/functions.o

//	create a share library file "libfunctions.so" & stored in ./lib
	g++ -shared ./obj/functions.o -o ./lib/libfunctions.so

//	add "/usr/lib" to PATH
//	edit "~/.bashrc" file
	vim ~/.bashrc
//	add "export PATH=$PATH:/usr/lib" at the bottom of the file
	source ~/.bashrc
//	move "libfunctions.so" to "/usr/lib"
	sudo mv lib/libfunctions.so /usr/lib/.
//	make sure "libfunctions.so" is 755
	ls /usr/lib/libfunctions.so -l
//	otherwise
	sudo chmod 755 /usr/lib/libfunctions.so

//	create executable file "run" with dynamic-linked library file "libfunctions.so"
//	since it is stored in $PATH, no need to specify the directory where it is saved by "-L"
	g++ -o run funcPtr.cpp -I./inc -lfunctions	
*/
