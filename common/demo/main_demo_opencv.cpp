#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    cv::Mat image(200, 300, CV_8UC1,  cv::Scalar(255));
    cv::putText(image, "Hallo", cv::Point(100,100), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0));
    namedWindow( "Display window", WINDOW_AUTOSIZE ); 
    imshow( "Display window", image );                   
    waitKey(0); 
    return 0;
}
