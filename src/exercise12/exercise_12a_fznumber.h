//
// Created by Sergio Marin Sanchez on 22/3/24.
//

#ifndef IMAGE_PROCESSING_EXERCISE_12A_FZNUMBER_H
#define IMAGE_PROCESSING_EXERCISE_12A_FZNUMBER_H

#define BUFFER_SIZE 32

#define LABEL_NO_FZ 0

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

// Read the configuration file
u_int readConfigFile(char *configFilename);

int writeOutputFile(const char *fileName, u_int number);

#endif //IMAGE_PROCESSING_EXERCISE_12A_FZNUMBER_H
