main.exe:main.o f.o
	g++ main.o f.o -o main
main.o:
	g++ main.cpp -o main.o
f.o:
	g++ f.cpp -o f.o
