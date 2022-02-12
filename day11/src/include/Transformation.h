#include <iostream>
#include <memory>
#include <thread>
#include <random>
#include <cstdlib>
#include <Eigen/Dense>
#include "open3d/Open3D.h"
#include <experimental/filesystem>
#include <unistd.h> //getcwd - get the pathname of the current working directory
#define PI 3.14159d

using namespace std;
namespace fs = experimental::filesystem;

class Transformation{
    // members cannot be accessed (or viewed) from outside the class
    private:   
    
    protected:  

    // members are accessible from outside the class
    public:
    Transformation(){
        // constructor
    }
    ~Transformation(){
        // destructor
    }     

    void translate();
    void rotation();
    void scale();
    void general_transformation();

    
};
