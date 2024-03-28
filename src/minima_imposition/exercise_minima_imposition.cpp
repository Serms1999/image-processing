//
// Created by Sergio Marin Sanchez on 27/3/24.
//

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "compare.h"
#include "infimum.h"
#include "supremum.h"
#include "erosion.h"

using cv::Mat;
using cv::imread;
using cv::IMREAD_GRAYSCALE;
using cv::bitwise_not;
using cv::imwrite;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

using std::cout;
using std::cerr;
using std::endl;

void imMinimaImpose(Mat *imageIn, Mat *imageInMarkers, Mat *imageOut)
{
    // Invert the marker image
    Mat markersInverted;
    bitwise_not(*imageInMarkers, markersInverted);

    Mat imageInMod = Mat::zeros(imageIn->size(), CV_8UC1);
    infimum(imageIn, &markersInverted, &imageInMod);

    Mat markerInvertedNew = Mat::zeros(imageIn->size(), CV_8UC1);
    Mat erosionImage = Mat::zeros(imageIn->size(), CV_8UC1);
    while (true)
    {
        erosion(&markersInverted, &erosionImage, 1);
        supremum(&erosionImage, &imageInMod, &markerInvertedNew);

        if (compare(&markersInverted, &markerInvertedNew))
        {
            break;
        }

        markersInverted = markerInvertedNew.clone();
    }

    *imageOut = markersInverted.clone();
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input file> <input markers image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read input image
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);

    // Read markers image
    Mat imageMarkers = imread(argv[2], IMREAD_GRAYSCALE);

    // Read output image
    char *outputFilename = argv[3];

    Mat output = Mat::zeros(image.size(), CV_8SC1);

    imMinimaImpose(&image, &imageMarkers, &output);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    imshow("Window: Minima imposition", output);
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}
