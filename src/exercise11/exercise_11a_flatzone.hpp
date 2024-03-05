//
// Created by Sergio Marin Sanchez on 25/2/24.
//

#ifndef IMAGE_PROCESSING_EXERCISE_11A_FLATZONE_HPP
#define IMAGE_PROCESSING_EXERCISE_11A_FLATZONE_HPP

#define BUFFER_SIZE 32

#define LABEL_NO_FZ 0

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <queue>
#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

struct config {
    u_int x;
    u_int y;
    u_int connectivity;
    u_int flatZoneLabel;
};

class pixel {
public:
    u_int x;
    u_int y;
    pixel()
    {
        this->x = 0;
        this->y = 0;
    }
    pixel(u_int x, u_int y)
    {
        this->x = x;
        this->y = y;
    }

};

typedef std::list<pixel> neighbourhood;

// Read the configuration file
config readConfigFile(char *configFilename);

neighbourhood getNeighbours8Connectivity(pixel p, u_int height, u_int width);

neighbourhood getNeighbours4Connectivity(pixel p, u_int height, u_int width);

neighbourhood getNeighbours(pixel p, u_int height, u_int width, u_int connectivity);

void flatZone(const cv::Mat *image, const cv::Mat *output, config configuration);

#endif //IMAGE_PROCESSING_EXERCISE_11A_FLATZONE_HPP
