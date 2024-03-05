//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "exercise_03b_dilation.hpp"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void horizontalDilation(const cv::Mat *image, cv::Mat *output)
{
    cv::Mat img = *(image);
    cv::Mat out = *(output);
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (j == 0)
            {
                out.at<u_char>(i, j) = std::max(img.at<u_char>(i, j), img.at<u_char>(i, j + 1));
            }
            else if (j == img.cols - 1)
            {
                out.at<u_char>(i, j) = std::max(img.at<u_char>(i, j - 1), img.at<u_char>(i, j));
            }
            else
            {
                out.at<u_char>(i, j) = std::max(std::max(img.at<u_char>(i, j - 1), img.at<u_char>(i, j)), img.at<u_char>(i, j + 1));
            }
        }
    }
}

void verticalDilation(const cv::Mat *image, cv::Mat *output)
{
    cv::Mat img = *(image);
    cv::Mat out = *(output);
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (i == 0)
            {
                out.at<u_char>(i, j) = std::max(img.at<u_char>(i, j), img.at<u_char>(i + 1, j));
            }
            else if (i == img.rows - 1)
            {
                out.at<u_char>(i, j) = std::max(img.at<u_char>(i - 1, j), img.at<u_char>(i, j));
            }
            else
            {
                out.at<u_char>(i, j) = std::max(std::max(img.at<u_char>(i - 1, j), img.at<u_char>(i, j)), img.at<u_char>(i + 1, j));
            }
        }
    }
}

void dilation(const cv::Mat *image, cv::Mat *output, u_int size)
{
    horizontalDilation(image, output);
    cv::Mat newReference = (*(output)).clone();
    verticalDilation(&newReference, output);

    if (size > 1)
    {
        newReference = (*(output)).clone();
        dilation(&newReference, output, size - 1);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Error: number of arguments: " << argv[0] << " <dilation size> <input image> <output image>" << std::endl;
        return EXIT_FAILURE;
    }

    // Read the dilation size
    uint DILATION_SIZE = atoi(argv[1]);

    // Read the input image
    cv::Mat image = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    // Read the output fileName
    char *outputFilename = argv[3];

    // Prepare the output image
    cv::Mat output = image.clone();

    // Perform the dilation
    dilation(&image, &output, DILATION_SIZE);

    std::cout << "Saving image " << outputFilename << " ..." << std::endl;
    cv::imwrite(outputFilename, output);

    std::cout << "Showing image in window... Press a key to finish." << std::endl;
    uint winNameLength = strlen("Window: image with dilation size = ") + strlen(argv[1]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: image with dilation size = %d", DILATION_SIZE);
    cv::imshow(winName, output);
    cv::waitKey(0);

    free(winName);

    return EXIT_SUCCESS;
}
