main: 
	g++ main.cpp MyLib.h -o main.exe
masyvai:
	g++ main(masyvai).cpp MyLib.h -o main.exe
mylib:
	g++ -c MyLib.h