//
// Created by Sergio Marin Sanchez on 22/2/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

#define WHITE_PIXEL 255
#define BLACK_PIXEL 0

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Error: number of arguments: " << argv[0] << " <input image> <threshold> <output image>" << std::endl;
        return EXIT_FAILURE;
    }

    // Read the input image
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    // Setting the threshold
    uint THRESHOLD = atoi(argv[2]);

    // Reading the output filename
    char *outputFilename = argv[3];

    // Modify the image
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            image.at<uchar>(i, j) = image.at<uchar>(i, j) >= THRESHOLD ? WHITE_PIXEL : BLACK_PIXEL;
        }
    }

    std::cout << "Saving image " << outputFilename << " ..." << std::endl;
    cv::imwrite(outputFilename, image);

    std::cout << "Showing image in window... Press a key to finish." << std::endl;
    uint winNameLength = strlen("Window: image with threshold = ") + strlen(argv[2]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: image with threshold = %d", THRESHOLD);
    cv::imshow(winName, image);
    cv::waitKey(0);

    free(winName);

    return EXIT_SUCCESS;
}
