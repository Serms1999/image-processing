//
// Created by Sergio Marin Sanchez on 22/3/24.
//

#include "neighbors.h"

#include <iostream>
#include <cstdlib>

using cv::Point;

using std::cerr;
using std::endl;

neighbourhood getNeighbours8Connectivity(Point p, u_int height, u_int width)
{
    neighbourhood neighbors;

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
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

neighbourhood getNeighbours4Connectivity(Point p, u_int height, u_int width)
{
    neighbourhood neighbors;

    // Add the top neighbor
    if (p.x > 0)
        neighbors.emplace_back(p.x - 1, p.y);

    // Add the left neighbor
    if (p.y > 0)
        neighbors.emplace_back(p.x, p.y - 1);

    // Add the right neighbor
    if (p.y < width - 1)
        neighbors.emplace_back(p.x, p.y + 1);

    // Add the bottom neighbor
    if (p.x < height - 1)
        neighbors.emplace_back(p.x + 1, p.y);

    return neighbors;
}

neighbourhood getNeighbours(Point p, u_int height, u_int width, u_int connectivity)
{
    switch (connectivity)
    {
        case 8:
            return getNeighbours8Connectivity(p, height, width);
        case 4:
            return getNeighbours4Connectivity(p, height, width);
        default:
            // Not a valid connectivity
            cerr << "Error: " << connectivity << " is not a valid connectivity. Pick 8 or 4." << endl;
            exit(EXIT_FAILURE);
    }
}
