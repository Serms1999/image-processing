//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#include "closing.h"

#include "erosion.h"
#include "dilation.h"

using cv::Mat;

void closing(const Mat *image, Mat *output, u_int size)
{
    dilation(image, output, size);
    Mat newReference = (*(output)).clone();
    erosion(&newReference, output, size);
}
