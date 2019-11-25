#Makefile

myprogram: main.cpp methods.cpp
	gcc -o myprogram main.cpp methods.cpp

clean:
	rm -r *.o myprogram
