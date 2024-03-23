//
// Created by Sergio Marin Sanchez on 22/2/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

#define WHITE_PIXEL 255
#define BLACK_PIXEL 0

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
        cerr << "Error: number of arguments: " << argv[0] << " <input image> <threshold> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read the input image
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);

    // Setting the threshold
    u_int THRESHOLD = atoi(argv[2]);

    // Reading the output filename
    char *outputFilename = argv[3];

    // Modify the image
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            image.at<u_char>(i, j) = image.at<u_char>(i, j) >= THRESHOLD ? WHITE_PIXEL : BLACK_PIXEL;
        }
    }

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, image);

    cout << "Showing image in window... Press a key to finish." << endl;
    u_int winNameLength = strlen("Window: image with threshold = ") + strlen(argv[2]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: image with threshold = %d", THRESHOLD);
    imshow(winName, image);
    waitKey(0);
    destroyAllWindows();

    free(winName);

    return EXIT_SUCCESS;
}
