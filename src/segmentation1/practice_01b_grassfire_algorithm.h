//
// Created by Sergio Marin Sanchez on 24/3/24.
//

#ifndef IMAGE_PROCESSING_PRACTICE_02B_GRASSFIRE_ALGORITHM_H
#define IMAGE_PROCESSING_PRACTICE_02B_GRASSFIRE_ALGORITHM_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <random>

#include "neighbors.h"

#define BUFFER_SIZE 32
#define BLACK_PIXEL 0

struct config {
    u_int connectivity;
    u_int size;
};

#endif //IMAGE_PROCESSING_PRACTICE_02B_GRASSFIRE_ALGORITHM_H
