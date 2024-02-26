//
// Created by Sergio Marin Sanchez on 25/2/24.
//

#include "exercise_11a_flatzone.hpp"

config readConfigFile(char *configFilename)
{
    config configuration;
    std::fstream file;

    file.open(configFilename, std::ios::in);
    if (file.is_open())
    {
        char *line = (char*) malloc(BUFFER_SIZE * sizeof(char));
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.x = atoi(line);
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.y = atoi(line);
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.connectivity = atoi(line);
        file.getline(line, BUFFER_SIZE * sizeof(char));
        configuration.flatZoneLabel = atoi(line);
        free(line);
    }

    return configuration;
}

neighbourhood getNeighbours8Connectivity(pixel p, u_int height, u_int width)
{
    neighbourhood neighbours;
    pixel neighbour;
    if (p.x == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            if (p.y == 0)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (i == 0 && j == 0) continue;
                    neighbour = pixel(p.x + i, p.y + j);
                    neighbours.push_back(neighbour);
                }
            }
            else if (p.y == width - 1)
            {
                for (int j = -1; j < 1; j++)
                {
                    if (i == 0 && j == 0) continue;
                    neighbour = pixel(p.x + i, p.y + j);
                    neighbours.push_back(neighbour);
                }
            }
            else
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i == 0 && j == 0) continue;
                    neighbour = pixel(p.x + i, p.y + j);
                    neighbours.push_back(neighbour);
                }
            }
        }
    }
    else if (p.x == height - 1)
    {
        for (int i = -1; i < 1; i++)
        {
            if (p.y == 0)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (i == 0 && j == 0) continue;
                    neighbour = pixel(p.x + i, p.y + j);
                    neighbours.push_back(neighbour);
                }
            }
            else if (p.y == width - 1)
            {
                for (int j = -1; j < 1; j++)
                {
                    if (i == 0 && j == 0) continue;
                    neighbour = pixel(p.x + i, p.y + j);
                    neighbours.push_back(neighbour);
                }
            }
            else
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i == 0 && j == 0) continue;
                    neighbour = pixel(p.x + i, p.y + j);
                    neighbours.push_back(neighbour);
                }
            }
        }
    }
    else
    {
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (i == 0 && j == 0) continue;
                neighbour = pixel(p.x + i, p.y + j);
                neighbours.push_back(neighbour);
            }
        }
    }

    return neighbours;
}

neighbourhood getNeighbours4Connectivity(pixel p, u_int height, u_int width)
{
    neighbourhood neighbours;
    pixel neighbour;
    if (p.x == 0)
    {
        if (p.y == 0)
        {
            neighbours.push_back(pixel(p.x, p.y + 1));
            neighbours.push_back(pixel(p.x + 1, p.y));
        }
        else if (p.y == width - 1)
        {
            neighbours.push_back(pixel(p.x, p.y - 1));
            neighbours.push_back(pixel(p.x + 1, p.y));
        }
        else
        {
            neighbours.push_back(pixel(p.x, p.y - 1));
            neighbours.push_back(pixel(p.x, p.y + 1));
            neighbours.push_back(pixel(p.x + 1, p.y));
        }
    }
    else if (p.x == height - 1)
    {
        if (p.y == 0)
        {
            neighbours.push_back(pixel(p.x - 1, p.y));
            neighbours.push_back(pixel(p.x, p.y + 1));
        }
        else if (p.y == width - 1)
        {
            neighbours.push_back(pixel(p.x, p.y - 1));
            neighbours.push_back(pixel(p.x - 1, p.y));
        }
        else
        {
            neighbours.push_back(pixel(p.x, p.y - 1));
            neighbours.push_back(pixel(p.x, p.y + 1));
            neighbours.push_back(pixel(p.x + 1, p.y));
        }
    }
    else
    {
        neighbours.push_back(pixel(p.x - 1, p.y));
        neighbours.push_back(pixel(p.x, p.y - 1));
        neighbours.push_back(pixel(p.x, p.y + 1));
        neighbours.push_back(pixel(p.x + 1, p.y));
    }

    return neighbours;
}

neighbourhood getNeighbours(pixel p, u_int height, u_int width, u_int connectivity)
{
    if (connectivity == 8)
    {
        return getNeighbours8Connectivity(p, height, width);
    }
    else if (connectivity == 4)
    {
        return getNeighbours4Connectivity(p, height, width);
    }
    else
    {
        // Not a valid connectivity
        perror("Not a valid connectivity");
        exit(EXIT_FAILURE);
    }
}

void flatZone(const cv::Mat *image, const cv::Mat *output, config configuration)
{
    u_int LABEL_FZ = configuration.flatZoneLabel;

    cv::Mat img = *(image);
    cv::Mat out = *(output);
    out.at<u_char>(configuration.x, configuration.y) = LABEL_FZ;

    std::queue<pixel> flatZone;

    flatZone.push(pixel(configuration.x, configuration.y));

    while (!flatZone.empty())
    {
        pixel p = flatZone.front();
        flatZone.pop();

        for (pixel neighbour: getNeighbours(p, out.rows, out.cols, configuration.connectivity))
        {
            if ((img.at<u_char>(p.x, p.y) == img.at<u_char>(neighbour.x, neighbour.y)) && (out.at<u_char>(neighbour.x, neighbour.y) != LABEL_FZ))
            {
                out.at<u_char>(neighbour.x, neighbour.y) = LABEL_FZ;
                flatZone.push(neighbour);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Error: number of arguments: " << argv[0] << " <input file> <input image> <output image>" << std::endl;
        return EXIT_FAILURE;
    }

    // Read config input file
    config configuration = readConfigFile(argv[1]);

    // Read input image
    cv::Mat image = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    // Read output image filename
    char *outputFilename = argv[3];

    // Prepare the output image
    cv::Mat output = image.clone().setTo(cv::Scalar::all(LABEL_NO_FZ));

    // Find the flat zone
    flatZone(&image, &output, configuration);

    std::cout << "Saving image " << outputFilename << " ..." << std::endl;
    cv::imwrite(outputFilename, output);

    std::cout << "Showing image in window... Press a key to finish." << std::endl;
    uint winNameLength = strlen("Window: flatzone") + strlen(argv[1]) + 1;
    char *winName = (char*) malloc(winNameLength * sizeof(char));
    snprintf(winName, winNameLength, "Window: flatzone");
    cv::imshow(winName, output);
    cv::waitKey(0);

    free(winName);

    return EXIT_SUCCESS;
}
