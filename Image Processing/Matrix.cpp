//
//  Matrix.cpp
//  
//
//  Created by Ali Parchekani on 11/22/17.
//

#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int i , int c) {
    for (int k = 0; k < i; k++ ) {
        rows.push_back(Row(c));
    }
}

Matrix::Matrix(vector<Row> init) {
    rows=init;
}

void Matrix::operator=(Matrix m2) {
    rows = m2.rows;
}

void Matrix::operator=(Row row2) {
    rows.clear();
    rows.push_back(row2);
}

Matrix Matrix::operator+(Matrix m2) {
    if ((height() != m2.height()) || (width() != m2.width())) {
        throw MatrixLengthException();
    }
    vector<Row> creator;
    for (int i = 0; i < rows.size() ; i++ ) {
        creator.push_back(rows[i] + m2.rows[i]);
    }
    return Matrix(creator);
}

Matrix Matrix::operator*(Matrix m2) {
    if ((width() != m2.height())) {
        throw MatrixMultException();
    }
    vector<Row> creator;
    for (int i = 0; i < height(); i++ ) {
        creator.push_back(rows[i]*m2);
    }
    return Matrix(creator);
}

void Matrix::operator*=(Matrix m2) {
    if ((width() != m2.height())) {
        throw MatrixMultException();
    }
    vector<Row> creator;
    for (int i = 0; i < height(); i++ ) {
        creator.push_back(rows[i]*m2);
    }
    rows.clear();
    rows = creator;
}

int Matrix::height() const {
    return rows.size();
}

int Matrix::width() {
    if (rows.size() == 0) {
        return 0;
    }
    return rows[0].size();
}

void Matrix::insert(Row target,int pos) {
    vector<Row> result;
    for (int i = 0; i < pos; i++ ) {
        result.push_back(rows[i]);
    }
    result.push_back(target);
    for (int i = pos ; i < height(); i++) {
        result.push_back(rows[i]);
    }
    rows.clear();
    rows = result;
}

ostream& operator<<(ostream& out,const Matrix temp) {
    out << '[' << endl;
    for (int i = 0; i < temp.height(); i++ ) {
        out << temp.rows[i] << endl;
    }
    out << ']';
    return out;
}

vector<double> Matrix::get_column(int num) {
    vector<double> result;
    for (int i = 0; i < rows.size() ; i++ ) {
        result.push_back(rows[i].get_elements(num));
    }
    return result;
}

Matrix operator-(double num, Matrix temp) {
    vector<Row> result;
    for (int i = 0; i < temp.height() ; i++ ) {
        result.push_back(num - temp.rows[i]);
    }
    return Matrix(result);
}

istream& operator>>(istream& is , Matrix& temp) {
    vector<Row> result;
    string line;
    getline(is,line);
    while (true) {
        getline(is,line);
        if (line[0] == ']') {
            break;
        }
        istringstream iss(line);
        Row res_row;
        iss >> res_row;
        result.push_back(res_row);
    }
    temp.rows = result;
    return is;
}





