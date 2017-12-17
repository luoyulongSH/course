//
// Created by luoyulong on 17/12/16.
//

#include "base_activity.h"

BaseActivity::~BaseActivity()
{
    for (View* view : views_)
    {
        delete  view;
    }
}

void BaseActivity::Update()
{
    draw_mat_ = mat_.clone();

    for (View* view : views_)
    {
        view->Draw(draw_mat_);
    }
    cv::imshow(name_, draw_mat_);
}

void BaseActivity::OnKeyDown(int key)
{
    //printf("%d\n", key);
    if (key == 27) //esc
    {
        focus_index_ = -1;
        return;
    }


    if (focus_index_ == -1)
    {
        if (key_listener_)
        {
            key_listener_(key);
        }
    }
    else
    {
        views_[focus_index_]->OnKeyDown(key);
    }
}

void BaseActivity::OnMouseClick(int x, int y)
{
    cv::Point point(x, y);
    bool consume  = false;
    for (size_t i = 0; i < views_.size(); ++i)
    {
        View *view = views_[i];
        if (view->Contain(point))
        {
            if (view->get_focus_enable())
            {
                focus_index_ = i;
            }

            consume = view->OnMouseClick(x, y);

            if (consume)
            {
                break;
            }
        }
    }

    if (!consume)
    {
        if (mouse_listener_)
        {
            mouse_listener_(x, y);
        }
    }
}

static void OnMouseEvent(int event, int x, int y, int flags, void* userdata)
{
    BaseActivity* activity = (BaseActivity*) userdata;
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        activity->OnMouseClick(x, y);
    }
}

void BaseActivity::Show()
{
    Update();
    cv::setMouseCallback(name_, OnMouseEvent, this);
    while (true) {
        int key = cv::waitKey();
        if (key == -1) {
            break;
        }
        OnKeyDown(key);
    }
}