
#include "image_activity.h"
#include "file_util.h"

void ImageActivity::OnInit()
{
    SetEventListener();
    FileUtil::FetchFiles(path_, -1, &file_pkg_);
    ShowImage();
}

void ImageActivity::SetEventListener()
{
    SetOnKeyDownListener([=](int key){
        switch (key)
        {
            case 0://up
            {
                ShowPreviousImage();
                break;
            }
            case 1: //down
            {
                ShowNextImage();
                break;
            }
        }
        return true;
    });
}

void ImageActivity::ShowNextImage()
{
    if (image_index_ + 1 >= file_pkg_.name_vec.size())
    {
        return;
    }

    image_index_ ++;
    ShowImage();
}

void ImageActivity::ShowPreviousImage()
{
    if (image_index_ - 1 < 0)
    {
        return;
    }

    image_index_ --;
    ShowImage();
}

void ImageActivity::ShowImage()
{
    if (image_index_ >= 0 && image_index_ < file_pkg_.name_vec.size())
    {
        std::string path(file_pkg_.path);
        path.append(file_pkg_.name_vec[image_index_]);

        mat_ = cv::imread(path, cv::IMREAD_UNCHANGED);
        if (change_listener_)
        {
            change_listener_(mat_, file_pkg_.name_vec[image_index_]);
        }
        Update();
    }
}

