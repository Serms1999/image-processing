//
// Created by Sergio Marin Sanchez on 28/3/24.
//

#ifndef IMAGE_PROCESSING_INFIMUM_H
#define IMAGE_PROCESSING_INFIMUM_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

void infimum(cv::Mat *image1, cv::Mat *image2, cv::Mat *output);

#endif //IMAGE_PROCESSING_INFIMUM_H
