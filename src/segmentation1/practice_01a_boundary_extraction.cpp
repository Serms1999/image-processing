//
// Created by Sergio Marin Sanchez on 24/3/24.
//

#include "practice_01a_boundary_extraction.h"

using cv::Mat;
using cv::imread;
using cv::IMREAD_GRAYSCALE;
using cv::Scalar;
using cv::subtract;
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
        cerr << "Error: number of arguments: " << argv[0] << " <input image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read the input image
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);

    // Reading the output filename
    char *outputFilename = argv[2];

    // Prepare the output image
    Mat output = Mat(image.size(), CV_8UC1, Scalar(0));

    erosion(&image, &output, EROSION_SIZE);

    subtract(image, output, output);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    cout << "Showing image in window... Press a key to finish." << endl;
    u_int winNameLength = strlen("Window: boundary of image: ") + strlen(argv[1]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: boundary of image: %s", argv[1]);
    imshow(winName, output);
    waitKey(0);
    destroyAllWindows();

    free(winName);

    return EXIT_SUCCESS;
}
