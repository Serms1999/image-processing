//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#ifndef IMAGE_PROCESSING_CLOSING_H
#define IMAGE_PROCESSING_CLOSING_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

// Performs closing of size <size>
void closing(const cv::Mat *image, cv::Mat *output, u_int size);

#endif //IMAGE_PROCESSING_CLOSING_H
