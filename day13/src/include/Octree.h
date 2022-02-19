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

class Octree{
    // members cannot be accessed (or viewed) from outside the class
    private: 

    void PrintVoxelGridInformation(const open3d::geometry::VoxelGrid& voxel_grid);   
    

    size_t max_depth = 5;
    shared_ptr<open3d::geometry::Octree>       octree = make_shared<open3d::geometry::Octree>(max_depth);

    shared_ptr<open3d::geometry::PointCloud>   pcd     = make_shared<open3d::geometry::PointCloud>();
       
    shared_ptr<open3d::geometry::TriangleMesh> mesh    = make_shared<open3d::geometry::TriangleMesh>();


    
    protected:  

    // members are accessible from outside the class
    public:
    Octree(){
        // constructor
    }
    ~Octree(){
        // destructor
    }
    // path to the PC
    string path_2_mesh; 
  

    void load_as_mesh(); 
    void scale();
    void octree_division();
    void voxelization();
    
};
