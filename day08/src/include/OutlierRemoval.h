#include <iostream>
#include <memory>
#include <thread>
#include <random>
#include <cstdlib>
#include <Eigen/Dense>
#include "open3d/Open3D.h"
#include <experimental/filesystem>
#include <unistd.h> //getcwd - get the pathname of the current working directory

using namespace std;
namespace fs = experimental::filesystem;

class OutRemove{
    // members cannot be accessed (or viewed) from outside the class
    private:   
    // if the point cloud contains points.
    bool pointcloud_has_normal = false;

    //----- Create a pointer to store the point cloud -----    
    shared_ptr<open3d::geometry::PointCloud> cloud_ptr     = make_shared<open3d::geometry::PointCloud>();
    //----- Create a pointer to store the point cloud -----
    // This is what it will be     
    shared_ptr<open3d::geometry::PointCloud> pcd           = make_shared<open3d::geometry::PointCloud>();

    // define inlier and outlier pointers
    shared_ptr<open3d::geometry::PointCloud> inlier_cloud  = make_shared<open3d::geometry::PointCloud>();    
    shared_ptr<open3d::geometry::PointCloud> outlier_cloud = make_shared<open3d::geometry::PointCloud>();      

    // members cannot be accessed from outside the class, 
    // however, they can be accessed in inherited classes. 
    protected:  

    // members are accessible from outside the class
    public:
    OutRemove(){
        // constructor
    }
    ~OutRemove(){
        // destructor
    }
    // path to the PC
    string path_2_pc;    

    void load_PC();
    void visualize_PC();
    void paint_gray();
    void DownSample_PC();
    void Stat_outlier_removal();
    void Radius_outlier_removal();
};
