//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

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

    // The images should have the same shape
    if ((image1.rows != image2.rows) || (image1.cols != image2.cols))
    {
        std::cerr << "Images should have the same shape." << std::endl;
        return EXIT_FAILURE;
    }

    // Modify the image
    for (int i = 0; i < image1.rows; i++)
    {
        for (int j = 0; j < image1.cols; j++)
        {
            image1.at<uchar>(i, j) = std::min(image1.at<uchar>(i, j), image2.at<uchar>(i, j));
        }
    }

    uint outputFilenameLength = strlen("exercise_02c_inf_output_01.pgm") + 1;
    char *outputFilename = (char*) malloc(outputFilenameLength);
    snprintf(outputFilename, outputFilenameLength, "exercise_02c_inf_output_01.pgm");
    std::cout << "Saving image " << outputFilename << " ..." << std::endl;
    cv::imwrite(outputFilename, image1);

    std::cout << "Showing image in window... Press a key to finish." << std::endl;
    uint winNameLength = strlen("Window: infimum of the images") + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: infimum of the images");
    cv::imshow(winName, image1);
    cv::waitKey(0);

    free(outputFilename);
    free(winName);

    return EXIT_SUCCESS;
}
