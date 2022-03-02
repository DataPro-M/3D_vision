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

class ICPReg{
    // members cannot be accessed (or viewed) from outside the class
    private: 

    //void draw_registration_result(const open3d::geometry::PointCloud &source, 
    //                            const open3d::geometry::PointCloud &target,
    //                            const Eigen::Matrix4d &Transforamtion); 
    
    double threshold = 0.02;
    
    // Manually set the transformation matrix
    Eigen::Matrix4d trans_init = Eigen::Matrix4d::Zero();
    
    

    shared_ptr<open3d::geometry::PointCloud>   source       = make_shared<open3d::geometry::PointCloud>();
    shared_ptr<open3d::geometry::PointCloud>   target       = make_shared<open3d::geometry::PointCloud>();
    shared_ptr<open3d::geometry::PointCloud>   source_noisy = make_shared<open3d::geometry::PointCloud>();
    //shared_ptr<Eigen::Matrix4d>        Transforamtion     = make_shared<Eigen::Matrix4d>();
    //shared_ptr<open3d::geometry::TriangleMesh> mesh    = make_shared<open3d::geometry::TriangleMesh>();


    
    protected:  

    // members are accessible from outside the class
    public:
    ICPReg(){
        // constructor
    }
    ~ICPReg(){
        // destructor
    }
    // path to the PC
    string path_2_pc_1; 
    string path_2_pc_2; 
  

    void load_PCs(); 
    void p2p_icp();
    void p2p_icp_iter();
    void p2plane_icp();
    void apply_noise_2_source();
    void robust_p2p_icp();
    
    
};
