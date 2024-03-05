//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#include "opening.hpp"

#include "erosion.hpp"
#include "dilation.hpp"

void closing(const cv::Mat *image, cv::Mat *output, u_int size)
{
    dilation(image, output, size);
    cv::Mat newReference = (*(output)).clone();
    erosion(&newReference, output, size);
}
