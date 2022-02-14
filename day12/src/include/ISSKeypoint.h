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

class IssKeypoint{
    // members cannot be accessed (or viewed) from outside the class
    private:     
    

    
    // This is what it will be     
    shared_ptr<open3d::geometry::PointCloud> pcd            = make_shared<open3d::geometry::PointCloud>();
    shared_ptr<open3d::geometry::PointCloud> ISS_keypoints  = make_shared<open3d::geometry::PointCloud>();
       
    shared_ptr<open3d::geometry::TriangleMesh> mesh         = make_shared<open3d::geometry::TriangleMesh>();
    // members cannot be accessed from outside the class, 
    // however, they can be accessed in inherited classes.

    
    protected:  

    // members are accessible from outside the class
    public:
    IssKeypoint(){
        // constructor
    }
    ~IssKeypoint(){
        // destructor
    }
    // path to the PC
    string path_2_mesh; 
  

    void load_as_mesh(); 
    void compute_iss_keypoints();
    void kp_visualization();
    
};
