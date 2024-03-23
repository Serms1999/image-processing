//
// Created by Sergio Marin Sanchez on 22/3/24.
//

#ifndef IMAGE_PROCESSING_NEIGHBORS_H
#define IMAGE_PROCESSING_NEIGHBORS_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <list>

typedef std::list<cv::Point> neighbourhood;

neighbourhood getNeighbours8Connectivity(cv::Point p, u_int height, u_int width);

neighbourhood getNeighbours4Connectivity(cv::Point p, u_int height, u_int width);

neighbourhood getNeighbours(cv::Point p, u_int height, u_int width, u_int connectivity);

#endif //IMAGE_PROCESSING_NEIGHBORS_H
