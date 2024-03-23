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

int writeOutputFile(bool equal)
{
    char *fileName = strdup("exercise_02b_output_01.txt");
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
    if (argc < 3)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input image 1> <input image 2>" << endl;
        return EXIT_FAILURE;
    }

    // Read the input images
    Mat image1 = imread(argv[1], IMREAD_GRAYSCALE);
    Mat image2 = imread(argv[2], IMREAD_GRAYSCALE);

    // If the images shapes do not match, the images can not be equals
    if ((image1.rows != image2.rows) || (image1.cols != image2.cols))
    {
        return writeOutputFile(false);
    }

    // If they have equal shapes then each pixel has to be checked
    for (int i = 0; i < image1.rows; i++)
    {
        for (int j = 0; j < image1.cols; j++)
        {
            if (image1.at<u_char>(i, j) != image2.at<u_char>(i, j))
            {
                return writeOutputFile(false);
            }
        }
    }

    // If every pair of pixels are equal then the images are equals
    return writeOutputFile(true);
}
