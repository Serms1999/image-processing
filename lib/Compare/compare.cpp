//
// Created by Sergio Marin Sanchez on 28/3/24.
//

#include "compare.h"

using cv::Mat;

bool compare(Mat *image1, Mat *image2)
{
    // If the images shapes do not match, the images can not be equals
    if ((image1->rows != image2->rows) || (image1->cols != image2->cols))
    {
        return false;
    }

    // If they have equal shapes then each pixel has to be checked
    for (int i = 0; i < image1->rows; i++)
    {
        for (int j = 0; j < image1->cols; j++)
        {
            if (image1->at<u_char>(i, j) != image2->at<u_char>(i, j))
            {
                return false;
            }
        }
    }

    // If every pair of pixels are equal then the images are equals
    return true;
}
