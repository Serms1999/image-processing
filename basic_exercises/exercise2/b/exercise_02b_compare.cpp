//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "exercise_02b_compare.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

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
        std::cout << "Error: number of arguments: " << argv[0] << " <input image 1> <input image 2>" << std::endl;
        return EXIT_FAILURE;
    }

    // Read the input images
    cv::Mat image1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat image2 = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

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
            if (image1.at<uchar>(i, j) != image2.at<uchar>(i, j))
            {
                return writeOutputFile(false);
            }
        }
    }

    // If every pair of pixels are equal then the images are equals
    return writeOutputFile(true);
}
