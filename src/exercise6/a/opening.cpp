//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#include "opening.hpp"

#include "erosion.hpp"
#include "dilation.hpp"

void opening(const cv::Mat *image, cv::Mat *output, u_int size)
{
    erosion(image, output, size);
    cv::Mat newReference = (*(output)).clone();
    dilation(&newReference, output, size);
}
