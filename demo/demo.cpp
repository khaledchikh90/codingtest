#include<iostream>
#include "utils.h"
#include "Specs.h"
#include "imageEditing.h"


int main(int argc, char *argv[]){
    /** Accept max of 2 arguments **/
    if(argc != 3)
    {
        std::cout << "Expected 2 arguments got : " << argc - 1 << std::endl;
        return 1;
    }
    

    Specs* specs = new Specs();
    /** Parse spec file in data/spec.txt (arg2) **/
    specs->parseFromFile(argv[2]);
    /** Load the image **/
    cv::Mat img = readImage(argv[1]);
    /** resize the image (new_w=average specs width, new_h=max specs height) **/
    cv::Mat out = resizeImage(img, specs->getAvgWidth(), specs->getMaxHeight());
    /** save resized image under data/dog1.jpg **/
    saveImage(out, "../data/dog1.jpg");

    return 0;
}