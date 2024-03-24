//
// Created by Sergio Marin Sanchez on 23/3/24.
//

#include "exercise_13c_minima.h"

using cv::Mat;
using cv::Point;
using cv::Scalar;
using cv::imread;
using cv::IMREAD_GRAYSCALE;
using cv::imwrite;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Error: number of arguments: " << argv[0] << " <input image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read input image
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);

    // Read output image filename
    char *outputFilename = argv[2];

    // Prepare the output image
    Mat output = Mat(image.size(), CV_8UC1, Scalar(LABEL_NO_FZ));

    // Compute the regional minima
    regionalMaxima(&image, &output, CONNECTIVITY, LABEL_FZ);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    cout << "Showing image in window... Press a key to finish." << endl;
    imshow("Window: regional maxima", output);
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}
