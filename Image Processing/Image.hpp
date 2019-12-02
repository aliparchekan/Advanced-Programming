//
//  Image.hpp
//  
//
//  Created by Ali Parchekani on 11/24/17.
//

#ifndef Image_hpp
#define Image_hpp

#include <iostream>
#include "Matrix.hpp"
#include "bitmap_image.hpp"
#include "ConvolveException.hpp"
#include "Row.hpp"

class Matrix;
class bitmap_image;
class Row;
class ConvolveException;

class Image {
public:
    Image() {}
    Image(bitmap_image _im , Matrix _imr , Matrix _img , Matrix _imb) : im(_im) , Im_red(_imr) , Im_blue(_imb) , Im_green(_img) {}
    Image(string filepath);
    void apply_matrix();
    void operator=(Image image2);
    Image operator*(Matrix m);
    Image operator!();
    int height();
    int width();
    void save(string filepath);
    void perform_conv(int x , int y , Matrix m , double& sum_r,double& sum_g,double& sum_b);
    bool is_out_of_range(int x , int y);
private:
    Matrix Im_red;
    Matrix Im_blue;
    Matrix Im_green;
    bitmap_image im;
};

#endif /* Image_hpp */
