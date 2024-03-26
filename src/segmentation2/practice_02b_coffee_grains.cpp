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

    // Maintain only the grains without detail
    threshold(output, output, 110, 255, THRESH_BINARY_INV);

    Mat newReference = output.clone();
    erosion(&newReference, &output, 1);

    subtract(newReference, output, output);

    vector<vector<Point>> contours;
    Scalar color = Scalar(0, 0, 255);
    findContours(output, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (int i = 0; i < contours.size(); i++)
    {
        drawContours(image, contours, i, color, 1);
    }

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, image);

    imshow("Markers", image);
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}
