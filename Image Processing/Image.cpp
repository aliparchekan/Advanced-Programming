//
//  Image.cpp
//  
//
//  Created by Ali Parchekani on 11/24/17.
//

#include "Image.hpp"

using namespace std;

Image::Image(string filepath) {
    bitmap_image temp(filepath);
    im = temp;
    unsigned char red,green,blue;
    vector<double> red_in_row;
    vector<double> blue_in_row;
    vector<double> green_in_row;
    vector<Row> red_rows;
    vector<Row> blue_rows;
    vector<Row> green_rows;
    for (int i = 0; i < height(); i++ ) {
        for (int j = 0; j < width(); j++ ) {
            im.get_pixel(j,i,red,green,blue);
            red_in_row.push_back(red);
            green_in_row.push_back(green);
            blue_in_row.push_back(blue);
        }
        red_rows.push_back(Row(red_in_row));
        green_rows.push_back(Row(green_in_row));
        blue_rows.push_back(Row(blue_in_row));
        red_in_row.clear();
        blue_in_row.clear();
        green_in_row.clear();
    }
    Im_red = Matrix(red_rows);
    Im_green = Matrix(green_rows);
    Im_blue = Matrix(blue_rows);
}

void Image::apply_matrix() {
    for (int i = 0; i < height() ; i++ ) {
        for (int j = 0; j < width() ; j++ ) {
            im.set_pixel(j,i,Im_red.get_element(i,j) , Im_green.get_element(i,j) , Im_blue.get_element(i,j));
        }
    }
}

void Image::operator=(Image image2) {
    im = image2.im;
    Im_red = image2.Im_red;
    Im_green = image2.Im_green;
    Im_blue = image2.Im_blue;
    apply_matrix();
}

Image Image::operator!() {
    Image result(im , 256 - Im_red , 256 - Im_green , 256 - Im_blue);
    result.apply_matrix();
    return result;
}

double mult(double a,double b) {
    return a*b;
}

void correct (double& sumr , double& sumg , double& sumb) {
    if (sumr > 255) {
        sumr = 255;
    }
    if(sumr < 0)
        sumr = 0;
    if (sumg > 255) {
        sumg = 255;
    }
    if(sumg < 0)
        sumg = 0;
    if (sumb > 255) {
        sumb = 255;
    }
    if(sumb < 0)
        sumb = 0;
}

bool Image::is_out_of_range(int x , int y) {
    if ((x < 0 || y < 0) || ((x > width() - 1) || ( y > height() - 1) )) {
        return true;
    }
    return false;
}


void Image::perform_conv(int x , int y , Matrix m , double& sum_r,double& sum_g,double& sum_b) {
    int center_x = m.height()/2;
    int center_y = m.width()/2;
    for (int i = -center_y; i < center_y + 1 ; i++ ) {
        for (int j = -center_x; j < center_x + 1 ; j++) {
            if (is_out_of_range(x+j,y+i)) {
                sum_r = Im_red.get_element(y,x);
                sum_g = Im_green.get_element(y,x);
                sum_b = Im_blue.get_element(y,x);
                return;
            }
            sum_r += mult(Im_red.get_element(y+i,x+j),m.get_element(center_y+i,center_x+j));
            sum_g += mult(Im_green.get_element(y+i,x+j),m.get_element(center_y+i,center_x+j));
            sum_b += mult(Im_blue.get_element(y+i,x+j),m.get_element(center_y+i,center_x+j));
        }
    }
}

Image Image::operator*(Matrix m) {
    if ((m.height() != m.width()) || (m.width()%2 != 1)) {
        throw ConvolveException();
    }
    int center_x = m.height()/2;
    int center_y = m.width()/2;
    vector<double> red_in_row;
    vector<double> green_in_row;
    vector<double> blue_in_row;
    vector<Row> red_rows;
    vector<Row> green_rows;
    vector<Row> blue_rows;
    for (int i = 0 ; i < height() ; i++ ) {
        for (int j = 0; j < width() ; j++ ) {
            double sum_r = 0;
            double sum_b = 0;
            double sum_g = 0;
            perform_conv(j,i,m,sum_r,sum_g,sum_b);
            correct(sum_r,sum_g,sum_b);
            red_in_row.push_back(sum_r);
            green_in_row.push_back(sum_g);
            blue_in_row.push_back(sum_b);
        }
        red_rows.push_back(Row(red_in_row));
        green_rows.push_back(Row(green_in_row));
        blue_rows.push_back(Row(blue_in_row));
        red_in_row.clear();
        green_in_row.clear();
        blue_in_row.clear();
    }
    Image result(im , Matrix(red_rows) , Matrix(green_rows) , Matrix(blue_rows));
    result.apply_matrix();
    return result;
}

int Image::height() {
    return im.height();
}

int Image::width() {
    return im.width();
}

void Image::save(string filepath) {
    im.save_image(filepath);
}

