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

class KDTree{
    // members cannot be accessed (or viewed) from outside the class
    private:

    int anchor_point =1500;
    int knn = 200;
    double radius = 0.2;
    
    //----- Create a pointer to store the point cloud -----    
    shared_ptr<open3d::geometry::PointCloud> cloud_ptr = make_shared<open3d::geometry::PointCloud>();
    //----- Create a pointer to store the point cloud -----
    // This is what it will be     
    shared_ptr<open3d::geometry::PointCloud> pcd = make_shared<open3d::geometry::PointCloud>();

    // chair point cloud     
    shared_ptr<open3d::geometry::PointCloud> chair = make_shared<open3d::geometry::PointCloud>();
    
    // if the point cloud contains points.
    bool pointcloud_has_normal = false;

    //----- Build a KDTree -----//
    //open3d::geometry::KDTreeFlann kdtree;
    open3d::geometry::KDTreeFlann kd_tree_;

    // members cannot be accessed from outside the class, 
    // however, they can be accessed in inherited classes. 
    protected:  

    // members are accessible from outside the class
    public:
    KDTree(){
        // constructor
    }
    ~KDTree(){
        // destructor
    }
    // path to the PC
    string path_2_pc;    

    void load_PC();
    void visualize_PC();
    void point_paint();
    void paint_gray();
    void KNN();
    void SearchRadius();
    void HybridSearch();

};