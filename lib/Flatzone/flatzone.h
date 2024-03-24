//
// Created by Sergio Marin Sanchez on 22/3/24.
//

#ifndef IMAGE_PROCESSING_FLATZONE_H
#define IMAGE_PROCESSING_FLATZONE_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "queue"

#define LABEL_NO_FZ 0

void reconstructFlatZone(const cv::Mat *image, const cv::Mat *output, const cv::Point pixel,
                         const u_int connectivity, const u_int labelFz);

u_short flatZoneCount(const cv::Mat *image, const cv::Mat *output, const u_int connectivity);

bool flatZoneMinimum(const cv::Mat *image, const cv::Mat *output, const cv::Point pixel,
                        const u_int connectivity, const u_int labelFz);

bool flatZoneMaximum(const cv::Mat *image, const cv::Mat *output, const cv::Point pixel,
                        const u_int connectivity, const u_int labelFz);

void regionalMinima(const cv::Mat *image, const cv::Mat *output, const u_int connectivity, const u_int labelFz);

void regionalMaxima(const cv::Mat *image, const cv::Mat *output, const u_int connectivity, const u_int labelFz);

#endif //IMAGE_PROCESSING_FLATZONE_H
