//
//  FindCenter.hpp
//  Teste_OpenCV
//
//  Created by Marina Silva Tavares on 27/11/18.
//  Copyright © 2018 Marina Silva Tavares. All rights reserved.
//

#ifndef FindCenter_hpp
#define FindCenter_hpp

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/aruco.hpp>
#include <map>
#include <errno.h>
#include <QFile>
#include <QTextStream>
using namespace std;
using namespace cv;

void ArUco (VideoCapture cap, char arquivo[], const char *filename, QFile filename1);

int FindCenter (float x1, float x2, float x3, float x4);

void file_txt (char filename[]);

#endif /* FindCenter_hpp */
