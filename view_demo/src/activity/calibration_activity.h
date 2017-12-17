//
// Created by luoyulong on 17/12/16.
//

#ifndef VIEW_DEMO_CALIBRATION_ACTIVITY_H
#define VIEW_DEMO_CALIBRATION_ACTIVITY_H
#include "image_activity.h"

#include "label_view.h"
class CalibrationActivity: public ImageActivity
{

public:

    CalibrationActivity(const std::string& path)
    {
        set_image_path(path);
    }

    virtual void OnInit() override;


private:
    LabelView* text_view_;

};


#endif //VIEW_DEMO_CALIBRATION_ACTIVITY_H
