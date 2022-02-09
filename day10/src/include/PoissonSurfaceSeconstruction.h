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

class Poisson{
    // members cannot be accessed (or viewed) from outside the class
    private:     
    
    std::vector<double> dentities;

    //----- Create a pointer to store the point cloud -----    
    shared_ptr<open3d::geometry::PointCloud> cloud_ptr     = make_shared<open3d::geometry::PointCloud>();
    //----- Create a pointer to store the point cloud -----
    // This is what it will be     
    shared_ptr<open3d::geometry::PointCloud> pcd            = make_shared<open3d::geometry::PointCloud>();
    shared_ptr<open3d::geometry::PointCloud> pcd_2          = make_shared<open3d::geometry::PointCloud>();
       
    shared_ptr<open3d::geometry::TriangleMesh> mesh         = make_shared<open3d::geometry::TriangleMesh>();
    shared_ptr<open3d::geometry::TriangleMesh> mesh_2       = make_shared<open3d::geometry::TriangleMesh>();
    // members cannot be accessed from outside the class, 
    // however, they can be accessed in inherited classes.

    void load_as_mesh(); 
    protected:  

    // members are accessible from outside the class
    public:
    Poisson(){
        // constructor
    }
    ~Poisson(){
        // destructor
    }
    // path to the PC
    string path_2_pc; 
    // path to the msh
    string path_2_pc_2;   

    void load_PC();
    void poisson_surface_reconstruction();
    void density_visualization();
    void mesh_2_pc();
    void alpha_shape();
    void ball_pivoting();
    void normal_estimation();
    
};
