//
// Created by Sergio Marin Sanchez on 24/3/24.
//

#include "practice_01b_grassfire_algorithm.h"

using cv::Mat;
using cv::Point;
using cv::Vec3b;
using cv::imread;
using cv::IMREAD_GRAYSCALE;
using cv::Scalar;
using cv::imwrite;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

using std::cout;
using std::cerr;
using std::fstream;
using std::ios;
using std::queue;
using std::endl;

config readConfigFile(char *configFilename)
{
    config configuration{};
    fstream file;

    file.open(configFilename, ios::in);
    if (file.is_open())
    {
        char *line = (char*) malloc(BUFFER_SIZE * sizeof(char));
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.connectivity = atoi(line);
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.size = atoi(line);
        free(line);
        file.close();
    }

    return configuration;
}

void grassfire(const Mat *image, const Mat *output, const u_int connectivity, const u_int size)
{
    Mat img = *(image);
    Mat out = *(output);

    queue<Point> currentRegion;
    Point p;
    Vec3b currentLabel;
    Vec3b LABEL_NO_RG = Vec3b(0, 0, 0);

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (img.at<u_char>(i, j) == BLACK_PIXEL || out.at<Vec3b>(i, j) != LABEL_NO_RG) continue;

            currentLabel = Vec3b(rand() % 256, rand() % 256, rand() % 256);
            out.at<Vec3b>(i, j) = currentLabel;
            currentRegion.emplace(i, j);

            while (!currentRegion.empty())
            {
                p = currentRegion.front();
                currentRegion.pop();

                for (Point neighbour: getNeighbours(p, img.rows, img.cols, connectivity, size))
                {
                    if ((img.at<u_char>(p.x, p.y) == img.at<u_char>(neighbour.x, neighbour.y)) && (out.at<Vec3b>(neighbour.x, neighbour.y) == LABEL_NO_RG))
                    {
                        out.at<Vec3b>(neighbour.x, neighbour.y) = currentLabel;
                        currentRegion.push(neighbour);
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cerr << "Error: number of arguments: " << argv[0] << "<input fil> <input image> <output image>" << endl;
        return EXIT_FAILURE;
    }

    // Read config file
    config configuration = readConfigFile(argv[1]);

    // Read the input image
    Mat image = imread(argv[2], IMREAD_GRAYSCALE);

    // Reading the output filename
    char *outputFilename = argv[3];

    // Prepare the output image
    Mat output = Mat(image.size(), CV_8UC3, Scalar(0, 0, 0));

    grassfire(&image, &output, configuration.connectivity, configuration.size);

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    cout << "Showing image in window... Press a key to finish." << endl;
    u_int winNameLength = strlen("Window: regions of image: ") + strlen(argv[1]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: regions of image: %s", argv[1]);
    imshow(winName, output);
    waitKey(0);
    destroyAllWindows();

    free(winName);

    return EXIT_SUCCESS;
}
