//
// Created by luoyulong on 17/12/16.
//
#include "calibration_activity.h"

int main()
{

    std::string path = "/Users/luoyulong/Documents/D/data/data_object_image_2/testing/image_2/";
    CalibrationActivity activity(path);
    activity.OnInit();
    activity.Show();

    return 0;
}