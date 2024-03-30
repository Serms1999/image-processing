//
// Created by Sergio Marin Sanchez on 29/3/24.
//

#ifndef IMAGE_PROCESSING_PRACTICE_03B_FAST_WATERSED_H
#define IMAGE_PROCESSING_PRACTICE_03B_FAST_WATERSED_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>

#include "neighbors.h"

// Initial value of a threshold level
#define MASK -2

// Value of the pixel belonging to the watersheds
#define WSHED 0

// Initial value of output pixels
#define INIT -1

#define CONNECTIVITY 8

#endif //IMAGE_PROCESSING_PRACTICE_03B_FAST_WATERSED_H
