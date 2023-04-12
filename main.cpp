// #include "net.h"
#include "../inc/FaceMeshService.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    cv::Mat img;
    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cout << "Can't open camera" << std::endl;
        return 0;
    }
    FaceMeshService::getInstance()->load("500m");
    while (true)
    {
        cap.read(img);
        auto result = FaceMeshService::getInstance()->detectFacialOrientation(img);
        switch (result)
        {
        case ORIENTATION_t::ORIENTATION_INVALID :
            std::cout << "Invalid" << std::endl;
            break;
        case ORIENTATION_t::ORIENTATION_LEFT :
            std::cout << "Left" << std::endl;
            break;
        case ORIENTATION_t::ORIENTATION_RIGHT :
            std::cout << "Right" << std::endl;
            break;
        case ORIENTATION_t::ORIENTATION_STRAIGHT :
            std::cout << "Straight" << std::endl;
            break;
        }
    }
    return 0;
}