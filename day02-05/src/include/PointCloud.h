#include <iostream>
#include <memory>
#include <thread>
#include <random>
#include <cstdlib>
#include <Eigen/Dense>
#include "open3d/Open3D.h"

using namespace std;

class PointCloud{
    // members cannot be accessed (or viewed) from outside the class
    private: 
    
    //----- Create a pointer to store the point cloud -----    
    std::shared_ptr<open3d::geometry::PointCloud> cloud_ptr = std::make_shared<open3d::geometry::PointCloud>();
    //----- Create a pointer to store the point cloud -----
    // This is what it will be     
    std::shared_ptr<open3d::geometry::PointCloud> pcd = std::make_shared<open3d::geometry::PointCloud>();

    // chair point cloud     
    std::shared_ptr<open3d::geometry::PointCloud> chair = std::make_shared<open3d::geometry::PointCloud>();
    
    // if the point cloud contains points.
    bool pointcloud_has_normal = false;

    // members cannot be accessed from outside the class, 
    // however, they can be accessed in inherited classes. 
    protected:  

    // members are accessible from outside the class
    public:
    PointCloud(){
        // constructor
    }
    ~PointCloud(){
        // destructor
    }
    // path to the PC
    string path_2_pc;    

    void load_PC();
    void visualize_PC(); 
    void DownSample_PC();
    void vertex_normal_estimation();
    void crop();
    void paint();
    void remove_chair();
    void DBSCAN();
    void plane_seg();
    void bounding_box();


};