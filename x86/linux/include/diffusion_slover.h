#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <map>
#include <cmath>
#include <ncnn/net.h>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <ctime>
#include <ncnn/benchmark.h>

using namespace std;

class DiffusionSlover
{
public:
    DiffusionSlover(int h, int w, int mode);

    ncnn::Mat sampler(int seed, int step, ncnn::Mat& c, ncnn::Mat& uc);

private:
    void generate_param(int height, int width);

    ncnn::Mat randn_4(int seed);
    ncnn::Mat CFGDenoiser_CompVisDenoiser(ncnn::Mat& input, float sigma, ncnn::Mat cond, ncnn::Mat uncond);

private:
    float log_sigmas[1000] = { 0 };

    ncnn::Net net;

    int h_size, w_size;
};