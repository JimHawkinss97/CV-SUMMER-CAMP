#include "filter.h"


 Mat GrayFilter::ProcessImage(Mat image) {
	 Mat res;
     cvtColor(image, res, cv::COLOR_RGB2GRAY);
	 return res;
}

/*ResizeFilter::ResizeFilter(int newWidth, int newHeight)
{
	width = newWidth;  height = newHeight;
}

//Mat ResizeFilter::ProcessImage(Mat image)
{
	Mat dst;
	cv::resize(image, dst, Size( width, height));
	return dst;
}*/
