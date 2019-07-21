#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "filter.h"

using namespace cv;
using namespace std;

const char* cmdAbout = "Sample of OpenCV usage. ";

const char* cmdOptions =
"{ i  image         | <none> | image to process        }"
"{ w  width         | <none> | width for image resize  }"
"{ h  height        | <none> | height for image resize }"
"{ q ? help usage   | <none> | print help message      }";

int main(int argc, char** argv)
{
    // Process input arguments
    CommandLineParser parser(argc, argv, cmdOptions);
    parser.about(cmdAbout);

    if (parser.has("help"))
    {
        parser.printMessage();
        return -1;
    }
    if (!parser.check())
    {
        parser.printErrors();
        return -1;
    }
    
    // Load image
    String imgName(parser.get<String>("image"));
	unsigned int newWidth = parser.get<unsigned>("width");
	unsigned int newHeight = parser.get<unsigned>("height");

	Mat image = imread(imgName, IMREAD_COLOR);

    
    // Filter image
	GrayFilter gray;
	//ResizeFilter resFilter(newWidth, newHeight);


    // Show image
	namedWindow("Out", WINDOW_AUTOSIZE);
	namedWindow("GrayFilter", WINDOW_AUTOSIZE);
	//namedWindow("Resize", WINDOW_AUTOSIZE);

	imshow("Out", image);
	imshow("GrayFilter", gray.ProcessImage(image));
	//imshow("Resize", resFilter.ProcessImage(image));

	waitKey(0);
    
    
    
    return 0;
}
