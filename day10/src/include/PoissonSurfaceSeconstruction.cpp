#include "PoissonSurfaceSeconstruction.h"

//----- convert_to_mesh -----//    
void Poisson::load_as_mesh() {
    
    mesh_2 = open3d::io::CreateMeshFromFile(path_2_pc_2);
    // if there is no data loaded
    if(!mesh_2->IsEmpty()){ 

        open3d::utility::LogInfo("Mesh has {:d} vertices, {:d} triangles.",
                            mesh_2 -> vertices_.size(), mesh_2 -> triangles_.size());
        mesh_2 -> RemoveDuplicatedVertices();
        mesh_2 -> RemoveDuplicatedTriangles();
        mesh_2 -> RemoveDegenerateTriangles();
        mesh_2 -> RemoveUnreferencedVertices();
        open3d::utility::LogInfo(
                    "After purge vertices, Mesh has {:d} vertices, {:d} "
                    "triangles.",
                    mesh_2 -> vertices_.size(), mesh_2 -> triangles_.size());
        

        open3d::visualization::DrawGeometries({mesh_2});

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }       
}

void Poisson::load_PC() {
    printf("\033c"); // For Linux/Unix : clear console
    cout << "Trying to add point cloud...\n";
    //----- Create a pointer to store the point cloud -----    
    cloud_ptr = open3d::io::CreatePointCloudFromFile(path_2_pc);
    if (open3d::io::ReadPointCloud(path_2_pc, *cloud_ptr))
    {
        open3d::utility::LogInfo("Successfully read {}", path_2_pc);
    }
    else
    {
        open3d::utility::LogInfo("Failed to read {}", path_2_pc);        
    }
 
    // visualizing PC
    open3d::visualization::DrawGeometries({cloud_ptr}, "Original PointCloud");
    // loading second data
    load_as_mesh();
    
}


//----- Poisson Surface Reconstruction -----//
void Poisson::poisson_surface_reconstruction(){    
    
    if(!cloud_ptr->IsEmpty()){
        open3d::utility::LogInfo("Run Poisson surface reconstruction...");
        tie(mesh, dentities) = open3d::geometry::TriangleMesh::CreateFromPointCloudPoisson(*cloud_ptr,9);

        // visualizing the mesh
        open3d::visualization::DrawGeometries({mesh}, "Possion Reconstruction");
        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }      
}

//----- scale -----//
void Poisson::density_visualization(){

    if(!mesh->IsEmpty()){ 
        open3d::utility::LogInfo("Visualize Densities");
        double maxDensity = *max_element(dentities.begin(), dentities.end());
        double minDensity = *min_element(dentities.begin(), dentities.end());
        cout <<" Max Density: " << maxDensity << ", Min Density: " << minDensity << endl;
        
        // Color mapping
        for (size_t i=0; i < dentities.size(); i++){
            double color = (dentities[i]-minDensity)/(maxDensity-minDensity);
            mesh -> vertex_colors_[i] = Eigen::Vector3d(color,0.5,0);
        }
        open3d::utility::LogInfo("Green indicates low density.");
        open3d::utility::LogInfo("Orange indicates high density.");

        // visualizing the mesh
        open3d::visualization::DrawGeometries({mesh}, "Density Visualization");   
            
    }       
    else{
         open3d::utility::LogInfo("Please try to load the data first and then apply poisson_surface_reconstruction!");
    }      
}

//----- voxelization -----//
void Poisson::mesh_2_pc() {
    // if there is no data loaded

    if(!mesh_2->IsEmpty()){  
        pcd_2 = mesh_2 -> SamplePointsPoissonDisk(750); // Number of points
        open3d::visualization::DrawGeometries({pcd_2}, "mesh_2_pc");       
             
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}



//----- alpha_shape -----//
void Poisson::alpha_shape() {
    // if there is no data loaded
    if(!pcd_2->IsEmpty()){ 

        double alpha = 0.03;
        cout << "alpha= " << alpha << "\n" << endl;
        auto mesh1 = open3d::geometry::TriangleMesh::CreateFromPointCloudAlphaShape(*pcd_2, alpha);
        mesh1 -> ComputeVertexNormals();
        // visualization
        open3d::visualization::DrawGeometries({mesh1}, "Alpha Shape", 640, 480, 50, 50, false, false, true);
                    

    }else{
         open3d::utility::LogInfo("Please try to load the data first and then apply mesh to PC!");
    }     
}

//----- ball_pivoting -----//
// This algorithm assumes the Point cloud has normals
void Poisson::ball_pivoting() {
        // if there is no data loaded
        if(!mesh_2->IsEmpty()){ 
            mesh_2 -> ComputeVertexNormals();  // ReconstructBallPivoting requires normals
            auto pcd1 = mesh_2 -> SamplePointsPoissonDisk(3000); // Number of points
            open3d::visualization::DrawGeometries({pcd1});

            // Define the radii of the ball that are used for surface reconstruction 
            const vector<double> radii={0.005, 0.01, 0.02, 0.04};
            auto rec_mesh = open3d::geometry::TriangleMesh::CreateFromPointCloudBallPivoting(*pcd1,radii);
            open3d::visualization::DrawGeometries({pcd1, rec_mesh}, "Ball Pivoting");       

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}

//----- normal_estimation -----//
void Poisson::normal_estimation() {
        // if there is no data loaded
        if(!mesh_2->IsEmpty()){             
            auto pcd1 = mesh_2 -> SamplePointsPoissonDisk(3000); // Number of points
            cout << "Normal number: " << pcd1->normals_.size() << endl;
            pcd1 -> normals_.clear();  // Invalidate existing normals
            cout << "Normal number after clear: " << pcd1->normals_.size() << endl;
            pcd1 -> open3d::geometry::PointCloud::EstimateNormals();
            cout << "Estimate normal number: " << pcd1->normals_.size() << endl;
            open3d::visualization::DrawGeometries({pcd1}, "Normal Estimation", 640, 480, 50, 50, true);
                    
            // Propagates the normal orientation using a minimum spanning tree.
            open3d::utility::LogInfo("Propagates the normal orientation using a minimum spanning tree");
            pcd1 -> OrientNormalsConsistentTangentPlane(100);
            open3d::visualization::DrawGeometries({pcd1}, "Normal Estimation", 640, 480, 50, 50, true);
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}

