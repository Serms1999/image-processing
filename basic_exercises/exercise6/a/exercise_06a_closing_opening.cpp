//
// Created by Sergio Marin Sanchez on 24/2/24.
//

#include "opening.hpp"
#include "closing.hpp"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Error: number of arguments: " << argv[0] << " <filter size> <input image> <output image>" << std::endl;
        return EXIT_FAILURE;
    }

    // Read the filter size
    uint FILTER_SIZE = atoi(argv[1]);

    // Read the input image
    cv::Mat image = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    // Read the output fileName
    char *outputFilename = argv[3];

    // Prepare the output image
    cv::Mat output = image.clone();

    // Perform the closing-opening
    opening(&image, &output, FILTER_SIZE);
    cv::Mat newReference = output.clone();
    closing(&newReference, &output, FILTER_SIZE);

    std::cout << "Saving image " << outputFilename << " ..." << std::endl;
    cv::imwrite(outputFilename, output);

    std::cout << "Showing image in window... Press a key to finish." << std::endl;
    uint winNameLength = strlen("Window: image with closing-opening size = ") + strlen(argv[1]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: image with closing-opening size = %d", FILTER_SIZE);
    cv::imshow(winName, output);
    cv::waitKey(0);

    free(winName);

    return EXIT_SUCCESS;
}
