//
// Created by Sergio Marin Sanchez on 25/3/24.
//

#include "practice_02a_wheel_teeth_count.h"


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
using std::ofstream;

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

    // Remove the teeth
    opening(&image, &output, OPENING_MAINTAIN_TEETH_SIZE);

    // Maintain only the teeth from the original image
    subtract(image, output, output);

    // Remove grain
    Mat newReference = output.clone();
    opening(&newReference, &output, OPENING_REMOVE_GRAIN_SIZE);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    imshow("Window: Teeth and central regions", output);
    waitKey(0);
    destroyAllWindows();

    // Count regions
    newReference = output.clone();
    output = Mat(image.size(), CV_16UC1, Scalar(0));

    u_short regionCount = flatZoneCount(&newReference, &output, CONNECTIVITY);

    // Remove central regions
    regionCount -= 2;

    cout << "Number of teeth: " << regionCount << endl;

    return EXIT_SUCCESS;
}