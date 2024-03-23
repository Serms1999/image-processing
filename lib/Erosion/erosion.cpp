//
// Created by Sergio Marin Sanchez on 23/2/24.
//

#include "erosion.h"

void horizontalErosion(const cv::Mat *image, cv::Mat *output)
{
    cv::Mat img = *(image);
    cv::Mat out = *(output);
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (j == 0)
            {
                out.at<u_char>(i, j) = std::min(img.at<u_char>(i, j), img.at<u_char>(i, j + 1));
            }
            else if (j == img.cols - 1)
            {
                out.at<u_char>(i, j) = std::min(img.at<u_char>(i, j - 1), img.at<u_char>(i, j));
            }
            else
            {
                out.at<u_char>(i, j) = std::min(std::min(img.at<u_char>(i, j - 1), img.at<u_char>(i, j)), img.at<u_char>(i, j + 1));
            }
        }
    }
}

void verticalErosion(const cv::Mat *image, cv::Mat *output)
{
    cv::Mat img = *(image);
    cv::Mat out = *(output);
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (i == 0)
            {
                out.at<u_char>(i, j) = std::min(img.at<u_char>(i, j), img.at<u_char>(i + 1, j));
            }
            else if (i == img.rows - 1)
            {
                out.at<u_char>(i, j) = std::min(img.at<u_char>(i - 1, j), img.at<u_char>(i, j));
            }
            else
            {
                out.at<u_char>(i, j) = std::min(std::min(img.at<u_char>(i - 1, j), img.at<u_char>(i, j)), img.at<u_char>(i + 1, j));
            }
        }
    }
}

void erosion(const cv::Mat *image, cv::Mat *output, u_int size)
{
    horizontalErosion(image, output);
    cv::Mat newReference = (*(output)).clone();
    verticalErosion(&newReference, output);

    if (size > 1)
    {
        newReference = (*(output)).clone();
        erosion(&newReference, output, size - 1);
    }
}
