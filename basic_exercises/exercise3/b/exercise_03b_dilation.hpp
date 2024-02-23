//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#ifndef IMAGE_PROCESSING_EXERCISE_03A_DILATION_H
#define IMAGE_PROCESSING_EXERCISE_03A_DILATION_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

// Performs a horizontal dilation with kernel 3x1
void horizontalDilation(const cv::Mat *image, cv::Mat *output);

// Performs a vertical dilation with kernel 1x3
void verticalDilation(const cv::Mat *image, cv::Mat *output);

// Performs dilation of size <size>
void dilation(const cv::Mat *image, cv::Mat *output, u_int size);

#endif //IMAGE_PROCESSING_EXERCISE_03A_DILATION_H
