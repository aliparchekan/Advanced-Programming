//
//  Matrix.hpp
//  
//
//  Created by Ali Parchekani on 11/22/17.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include <vector>
#include "Row.hpp"
#include "MatrixLengthException.hpp"



class MatrixLengthException;
class Row;

class Matrix {
public:
    Matrix() {}
    Matrix(int i , int c);
    Matrix(vector<Row> init);
    void operator=(Matrix m2);
    void operator=(Row row2);
    Matrix operator+(Matrix m2);
    Matrix operator*(Matrix m2);
    void operator*=(Matrix m2);
    int height() const;
    int width();
    void insert(Row target,int pos);
    vector<double> get_column(int num);
    friend ostream& operator<<(ostream& out,const Matrix temp);
    friend istream& operator>>(istream& is , Matrix& temp);
    friend Matrix operator-(double num, Matrix temp);
    double get_element(int i , int c) {return rows[i].get_elements(c);}
    Row get_row(int c) {return rows[c];}
private:
    vector<Row> rows;
};

#endif /* Matrix_hpp */
