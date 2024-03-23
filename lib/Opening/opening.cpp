//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#include "opening.h"

#include "erosion.h"
#include "dilation.h"

using cv::Mat;

void opening(const Mat *image, Mat *output, u_int size)
{
    erosion(image, output, size);
    Mat newReference = (*(output)).clone();
    dilation(&newReference, output, size);
}
