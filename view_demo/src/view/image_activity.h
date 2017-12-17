//
// Created by luoyulong on 17/12/17.
//

#ifndef VIEW_DEMO_IMAGE_ACTIVITY_H
#define VIEW_DEMO_IMAGE_ACTIVITY_H
#include "base_activity.h"
#include "file_util.h"
class ImageActivity : public  BaseActivity
{
public:
    ImageActivity():image_index_(0)
    {}

    virtual void OnInit();

    void ShowNextImage();

    void ShowPreviousImage();

public:
    void set_image_path( const std::string& path)
    {
        path_ = path;
    }

    void set_image_index( int image_index)
    {
        image_index_ = image_index;
    }

    void set_image_change_listener(const ImageChangeListener& listener)
    {
        change_listener_ = listener;
    }



private:
    void SetEventListener();
    void ShowImage();

private:
    std::string path_;
    int image_index_;
    FilePackage file_pkg_;
    ImageChangeListener change_listener_;
};


#endif //VIEW_DEMO_IMAGE_ACTIVITY_H
