main: 
	g++ -O3 main.cpp MyLib.h -o main.exe
masyvai:
	g++ main(masyvai).cpp MyLib.h -o main.exe
mylib:
	g++ -c MyLib.h
run:
	./main.exe