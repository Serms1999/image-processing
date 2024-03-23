//
// Created by Sergio Marin Sanchez on 14/3/24.
//

#include "exercise_13a_minimum.h"

#include "flatzone.h"

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

config readConfigFile(char *configFilename)
{
    config configuration;
    fstream file;

    file.open(configFilename, ios::in);
    if (file.is_open())
    {
        char *line = (char*) malloc(BUFFER_SIZE * sizeof(char));
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.y = atoi(line);
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.x = atoi(line);
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.connectivity = atoi(line);
        free(line);
        file.close();
    }

    return configuration;
}

int writeOutputFile(const char *fileName, bool minimum)
{
    char *output = (char*) malloc(2 * sizeof(char));
    snprintf(output, 2 * sizeof(char), "%c", minimum ? IS_MIN : IS_NOT_MIN);

    int fd;
    if ((fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRGRP | S_IWGRP)) == -1)
    {
        perror("Error writing the output file");
        free(output);
        return EXIT_FAILURE;
    }
    if (write(fd, output, strlen(output)) == -1)
    {
        perror("Error writing the output file");
        close(fd);
        free(output);
        return EXIT_FAILURE;
    }

    close(fd);
    free(output);
    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input file> <input image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read config input file
    config configuration = readConfigFile(argv[1]);

    // Read input image
    Mat image = imread(argv[2], IMREAD_GRAYSCALE);

    // Read output image filename
    char *outputFilename = argv[3];

    // Prepare the output image
    Mat output = image.clone().setTo(Scalar::all(LABEL_NO_FZ));

    // Find the flat zone
    bool minimum = flatZoneMinimum(&image, &output, Point(configuration.x, configuration.y),
                                   configuration.connectivity, LABEL_FZ);

    return writeOutputFile(outputFilename, minimum);
}
