//
// Created by luoyulong on 17/12/16.
//

#ifndef VIEW_DEMO_VIEW_DEF_H
#define VIEW_DEMO_VIEW_DEF_H

#include <functional>
#include <opencv2/opencv.hpp>

typedef std::function<bool(int)> KeyListener;
typedef std::function<bool(int, int)> MouseClickListener;
typedef std::function<void(cv::Mat&, const std::string&)> ImageChangeListener;



#endif //VIEW_DEMO_VIEW_DEF_H
