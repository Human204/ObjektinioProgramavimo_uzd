main: 
	g++ -O3 main.cpp skaiciavimai.cpp ranka.cpp failai.cpp MyLib.h ranka.h skaiciavimai.h failai.h -o main.exe
masyvai:
	g++ main(masyvai).cpp MyLib.h -o main.exe
mylib:
	g++ -c MyLib.h
run:
	./main.exe