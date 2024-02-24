//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "exercise_04a_opening.hpp"

#include "dilation.hpp"
#include "erosion.hpp"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>


void opening(const cv::Mat *image, cv::Mat *output, u_int size)
{
    erosion(image, output, size);
    cv::Mat newReference = (*(output)).clone();
    dilation(&newReference, output, size);
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Error: number of arguments: " << argv[0] << " <opening size> <input image> <output image>" << std::endl;
        return EXIT_FAILURE;
    }

    // Read the opening size
    uint OPENING_SIZE = atoi(argv[1]);

    // Read the input image
    cv::Mat image = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    // Read the output fileName
    char *outputFilename = argv[3];

    // Prepare the output image
    cv::Mat output = image.clone();

    // Perform the opening
    opening(&image, &output, OPENING_SIZE);

    std::cout << "Saving image " << outputFilename << " ..." << std::endl;
    cv::imwrite(outputFilename, output);

    return EXIT_SUCCESS;
}

