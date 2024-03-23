//
// Created by Sergio Marin Sanchez on 25/2/24.
//

#ifndef IMAGE_PROCESSING_EXERCISE_11A_FLATZONE_H
#define IMAGE_PROCESSING_EXERCISE_11A_FLATZONE_H

#define BUFFER_SIZE 32

#define LABEL_NO_FZ 0

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

struct config {
    u_int x;
    u_int y;
    u_int connectivity;
    u_int flatZoneLabel;
};


// Read the configuration file
config readConfigFile(char *configFilename);

#endif //IMAGE_PROCESSING_EXERCISE_11A_FLATZONE_H
