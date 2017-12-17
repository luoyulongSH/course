
#include "label_view.h"

void LabelView::Draw(cv::Mat& mat)
{
    if (IsSelected())
    {
        cv::rectangle(mat, rect_, bg_color_, -1);
    }
    else
    {
        cv::rectangle(mat, rect_, bg_color_, 1);
    }

    int left = (rect_.width - text_size_.width) / 2 + rect_.x;
    int bottom = (rect_.height + text_size_.height) / 2 + rect_.y;

    cv::putText(mat, text_, cv::Point(left, bottom), 1, 1, text_color_);
}


