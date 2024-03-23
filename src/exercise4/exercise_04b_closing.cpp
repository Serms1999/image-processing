//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "closing.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>

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

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <closing size> <input image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read the opening size
    u_int CLOSING_SIZE = atoi(argv[1]);

    // Read the input image
    Mat image = imread(argv[2], IMREAD_GRAYSCALE);

    // Read the output fileName
    char *outputFilename = argv[3];

    // Prepare the output image
    Mat output = image.clone();

    // Perform the opening
    closing(&image, &output, CLOSING_SIZE);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    cout << "Showing image in window... Press a key to finish." << endl;
    u_int winNameLength = strlen("Window: image with closing size = ") + strlen(argv[1]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: image with closing size = %d", CLOSING_SIZE);
    imshow(winName, output);
    waitKey(0);
    destroyAllWindows();

    free(winName);

    return EXIT_SUCCESS;
}

