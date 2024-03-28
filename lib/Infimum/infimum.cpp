//
// Created by Sergio Marin Sanchez on 28/3/24.
//

#include "infimum.h"

using cv::Mat;

using std::cerr;
using std::endl;
using std::min;

void infimum(Mat *image1, Mat *image2, Mat *output)
{
    Mat out = *output;

    // The images should have the same shape
    if ((image1->rows != image2->rows) || (image1->cols != image2->cols))
    {
        cerr << "Images should have the same shape." << endl;
        exit(EXIT_FAILURE);
    }

    // Modify the image
    for (int i = 0; i < image1->rows; i++)
    {
        for (int j = 0; j < image1->cols; j++)
        {
            out.at<u_char>(i, j) = min(image1->at<u_char>(i, j), image2->at<u_char>(i, j));
        }
    }
}
