//
// Created by Sergio Marin Sanchez on 25/3/24.
//

#include "practice_02b_coffee_grains.h"

using cv::Mat;
using cv::Point;
using cv::imread;
using cv::IMREAD_COLOR;
using cv::cvtColor;
using cv::subtract;
using cv::COLOR_BGR2GRAY;
using cv::THRESH_BINARY_INV;
using cv::RETR_EXTERNAL;
using cv::CHAIN_APPROX_SIMPLE;
using cv::Scalar;
using cv::Vec3b;
using cv::watershed;
using cv::threshold;
using cv::findContours;
using cv::drawContours;
using cv::imwrite;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

using std::cout;
using std::cerr;
using std::endl;
using std::vector;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read input image
    Mat image = imread(argv[1], IMREAD_COLOR);

    // Read the output filename
    char *outputFilename = argv[2];

    // Obtain grayscale image
    Mat output;
    cvtColor(image, output, COLOR_BGR2GRAY);

    // Maintain only the grains shape without detail
    threshold(output, output, 122 , 180, THRESH_BINARY_INV);

    // Find contours
    vector<vector<Point>> contours;
    Scalar markerColor = Scalar(0, 0, 255);
    findContours(output, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Build the mask
    Mat markers = Mat(image.size(), CV_32SC1, Scalar(0));
    for (int i = 0; i < contours.size(); i++)
    {
        drawContours(markers, contours, i, Scalar(i + 1), 1);
    }

    // Perform watershed algorithm
    watershed(image, markers);
    output = Mat(image.size(), CV_8UC3, Scalar(0, 0, 0));

    // Assign original color or the contour color
    Vec3b contourColor = Vec3b(0, 0, 255);
    Vec3b pixelColor;
    for (int i = 0; i < markers.rows; i++)
    {
        for (int j = 0; j < markers.cols; j++)
        {
            pixelColor = markers.at<int>(i, j) == -1
                    ? contourColor
                    : image.at<Vec3b>(i, j);
            output.at<Vec3b>(i, j) = pixelColor;
        }
    }

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    imshow("Markers", output);
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}
