//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

#include "infimum.h"

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
    if (argc < 3)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input image 1> <input image 2> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read the input images
    Mat image1 = imread(argv[1], IMREAD_GRAYSCALE);
    Mat image2 = imread(argv[2], IMREAD_GRAYSCALE);

    // Read output filename
    char *outputFilename = argv[3];

    // Prepare output image
    Mat output = Mat::zeros(image1.size(), CV_8UC1);

    infimum(&image1, &image2, &output);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    cout << "Showing image in window... Press a key to finish." << endl;
    u_int winNameLength = strlen("Window: infimum of the images") + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: infimum of the images");
    imshow(winName, output);
    waitKey(0);
    destroyAllWindows();

    free(winName);

    return EXIT_SUCCESS;
}
