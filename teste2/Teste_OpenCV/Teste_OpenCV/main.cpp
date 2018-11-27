
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include <errno.h>
using namespace cv;
using namespace std;


int FindCenterX (float x1, float x2, float x3, float x4){
    float xf;
    
    xf=(x1+x2+x3+x4)/4;
    
    return xf;
}

int main() {
    
    int cornersSize;
    float xf,yf;
    stringstream ss;
    string str;
    
    
    char filename[ ] = "id_xy.txt";
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
    
    
    VideoCapture cap("/Users/marinastavares/Dev_Kilobots/kilobots/kilobots_tests/tentativa1.mov");
    
    if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    
    Ptr<cv::aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    
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
        
        ofstream file;
        file.open ("ids_xy.txt");
        
        for (int k = 0; k < cornersSize; ++k) {
            pos1.x=corners.at(k).at(0).x;
            pos1.y=corners.at(k).at(0).y;
            pos2.x=corners.at(k).at(1).x;
            pos2.y=corners.at(k).at(1).y;
            pos3.x=corners.at(k).at(2).x;
            pos3.y=corners.at(k).at(2).y;
            pos4.x=corners.at(k).at(3).x;
            pos4.y=corners.at(k).at(3).y;
            xf=FindCenterX(pos1.x, pos2.x, pos3.x, pos4.x);
            yf=FindCenterX(pos1.y, pos2.y, pos3.y, pos4.y);
            ListaKilobots[ids[k]].x=xf;
            ListaKilobots[ids[k]].y=yf;
            ss << ids[k];
            str = ss.str();
            circle(frame, Point(xf,yf), 40, (0,0,255));
            putText(frame,str,Point(xf+10,yf+10),FONT_HERSHEY_SIMPLEX,1,Scalar(128));
            ss.str(std::string());
            
        }
        file.close();

        // Display the resulting frame
        imshow( "Frame", frame );
        
        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
        
        if(c==27)
            break;
    }
    
    // When everything done, release the video capture object
    cap.release();
    
    // Closes all the frames
    destroyAllWindows();
    
    return 0;
}
