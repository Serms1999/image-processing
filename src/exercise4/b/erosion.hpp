//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#ifndef IMAGE_PROCESSING_EROSION_HPP
#define IMAGE_PROCESSING_EROSION_HPP

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

// Performs a horizontal erosion with kernel 3x1
void horizontalErosion(const cv::Mat *image, cv::Mat *output);

// Performs a vertical erosion with kernel 1x3
void verticalErosion(const cv::Mat *image, cv::Mat *output);

// Performs erosion of size <size>
void erosion(const cv::Mat *image, cv::Mat *output, u_int size);

#endif //IMAGE_PROCESSING_EROSION_HPP
