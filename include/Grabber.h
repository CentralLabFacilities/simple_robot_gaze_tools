#pragma once

// STD
#include <iostream>
#include <sstream>
#include <string>
#include <mutex>

// ROS
#include "ros/ros.h"

// CV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class Grabber {

public:
    Grabber();
    ~Grabber();
    void grabImage();
    int getCamera();
    void setCapture(int _argc, const char *_argv[], int framerate, bool timing_flag, int width, int height);
    void getImage(ros::Time *timestamp, cv::Mat *mat);

protected:
    ros::Time timestamp;
    cv::VideoCapture cap;
    std::recursive_mutex mtx;
    cv::Mat source_frame;
    cv::Mat output_frame;
    int usingCamera, width, height;
    bool timing;
};
