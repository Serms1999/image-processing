//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "exercise_02b_compare.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>

#include "compare.h"

using cv::Mat;
using cv::imread;
using cv::IMREAD_GRAYSCALE;
using cv::imwrite;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

using std::cout;
using std::cerr;
using std::endl;

int writeOutputFile(char *fileName, bool equal)
{
    char *output = (char*) malloc(2 * sizeof(char));
    snprintf(output, 2 * sizeof(char), "%c", equal ? EQUAL_FILES : DIFFERENT_FILES);

    int fd;
    if ((fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRGRP | S_IWGRP)) == -1)
    {
        perror("Error writing the output file");
        free(output);
        return EXIT_FAILURE;
    }
    if (write(fd, output, strlen(output)) == -1)
    {
        perror("Error writing the output file");
        close(fd);
        free(output);
        return EXIT_FAILURE;
    }

    close(fd);
    free(output);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input image 1> <input image 2> <output file>" << endl;
        return EXIT_FAILURE;
    }

    // Read the input images
    Mat image1 = imread(argv[1], IMREAD_GRAYSCALE);
    Mat image2 = imread(argv[2], IMREAD_GRAYSCALE);

    return writeOutputFile(argv[3], compare(&image1, &image2));
}
