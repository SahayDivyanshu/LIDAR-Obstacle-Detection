LIDAR Obstacle Detection
In this project a LIDAR Sensor has been used to detect the vehicles on the road. The Lidar data is stored in a format called Point Cloud Data (PCD). A Real-Time stream of PCD will be used to demonstrate LIDAR Obstacle Detection.

Following are the major operations performed:
Segmentation: It is performed to separate the road from obstacle. This operation fits a plane through a set of 3D points. In the project the PCL library has been use to implement the RANSAC algorithm. A 2D implementation can also be found the Quiz.

Clustering: Clustering helps in isolating the regions of interests and helps identifying vehicles. A KDTree has been used to perform the clustering operation. KDTree performs an efficient nearest neighbour search.

Filtering/Downsampling: The processor pipeline to be able to digest point cloud as quickly as possible. Voxel grid filtering will create a cubic grid filters the cloud by only leaving a single point per voxel cube, so the larger the cube length the lower the resolution of the point cloud

