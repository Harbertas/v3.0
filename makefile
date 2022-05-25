main: functions.o mix.o
	g++ -o main main.cpp functions.o mix.o
functions:
	g++ -c functions.cpp mix.cpp
clean:
	rm *.o main