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
