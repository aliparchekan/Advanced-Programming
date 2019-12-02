//
//  Row.cpp
//  
//
//  Created by Ali Parchekani on 11/20/17.
//

#include "Row.hpp"

using namespace std;

Row::Row(int size) {
    for (int i = 0; i < size; i++ ) {
        elements.push_back(0);
    }
}

Row::Row(vector<double> init){
    elements = init;
}

void Row::operator=(Row row2) {
    if (elements.size() != row2.size()) {
        throw RowLengthException();
    }
    elements = row2.elements;
}

void Row::operator=(vector<double> equal) {
    if (elements.size() != equal.size()) {
        throw RowLengthException();
    }
    elements = equal;
}

Row Row::operator+(Row row2) {
    if (elements.size() != row2.size()) {
        throw RowLengthException();
    }
    vector<double> temp;
    for (int i = 0; i < elements.size() ; i++ ) {
        temp.push_back(elements[i] + row2.elements[i]);
    }
    return Row(temp);
}

void Row::operator+=(Row row2) {
    if (elements.size() != row2.size()) {
        throw RowLengthException();
    }
    for (int i = 0; i < elements.size(); i++ ) {
        elements[i] += row2.elements[i];
    }
}

Row operator*(double mult , Row row){
    vector<double> result;
    for (int i = 0; i < row.elements.size() ; i++ ) {
        result.push_back(row.elements[i] * mult);
    }
    return Row(result);
}

bool Row::operator==(Row row2) {
    if (elements.size() != row2.size() ) {
        return false;
    }
    for (int i = 0; i < elements.size() ; i++ ) {
        if (elements[i] != row2.elements[i]) {
            return false;
        }
    }
    return true;
}

int Row::size() const {
    return elements.size();
}

Row Row::operator*(Matrix m) {
    if (size() != m.height()) {
        throw MatrixMultException();
    }
    vector<double> result;
    vector<double> column;
    for (int i = 0; i < m.width(); i++ ) {
        column.clear();
        column = m.get_column(i);
        double sum = 0;
        for (int j = 0; j < column.size(); j++ ) {
            sum += (elements[j]*column[j]);
        }
        result.push_back(sum);
    }
    return Row(result);
}

ostream& operator<<(ostream& out,const Row temp) {
    for (int i = 0; i < temp.size() - 1; i++ ) {
        out << temp.elements[i] << '\t';
    }
    if (temp.size() > 0) {
        out << temp.elements[temp.size() - 1];
    }
    return out;
}

Row operator-(double num , Row temp) {
    vector<double> result;
    for (int i = 0; i < temp.size(); i++ ) {
        result.push_back(num - temp.elements[i]);
    }
    return Row(result);
}

istream& operator>>(istream& is,Row& temp) {
    string line;
    getline(is,line);
    istringstream iss(line);
    string temps;
    vector<double> result;
    while (getline(iss,temps,'\t')) {
        if (temps!="\t") {
            istringstream is(temps);
            double f;
            is >> f;
            result.push_back(f);
        }
        
    }
    temp.elements = result;
    return is;
}

double& Row::operator[](int place) {
    if ((place < 0) || (place > size() - 1)) {
        throw IndexOutOfBoundException();
    }
    return elements.at(place);
}

const double& Row::operator[](int place)const {
    if ((place < 0) || (place > size() - 1)) {
        throw IndexOutOfBoundException();
    }
    return elements.at(place);
}

double Row::get_elements(int num) {
    return elements[num];
}


