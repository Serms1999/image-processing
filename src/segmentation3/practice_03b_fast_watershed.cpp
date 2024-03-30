//
// Created by Sergio Marin Sanchez on 29/3/24.
//

#include "practice_03b_fast_watershed.h"

using cv::Mat;
using cv::Point;
using cv::Vec3b;
using cv::imread;
using cv::IMREAD_COLOR;
using cv::RETR_EXTERNAL;
using cv::CHAIN_APPROX_SIMPLE;
using cv::THRESH_BINARY_INV;
using cv::cvtColor;
using cv::minMaxLoc;
using cv::COLOR_BGR2GRAY;
using cv::Scalar;
using cv::imwrite;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

using std::cout;
using std::cerr;
using std::endl;
using std::queue;
using std::vector;

void fastWatershed(Mat *image, Mat *output)
{
    Mat out = *output;

    int currentLabel = 0;
    u_short currentDistance;
    Point fictitiousPixel = Point(-1, -1);
    Point p, p2;
    queue<Point> fifo;

    Mat imageDistances = Mat::zeros(out.size(), CV_16UC1);

    double min_d, max_d;
    u_char min, max;
    Point minLoc, maxLoc;

    minMaxLoc(*image, &min_d, &max_d, &minLoc, &maxLoc);
    min = image->at<u_char>(minLoc);
    max = image->at<u_char>(maxLoc);

    for (u_short h = min; h <= max; h++)
    {
        for (int i = 0; i < out.rows; i++)
        {
            for (int j = 0; j < out.cols; j++)
            {
                p = Point(i, j);
                if (image->at<u_char>(p.x, p.y) != h) continue;

                out.at<int>(p.x, p.y) = MASK;

                for (Point neighbour : getNeighbours(p, image->rows, image->cols, CONNECTIVITY))
                {
                    if (out.at<int>(neighbour.x, neighbour.y) > 0 || out.at<int>(neighbour.x, neighbour.y) == WSHED)
                    {
                        imageDistances.at<u_short>(p.x, p.y) = 1;
                        fifo.emplace(p);
                        break;
                    }
                }
            }
        }

        currentDistance = 1;
        fifo.emplace(fictitiousPixel);

        while (true)
        {
            p = fifo.front();
            fifo.pop();

            if (p == fictitiousPixel)
            {
                if (fifo.empty()) break;
                fifo.emplace(fictitiousPixel);
                currentDistance++;
                p = fifo.front();
                fifo.pop();
            }

            for (Point neighbour : getNeighbours(p, image->rows, image->cols, CONNECTIVITY))
            {
                if (imageDistances.at<u_short>(neighbour.x, neighbour.y) < currentDistance && (
                        out.at<int>(neighbour.x, neighbour.y) > 0 || out.at<int>(neighbour.x, neighbour.y) == WSHED
                ))
                {
                    if (out.at<int>(neighbour.x, neighbour.y) > 0)
                    {
                        if (out.at<int>(p.x, p.y) == MASK || out.at<int>(p.x, p.y) == WSHED)
                        {
                            out.at<int>(p.x, p.y) = out.at<int>(neighbour.x, neighbour.y);
                        }
                        else if (out.at<int>(p.x, p.y) != out.at<int>(neighbour.x, neighbour.y))
                        {
                            out.at<int>(p.x, p.y) = WSHED;
                        }
                    }
                    else if (out.at<int>(p.x, p.y) == MASK)
                    {
                        out.at<int>(p.x, p.y) = WSHED;
                    }
                }
                else if (out.at<int>(neighbour.x, neighbour.y) == MASK && imageDistances.at<u_short>(neighbour.x, neighbour.y) == 0)
                {
                    imageDistances.at<u_short>(neighbour.x, neighbour.y) = currentDistance + 1;
                    fifo.emplace(neighbour);
                }
            }
        }

        for (int i = 0; i < out.rows; i++)
        {
            for (int j = 0; j < out.cols; j++)
            {
                p = Point(i, j);
                if (image->at<u_char>(p.x, p.y) != h) continue;

                imageDistances.at<u_short>(p.x, p.y) = 0;

                if (out.at<int>(p.x, p.y) == MASK)
                {
                    out.at<int>(p.x, p.y) = ++currentLabel;
                    fifo.emplace(p);

                    while (!fifo.empty())
                    {
                        p2 = fifo.front();
                        fifo.pop();

                        for (Point neighbour : getNeighbours(p2, image->rows, image->cols, CONNECTIVITY))
                        {
                            if (out.at<int>(neighbour.x, neighbour.y) == MASK)
                            {
                                out.at<int>(neighbour.x, neighbour.y) = currentLabel;
                                fifo.emplace(neighbour);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main (int argc,char** argv) {
    if (argc < 3)
    {
        cerr << "Error: number of arguments: " << argv[0] << " <input image> <markers image>" << endl;
        return EXIT_FAILURE;
    }

    // Read input image
    Mat image = imread(argv[1], IMREAD_COLOR);

    // Read the markers filename
    char *outputFilename = argv[2];

    Mat imageGray;
    cvtColor(image, imageGray, COLOR_BGR2GRAY);

    threshold(imageGray, imageGray, 180, 255, THRESH_BINARY_INV);

    Mat markers = Mat::zeros(imageGray.size(),CV_32SC1);
    vector<vector<Point>> contours;
    findContours(imageGray, contours,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Draw the foreground markers
    for (int i = 0; i < contours.size(); i++)
    {
        drawContours(markers, contours, i, Scalar(i + 1), -1);
    }

    fastWatershed(&imageGray,&markers);

    Mat output = Mat::zeros(markers.size(), CV_8UC3);

    // Assign original color or the contour color
    Vec3b contourColor = Vec3b(0, 0, 255);
    Vec3b pixelColor;
    for (int i = 0; i < markers.rows; i++)
    {
        for (int j = 0; j < markers.cols; j++)
        {
            pixelColor = markers.at<int>(i, j) > 1 && markers.at<int>(i, j) <= contours.size()
                         ? contourColor
                         : image.at<Vec3b>(i, j);
            output.at<Vec3b>(i, j) = pixelColor;
        }
    }

    cout << "Saving image " << outputFilename << " ..." << endl;
    imwrite(outputFilename, output);

    imshow("Detected objects", output);
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;
}
