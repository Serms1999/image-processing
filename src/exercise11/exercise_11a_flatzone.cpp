//
// Created by Sergio Marin Sanchez on 25/2/24.
//

#include "exercise_11a_flatzone.h"

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
using std::ios;

config readConfigFile(char *configFilename)
{
    config configuration{};
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
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.flatZoneLabel = atoi(line);
        free(line);
        file.close();
    }

    return configuration;
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
    reconstructFlatZone(&image, &output, Point(configuration.x, configuration.y),
                        configuration.connectivity, configuration.flatZoneLabel);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    cout << "Showing image in window... Press a key to finish." << endl;
    imshow("Window: flatzone", output);
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}
