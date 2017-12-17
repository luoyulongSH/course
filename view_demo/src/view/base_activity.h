//
// Created by luoyulong on 17/12/16.
//

#ifndef VIEW_DEMO_BASE_ACTIVITY_H
#define VIEW_DEMO_BASE_ACTIVITY_H

#include "view.h"
#include "view_def.h"

#include <string>
class BaseActivity
{
public:
    BaseActivity(): focus_index_(-1)
    {

    }

    ~BaseActivity();

    virtual void OnInit()
    {

    }

    void Update();

    void OnKeyDown(int key);

    void OnMouseClick(int x, int y);

    void SetOnKeyDownListener(const KeyListener& listener)
    {
        key_listener_ = listener;
    }

    void SetOnMouseClickLister(const MouseClickListener& listener)
    {
        mouse_listener_ = listener;
    }

    void set_activity_name(const std::string& name)
    {
        name_ = name;
    }

    void set_activity_name(const char* name)
    {
        name_.assign(name);
    }

    void AddView(View* view)
    {
        views_.push_back(view);
    }

    void AddView(View* view, int index)
    {
        if (index > views_.size() || index < 0)
        {
            return;
        }

        views_.insert(views_.begin() + index, view);
    }

    void Show();
protected:
    std::vector<View*> views_;
    cv::Mat mat_;
    cv::Mat draw_mat_;
    std::string name_;
    int focus_index_;

    KeyListener key_listener_;
    MouseClickListener mouse_listener_;
};


#endif //VIEW_DEMO_BASE_ACTIVITY_H
