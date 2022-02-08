#include "Voxelization.h"

void Voxel::load_PC() {
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

    // Returns 'true' if the point cloud contains points.
    pointcloud_has_normal = cloud_ptr->HasNormals();
    if(pointcloud_has_normal){ 
        open3d::utility::LogInfo("Pointcloud has normals.");
    }else{
        open3d::utility::LogInfo("Pointcloud has no normals.");
    }   
    // what will be visualized
    *pcd = *cloud_ptr;
    
}

void Voxel::visualize_PC() {
    
    // if there is no data loaded
    if(!pcd->IsEmpty()){ 
        
        open3d::visualization::Visualizer vis;         
        vis.CreateVisualizerWindow("Open3D Test", 1600, 900); // create a visualizer window
        
        vis.AddGeometry(pcd);
                
        vis.Run();               
        vis.DestroyVisualizerWindow(); 
        
               
    }else{
         open3d::utility::LogInfo("Nothing to visualize");
    } 
    
}

//----- shit -----//
void Voxel::shift(int axis_ind, float shift){

    
    if(!cloud_ptr->IsEmpty()){
        // copy original to pcd_2 
        *pcd_2 = *cloud_ptr;

        open3d::utility::LogInfo("Shift the PC");
        if(axis_ind >= 0 && axis_ind <= 2){
            for(size_t i = 0; i < pcd_2->points_.size(); i++){
                if(axis_ind==0)       pcd_2->points_[i].x() += shift;
                else if(axis_ind==1)  pcd_2->points_[i].y() += shift;
                else                  pcd_2->points_[i].z() += shift;
            }
            // what will be visualized
            *pcd = *cloud_ptr; 
            *pcd += *pcd_2; //merging 2 point clouds
        }
        else{
            open3d::utility::LogInfo("Wrong axis ind!\nx:1, y:2, and z:3");
        }  
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }      
}

//----- scale -----//
void Voxel::scale(){

    if(!cloud_ptr->IsEmpty()){         
        open3d::utility::LogInfo("Fit to the unit cube");
        // what will be visualized
        *pcd = *cloud_ptr; 
        // Fit to the unit cube
        auto scale = pcd->GetMaxBound() - pcd->GetMinBound();        
        auto center = pcd->GetCenter();
        pcd -> Scale(1/scale.maxCoeff(), center);

        *pcd += *pcd_2; //merging 2 point clouds       
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }      
}

//----- voxelization -----//
void Voxel::voxelization() {
    // if there is no data loaded
    if(!cloud_ptr->IsEmpty()){         
        open3d::utility::LogInfo("voxelization");
        auto voxel = open3d::geometry::VoxelGrid::CreateFromPointCloud(*cloud_ptr, 0.005);
        open3d::visualization::DrawGeometries({voxel});      
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}

//----- convert_to_mesh -----//    
void Voxel::convert_to_mesh() {
    
    mesh = open3d::io::CreateMeshFromFile(path_2_msh);
    // if there is no data loaded
    if(!mesh->IsEmpty()){ 

        open3d::utility::LogInfo("Mesh has {:d} vertices, {:d} triangles.",
                            mesh -> vertices_.size(), mesh -> triangles_.size());
        mesh -> RemoveDuplicatedVertices();
        mesh -> RemoveDuplicatedTriangles();
        mesh -> RemoveDegenerateTriangles();
        mesh -> RemoveUnreferencedVertices();
        open3d::utility::LogInfo(
                    "After purge vertices, Mesh has {:d} vertices, {:d} "
                    "triangles.",
                    mesh -> vertices_.size(), mesh -> triangles_.size());
        

        open3d::visualization::DrawGeometries({mesh});

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }       
}

    //----- Radius outlier removal -----//
void Voxel::mesh_voxelization() {
        // if there is no data loaded
        if(!mesh->IsEmpty()){ 
            // Fit to the unit cube
            auto scale = mesh->GetMaxBound() - mesh->GetMinBound();
            //std::cout << "Here is mat.maxCoeff():  " << scale.maxCoeff() << std::endl;
            auto center = mesh->GetCenter();
            mesh -> Scale(1/scale.maxCoeff(), center);

            //open3d::visualization::DrawGeometries({mesh});

            cout << "Voxelization: " << endl;
            auto voxel1 = open3d::geometry::VoxelGrid::CreateFromTriangleMesh(*mesh, 0.05);
            open3d::visualization::DrawGeometries({mesh, voxel1});        

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}