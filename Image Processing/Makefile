all:a.out

a.out:RowLengthException.o MatrixLengthException.o MatrixMultException.o Row.o Matrix.o Image.o main.o ConvolveException.o
	g++ main.o Image.o RowLengthException.o MatrixLengthException.o MatrixMultException.o Matrix.o Row.o ConvolveException.o
Matrix.o:Matrix.hpp Row.hpp
	g++ -c Matrix.cpp
Row.o:Row.hpp Matrix.hpp
	g++ -c Row.cpp
RowLengthException.o:RowLengthException.hpp
	g++ -c RowLengthException.cpp
MatrixLengthException.o:MatrixLengthException.hpp
	g++ -c MatrixLengthException.cpp
MatrixMultException.o:MatrixMultException.hpp
	g++ -c MatrixMultException.cpp
Image.o:Image.hpp Matrix.hpp Row.hpp
	g++ -c Image.cpp
ConvolveException.o:ConvolveException.hpp
	g++ -c ConvolveException.cpp
main.o:main.cpp Image.hpp Matrix.hpp Row.hpp
	g++ -c main.cpp

clean:
	rm *.o
	rm *.out
	