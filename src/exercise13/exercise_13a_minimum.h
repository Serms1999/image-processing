//
// Created by Sergio Marin Sanchez on 14/3/24.
//

#ifndef IMAGE_PROCESSING_EXERCISE_13A_MINIMUM_HPP
#define IMAGE_PROCESSING_EXERCISE_13A_MINIMUM_HPP

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <queue>
#include <list>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#define BUFFER_SIZE 32

#define LABEL_FZ 255
#define LABEL_NO_FZ 0

#define IS_MIN '1'
#define IS_NOT_MIN '0'

struct config {
    u_int x;
    u_int y;
    u_int connectivity;
};

// Read the configuration file
config readConfigFile(char *configFilename);

int writeOutputFile(const char *fileName, bool minimum);

#endif //IMAGE_PROCESSING_EXERCISE_13A_MINIMUM_HPP
