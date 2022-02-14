#include "ISSKeypoint.h"

//----- Load mesh and convert to point cloud-----//    
void IssKeypoint::load_as_mesh() {
    
    mesh = open3d::io::CreateMeshFromFile(path_2_mesh);
    printf("\033c"); // For Linux/Unix : clear console
    cout << "Trying to add mesh...\n";
    // if there is no data loaded
    if(!mesh->IsEmpty()){ 
        mesh = open3d::io::CreateMeshFromFile(path_2_mesh);  // Load Triangle Mesh
        open3d::utility::LogInfo("Mesh has {:d} vertices, {:d} triangles.",
                            mesh -> vertices_.size(), mesh -> triangles_.size());
       
        // convert to point cloud
        pcd -> points_ = mesh -> vertices_;
        
        open3d::visualization::DrawGeometries({mesh});

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }       
}




//----- Compute the ISS Keypoints -----//
void IssKeypoint::compute_iss_keypoints(){    
    
    if(!pcd->IsEmpty()){
        open3d::utility::ScopeTimer timer("ISS keypoints Estimation");
        ISS_keypoints = open3d::geometry::keypoint::ComputeISSKeypoints(*pcd);
        open3d::utility::LogInfo("Detected {} keypoints", ISS_keypoints -> points_.size());
        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }      
}

//----- Keypoints Visualization -----//
void IssKeypoint::kp_visualization(){

    if(!ISS_keypoints->IsEmpty()){ 
        ISS_keypoints->PaintUniformColor(Eigen::Vector3d(1.0, 0.75, 0.0)); // Paint keypoints yellow
        mesh -> PaintUniformColor(Eigen::Vector3d(0.5, 0.5, 0.5));
        mesh -> ComputeVertexNormals();
        mesh -> ComputeTriangleNormals();
        open3d::visualization::DrawGeometries({mesh, ISS_keypoints}, "ISS Keypoints");        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the data first and then apply poisson_surface_reconstruction!");
    }      
}

