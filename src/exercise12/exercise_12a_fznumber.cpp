//
// Created by Sergio Marin Sanchez on 6/3/24.
//

#include "exercise_12a_fznumber.h"
#include "flatzone.h"

#include <iostream>
#include <cstdlib>

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
using std::fstream;
using std::ofstream;
using std::ios;

u_int readConfigFile(char *configFilename)
{
    fstream file;
    u_int connectivity = 0;

    file.open(configFilename, ios::in);
    if (file.is_open())
    {
        char *line = (char*) malloc(BUFFER_SIZE * sizeof(char));
        file.getline(line, BUFFER_SIZE * sizeof(char));
        connectivity = atoi(line);
        free(line);
        file.close();
    }

    return connectivity;
}

int writeOutputFile(const char *fileName, u_int number) {
    // Open the file for writing
    ofstream outputFile(fileName);

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file " << fileName << " for writing." << endl;
        return EXIT_FAILURE;
    }

    // Write the number into the file
    outputFile << number;

    // Check if the writing was successful
    if (outputFile.fail()) {
        cerr << "Error: Failed to write number to file " << fileName << endl;
        return EXIT_FAILURE;
    }

    // Close the file
    outputFile.close();

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cout << "Error: number of arguments: " << argv[0] << " <input file> <input image> <output file>" << endl;
        return EXIT_FAILURE;
    }

    // Read config input file
    u_int connectivity = readConfigFile(argv[1]);

    // Read input image
    Mat image = imread(argv[2], IMREAD_GRAYSCALE);

    // Read output image filename
    char *outputFilename = argv[3];

    // Prepare the auxiliary image
    Mat auxiliary = Mat(image.size(), CV_16UC1, Scalar(LABEL_NO_FZ));

    u_short numberOfFlatZones = flatZoneCount(&image, &auxiliary, connectivity);

    return writeOutputFile(outputFilename, numberOfFlatZones);
}
