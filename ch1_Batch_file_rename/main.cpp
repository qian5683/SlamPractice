#include <iostream>
#include <opencv2/opencv.hpp>
#include<stdio.h>

using namespace std;
using namespace cv;

int main()
{
    cv::Mat outImage;
    cv::String src_path =  "/home/qian/rgbd_dataset_freiburg1_desk/rgb";
    cv::String newName_path = "/home/qian/rgbd_dataset_freiburg1_desk/output/";
    char newName[10];
    std::vector<String> filenames;
    cv::glob(src_path, filenames);//获取路径下所有文件名
    cout << "filenames.size:" << filenames.size() << endl;
    for(int i = 0; i < filenames.size(); i++)
    {
        String ImgName = filenames[i];
        if(ImgName.find(".png") != String::npos)//匹配.png文件
        {
            outImage = imread(ImgName,CV_LOAD_IMAGE_UNCHANGED);//CV_LOAD_IMAGE_UNCHANGED以原始图像读取

            sprintf(newName, "%04d.png", i);
            imwrite(newName_path+newName, outImage);//文件夹必须提前创建，否则代码执行没有效果
            cout << newName_path+newName << endl;
        }
        else
        {
            cout << "NOT A PNG IMAGE" << endl;
        }
    }
    return 0;
}
