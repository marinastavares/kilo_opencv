//
//  FindCenter.cpp
//  Teste_OpenCV
//
//  Created by Marina Silva Tavares on 27/11/18.
//  Copyright © 2018 Marina Silva Tavares. All rights reserved.
//

#include "FindCenter.hpp"

int FindCenter (float x1, float x2, float x3, float x4){
    float xf;

    xf=(x1+x2+x3+x4)/4;
    
    return xf;
}

void file_txt (char filename[]){
    
    fstream appendFileToWorkWith;
    
    appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    
    
    // If file does not exist, Create new file
    if (!appendFileToWorkWith )
    {
        cout << "Cannot open file, file does not exist. Creating new file..";
        
        appendFileToWorkWith.open(filename,  fstream::in | fstream::out | fstream::trunc);
        appendFileToWorkWith <<"\n";
        appendFileToWorkWith.close();
        
    }
    else
    {    // use existing file
        cout<<"success "<<filename <<" found. \n";
        cout<<"\nAppending writing and working with existing file"<<"\n---\n";
        
        appendFileToWorkWith << "Appending writing and working with existing file"<<"\n---\n";
        appendFileToWorkWith.close();
        cout<<"\n";
        
    }
    
}




void ArUco (VideoCapture cap, char arquivo[], const char *filename, QFile file) {
    
    int cornersSize;
    float xf,yf;
    stringstream ss;
    string str;
    

    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file);
        stream << "something" << endl;
    }

    file_txt(arquivo);
    
    
    if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
    }
    
    Ptr<cv::aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    
    ofstream file;

    file.open (filename);
    file << " cabou ";

    //unconditional loop
    while(1){
        
        Mat frame;
        // Capture frame-by-frame
        cap >> frame;
        
        if (frame.empty())
            break;
        
        putText(frame,"Kilobots UFSC",Point(10,30),FONT_HERSHEY_SIMPLEX,1,Scalar(128));
        
        std::vector<int> ids;
        std::vector<float> cantos;
        std::vector<vector<cv::Point2f>> corners;
        aruco::detectMarkers(frame, dictionary, corners, ids);
        cv::Point2f pos1,pos2,pos3,pos4;
        std::map <int, cv::Point2f> ListaKilobots;
        
        
        //cout << "Output of begin and end: ";
        //for (auto i = corners.begin(); i != corners.end(); ++i)
        //   cout << *i << " cabou ";
        
        cornersSize = corners.size();
        

;
        for (int k = 0; k < cornersSize; ++k) {
            pos1.x = corners.at(k).at(0).x;
            pos1.y = corners.at(k).at(0).y;
            pos2.x = corners.at(k).at(1).x;
            pos2.y = corners.at(k).at(1).y;
            pos3.x = corners.at(k).at(2).x;
            pos3.y = corners.at(k).at(2).y;
            pos4.x = corners.at(k).at(3).x;
            pos4.y = corners.at(k).at(3).y;
            xf=FindCenter(pos1.x, pos2.x, pos3.x, pos4.x);
            yf=FindCenter(pos1.y, pos2.y, pos3.y, pos4.y);
            ListaKilobots[ids[k]].x=xf;
            ListaKilobots[ids[k]].y=yf;
            ss << ids[k];
            str = ss.str();
            file << str << " " << xf << " , " << yf << "\n";
            stream << xf << "," << yf << endl;
            circle(frame, Point(xf,yf), 40, (0,0,255));
            putText(frame,str,Point(xf+20,yf+20),FONT_HERSHEY_SIMPLEX,1,Scalar(128));
            ss.str(std::string());
        }
        
        // Display the resulting frame
        imshow( "Frame", frame );
        
        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
        
        if(c==27)
            break;
    }


    // When everything done, release the video capture object
    cap.release();

    file.close();

    
    // Closes all the frames
    destroyAllWindows();
    
    
}

