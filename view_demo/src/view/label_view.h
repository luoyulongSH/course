//
// Created by luoyulong on 17/12/16.
//

#ifndef VIEW_DEMO_LABEL_VIEW_H
#define VIEW_DEMO_LABEL_VIEW_H

#include "view.h"
class LabelView: public View
{
public:
    LabelView(BaseActivity* context, int x, int y, int width, int height):
            View(context, x, y, width, height), bg_color_(255, 0, 125),  text_color_(255, 33, 36), selected_(true)
    {}

    virtual void Draw(cv::Mat& mat) override ;

    void set_text(const std::string& text)
    {
        text_ = text;
        text_size_ = cv::getTextSize(text_, 1, 1, 1, nullptr);
    }

    bool IsSelected() const
    {
        return selected_;
    }

    void set_selected(bool sel)
    {
        selected_ = sel;
    }

private:
    cv::Scalar bg_color_;
    cv::Scalar text_color_;

    std::string text_;
    cv::Size text_size_;
    bool selected_;


};


#endif //VIEW_DEMO_LABEL_VIEW_H
