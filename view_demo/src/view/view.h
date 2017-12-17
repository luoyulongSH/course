//
// Created by luoyulong on 17/12/16.

#ifndef VIEW_DEMO_VIEW_H
#define VIEW_DEMO_VIEW_H
#include <opencv2/opencv.hpp>
#include <functional>
#include "view_def.h"

class BaseActivity;
class View
{
public:

    View(BaseActivity* activity, int x, int y, int width, int height)
    : rect_ (x, y, width, height), activity_(activity), focus_enable_(false)
    {}

    virtual ~View()
    {}

    virtual void Draw(cv::Mat& mat) = 0;

    virtual bool OnKeyDown(int key)
    {
        if (key_listener_)
        {
            return key_listener_(key);
        }
        return false;
    }

    virtual bool OnMouseClick(int x, int y)
    {
        if (mouse_click_listener_)
        {
            return mouse_click_listener_(x, y);
        }
        return false;
    }

    void Update();

    void SetOnKeyDownListener(const KeyListener& listener)
    {
        key_listener_ = listener;
        focus_enable_ = true;
    }

    void SetMouseClickListener(const MouseClickListener& listener)
    {
        mouse_click_listener_ = listener;
    }

    void SetFocusEnable(bool focus_enable)
    {
        focus_enable_ = focus_enable;
    }

    bool get_focus_enable()
    {
        return focus_enable_;
    }

    inline bool Contain(const cv::Point& point)
    {
        return rect_.contains(point);
    }

protected:
    cv::Rect rect_;
    BaseActivity* activity_;
    bool focus_enable_;

    KeyListener key_listener_;
    MouseClickListener mouse_click_listener_;
};


#endif //VIEW_DEMO_VIEW_H
