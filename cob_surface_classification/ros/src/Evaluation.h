/*
 * Evaluation.h
 *
 *  Created on: Jul 10, 2013
 *      Author: rmb-ce
 */

#ifndef EVALUATION_H_
#define EVALUATION_H_

//package includes
#include "cob_3d_segmentation/cluster_handler.h"
#include <cob_3d_segmentation/cluster_classifier.h>
#include <cob_3d_segmentation/depth_segmentation.h>
#include <cob_3d_mapping_common/label_defines.h>
#include "scene_recording.h"

//pcl
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_types_conversion.h>

// opencv
#include <opencv/cv.h>
#include <opencv/highgui.h>


#include <boost/tuple/tuple.hpp>


class Evaluation {
public:
	Evaluation();
	virtual ~Evaluation();

	typedef cob_3d_segmentation::PredefinedSegmentationTypes ST;
    inline void setClusterHandler(ST::CH::Ptr cHdl) { clusterHandler = cHdl; }

	int compareClassification(std::string gt_filename);
	int compareClassification(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr gt, cv::Mat gt_color_image);


private:
	std::string search_directory;
	Scene_recording rec;


	ST::CH::Ptr clusterHandler;

    std::vector<int> color_tab;

	struct count
	{
		int countCorrect ;
		int countCorrectEdge;
		int countCorrectPlane ;
		int countCorrectConc ;
		int countCorrectConv ;
		int countCompared ;
		int countNoColorAssigned ;
		int countEdge ;
		int countPlane ;
		int countConc ;
		int countConv ;
	} ;

	struct percentages
	{
		float plane;
		float edge;
		float conc;
		float conv;
	};

	float divide(float a, float b);
	void compareImagesUsingColor(cv::Mat imOrigin, cv::Mat imComp, Evaluation::count& c);
    void clusterTypesToColorImage(cv::Mat& test_image, unsigned int height,unsigned int width);



};

#endif /* EVALUATION_H_ */
