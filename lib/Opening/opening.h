//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#ifndef IMAGE_PROCESSING_OPENING_H
#define IMAGE_PROCESSING_OPENING_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

// Performs opening of size <size>
void opening(const cv::Mat *image, cv::Mat *output, u_int size);

#endif //IMAGE_PROCESSING_OPENING_H
