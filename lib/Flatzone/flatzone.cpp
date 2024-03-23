//
// Created by Sergio Marin Sanchez on 22/3/24.
//

#include "neighbors.h"
#include "flatzone.h"

using cv::Mat;
using cv::Point;

using std::queue;

void reconstructFlatZone(const Mat *image, const Mat *output, const Point pixel,
                         const u_int connectivity, const u_int labelFz){
    Mat img = *(image);
    Mat out = *(output);
    out.at<u_char>(pixel) = labelFz;

    queue<Point> flatZone;

    flatZone.push(pixel);

    while (!flatZone.empty())
    {
        Point p = flatZone.front();
        flatZone.pop();

        for (Point neighbour: getNeighbours(p, out.rows, out.cols, connectivity))
        {
            if ((img.at<u_char>(p.x, p.y) == img.at<u_char>(neighbour.x, neighbour.y)) && (out.at<u_char>(neighbour.x, neighbour.y) != labelFz))
            {
                out.at<u_char>(neighbour.x, neighbour.y) = labelFz;
                flatZone.push(neighbour);
            }
        }
    }
}

u_short flatZoneCount(const Mat *image, const Mat *output, const u_int connectivity)
{
    Mat img = *(image);
    Mat out = *(output);

    u_short numberOfFlatZones = 0;
    queue<Point> flatZone;
    Point p;
    u_short currentLabel;

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (out.at<u_short>(i, j) != LABEL_NO_FZ) continue;

            currentLabel = ++numberOfFlatZones;
            out.at<u_short>(i, j) = currentLabel;
            flatZone.push(Point(i, j));

            while (!flatZone.empty())
            {
                p = flatZone.front();
                flatZone.pop();

                for (Point neighbour: getNeighbours(p, img.rows, img.cols, connectivity))
                {
                    if ((img.at<u_char>(p.x, p.y) == img.at<u_char>(neighbour.x, neighbour.y)) && (out.at<u_short>(neighbour.x, neighbour.y) == LABEL_NO_FZ))
                    {
                        out.at<u_short>(neighbour.x, neighbour.y) = currentLabel;
                        flatZone.push(neighbour);
                    }
                }
            }
        }
    }

    return numberOfFlatZones;
}

bool flatZoneMinimum(const Mat *image, const Mat *output, const cv::Point pixel,
                     const u_int connectivity, const u_int labelFz)
{
    Mat img = *(image);
    Mat out = *(output);
    out.at<u_char>(pixel) = labelFz;

    queue<Point> flatZone;

    flatZone.push(pixel);

    while (!flatZone.empty())
    {
        Point p = flatZone.front();
        flatZone.pop();

        for (Point neighbour: getNeighbours(p, out.rows, out.cols, connectivity))
        {
            if ((img.at<u_char>(p.x, p.y) == img.at<u_char>(neighbour.x, neighbour.y)) && (out.at<u_char>(neighbour.x, neighbour.y) != labelFz))
            {
                out.at<u_char>(neighbour.x, neighbour.y) = labelFz;
                flatZone.push(neighbour);
            }
            else if (img.at<u_char>(p.x, p.y) > img.at<u_char>(neighbour.x, neighbour.y))
            {
                return false;
            }
        }
    }

    return true;
}

bool flatZoneMaximum(const Mat *image, const Mat *output, const cv::Point pixel,
                     const u_int connectivity, const u_int labelFz)
{
    Mat img = *(image);
    Mat out = *(output);
    out.at<u_char>(pixel) = labelFz;

    queue<Point> flatZone;

    flatZone.push(pixel);

    while (!flatZone.empty())
    {
        Point p = flatZone.front();
        flatZone.pop();

        for (Point neighbour: getNeighbours(p, out.rows, out.cols, connectivity))
        {
            if ((img.at<u_char>(p.x, p.y) == img.at<u_char>(neighbour.x, neighbour.y)) && (out.at<u_char>(neighbour.x, neighbour.y) != labelFz))
            {
                out.at<u_char>(neighbour.x, neighbour.y) = labelFz;
                flatZone.push(neighbour);
            }
            else if (img.at<u_char>(p.x, p.y) < img.at<u_char>(neighbour.x, neighbour.y))
            {
                return false;
            }
        }
    }

    return true;
}
