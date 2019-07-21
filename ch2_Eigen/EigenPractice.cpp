//
// Created by qian on 19-7-21.
//
#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

using namespace Eigen;
int main( int argc, char** argv ){

    Eigen::Quaterniond q1= Eigen::Quaterniond (0.2,0.55, 0.3, 0.2).normalized();
    Eigen::Quaterniond q2= Eigen::Quaterniond (0.2,-0.1, 0.3, -0.7).normalized();

    //四元数转换成选择矩阵
    Eigen::Matrix3d Rotation_matrix1 = q1.toRotationMatrix();
    Eigen::Matrix3d Rotation_matrix2 = q2.toRotationMatrix();

    Eigen::Vector3d t1;
    t1<<0.7, 1.1, 0.2;
    Eigen::Vector3d t2;
    t2<<-0.1, 0.4, 0.8;
    Eigen::Vector3d p1;
    p1<<0.5, -0.1, 0.2;
    Eigen::Vector3d p2;

//    p2= q2*(q1.inverse()*(p1-t1))+t2;//四元数的重载乘法只适用于向量，不能用于矩阵变量
    p2= Rotation_matrix2*(Rotation_matrix1.inverse()*(p1-t1))+t2;//四元数的重载乘法只适用于向量，不能用于矩阵变量
    std::cout<<p2<<std::endl;



    return 0;

}