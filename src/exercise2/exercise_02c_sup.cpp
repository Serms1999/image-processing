//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <algorithm>
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
using std::max;

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

    // The images should have the same shape
    if ((image1.rows != image2.rows) || (image1.cols != image2.cols))
    {
        cerr << "Images should have the same shape." << endl;
        return EXIT_FAILURE;
    }

    // Modify the image
    for (int i = 0; i < image1.rows; i++)
    {
        for (int j = 0; j < image1.cols; j++)
        {
            image1.at<u_char>(i, j) = max(image1.at<u_char>(i, j), image2.at<u_char>(i, j));
        }
    }

    u_int outputFilenameLength = strlen("exercise_02c_sup_output_01.pgm") + 1;
    char *outputFilename = (char*) malloc(outputFilenameLength);
    snprintf(outputFilename, outputFilenameLength, "exercise_02c_sup_output_01.pgm");
    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, image1);

    cout << "Showing image in window... Press a key to finish." << endl;
    u_int winNameLength = strlen("Window: supremum of the images") + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: supremum of the images");
    imshow(winName, image1);
    waitKey(0);
    destroyAllWindows();

    free(outputFilename);
    free(winName);

    return EXIT_SUCCESS;
}
