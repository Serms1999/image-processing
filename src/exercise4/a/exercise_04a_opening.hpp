//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#ifndef IMAGE_PROCESSING_EXERCISE_04A_OPENING_HPP
#define IMAGE_PROCESSING_EXERCISE_04A_OPENING_HPP

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

// Performs opening of size <size>
void opening(const cv::Mat *image, cv::Mat *output, u_int size);

#endif //IMAGE_PROCESSING_EXERCISE_04A_OPENING_HPP
