//
// Created by Sergio Marin Sanchez on 22/3/24.
//

#include "neighbors.h"

#include <iostream>
#include <cstdlib>

using cv::Point;

using std::cerr;
using std::endl;

neighbourhood getNeighbours8Connectivity(Point p, u_int height, u_int width, u_int size = 1)
{
    neighbourhood neighbors;
    int signedSize = static_cast<int>(size);

    for (int i = -signedSize; i <= signedSize; i++)
    {
        for (int j = -signedSize; j <= signedSize; j++)
        {
            if (i == 0 && j == 0) continue;
            // Exclude the center Point itself
            int nx = p.x + i;
            int ny = p.y + j;
            if (nx >= 0 && nx < height && ny >= 0 && ny < width)
            {
                // Add the valid neighbor to the list
                neighbors.emplace_back(nx, ny);
            }
        }
    }

    return neighbors;
}

neighbourhood getNeighbours4Connectivity(Point p, u_int height, u_int width, u_int size = 1)
{
    neighbourhood neighbors;
    int signedSize = static_cast<int>(size);

    // Add the vertical neighbors
    for (int i = -signedSize; i <= signedSize; i++)
    {
        if (i == 0) continue;
        int nx = p.x + i;
        int ny = p.y;
        if (nx >= 0 && nx < height && ny >= 0 && ny < width)
        {
            // Add the valid neighbor to the list
            neighbors.emplace_back(nx, ny);
        }
    }

    // Add the horizontal neighbors
    for (int j = -signedSize; j <= signedSize; j++)
    {
        if (j == 0) continue;
        int nx = p.x;
        int ny = p.y + j;
        if (nx >= 0 && nx < height && ny >= 0 && ny < width)
        {
            // Add the valid neighbor to the list
            neighbors.emplace_back(nx, ny);
        }
    }

    return neighbors;
}

neighbourhood getNeighbours(Point p, u_int height, u_int width, u_int connectivity, u_int size)
{
    switch (connectivity)
    {
        case 8:
            return getNeighbours8Connectivity(p, height, width, size);
        case 4:
            return getNeighbours4Connectivity(p, height, width, size);
        default:
            // Not a valid connectivity
            cerr << "Error: " << connectivity << " is not a valid connectivity. Pick 8 or 4." << endl;
            exit(EXIT_FAILURE);
    }
}
