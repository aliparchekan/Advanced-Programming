//
//  Row.hpp
//  
//
//  Created by Ali Parchekani on 11/20/17.
//

#ifndef Row_hpp
#define Row_hpp

#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include "RowLengthException.hpp"
#include "MatrixMultException.hpp"
#include "IndexOutOfBoundException.hpp"



class RowLengthException;
class MatrixMultException;
class IndexOutOfBoundException;
class Matrix;

class Row {
public:
    Row(){}
    Row(int size);
    Row(vector<double> init);
    void operator=(Row row2);
    void operator=(vector<double> equal);
    Row operator+(Row row2);
    void operator+=(Row row2);
    Row operator*(Matrix m);
    friend Row operator*(double mult , Row row);
    bool operator==(Row row2);
    int size() const;
    double get_elements(int num);
    friend ostream& operator<<(ostream& out,const Row temp);
    friend istream& operator>>(istream& is,Row& temp);
    double& operator[](int place);
    const double& operator[](int place)const;
    friend Row operator-(double num , Row temp);
private:
    vector<double> elements;
};

#include "Matrix.hpp"


#endif /* Row_hpp */
