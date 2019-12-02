#include <iostream>
#include "Matrix.hpp"
#include "Row.hpp"
#include "Image.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Matrix m(3, 4);
    
    Row r(4);
    r[0]=2;
    r[1]=3;
    r[2]=4;
    r[3]=7;
    
    vector<Row> rows(3, r);
    
    m = Matrix(rows);
    
    cout << m.height() << ' ' << m.width() << endl;
    cout << m << endl;
    
    r[2]=-10;
    
    m.insert(r, m.height());
    
    cout << "row:\t" << r << endl;
    cout << "matrix:\t" << endl << m << endl;
    
    Matrix mi;
    cin >> mi;
    cout << mi << endl;
    
    Matrix m2(mi.height(), mi.width());
    m2 = mi + mi;
    
    Image img("lena.bmp");
    Image img2;
    img2 = !img;
    img2.save("image2.bmp");
    
    Matrix m3(3, 3);
    Row r2(3);
    vector<Row> rows2;
    r2[0] = -1;
    r2[1] = -1;
    r2[2] = -1;
    rows2.push_back(r2);
    r2[1] = 8;
    rows2.push_back(r2);
    r2[1] = -1;
    rows2.push_back(r2);
    m3 = Matrix(rows2);
    
    img2 = img * m3;
    img2.save("lena-edge.bmp");
    
    return 0;
}

