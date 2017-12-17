//
// Created by luoyulong on 17/12/16.
//

#include "calibration_activity.h"

void CalibrationActivity::OnInit()
{
    set_activity_name("Calibration");
    text_view_ = new LabelView(this, 10, 10, 150, 100);
    AddView(text_view_);

    set_image_change_listener([&](cv::Mat& mat, const std::string& name){
        text_view_->set_text(name);
    });

    ImageActivity::OnInit();
}

