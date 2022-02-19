#include "Octree.h"

//----- Load mesh and convert to point cloud-----//    
void Octree::load_as_mesh() {
    
    mesh = open3d::io::CreateMeshFromFile(path_2_mesh);
    printf("\033c"); // For Linux/Unix : clear console
    cout << "Trying to add mesh...\n";
    // if there is no data loaded
    if(!mesh->IsEmpty()){ 
        mesh = open3d::io::CreateMeshFromFile(path_2_mesh);  // Load Triangle Mesh
        
       
        mesh -> ComputeVertexNormals();
        pcd = mesh -> SamplePointsPoissonDisk(2000);
        
        if (open3d::io::ReadTriangleMesh(path_2_mesh, *mesh))
        {
            open3d::utility::LogInfo("Successfully read {}", path_2_mesh);
        }
        else
        {
            open3d::utility::LogInfo("Failed to read {}", path_2_mesh);
            
        }
        open3d::visualization::DrawGeometries({pcd});

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }       
}

//----- scale -----//
void Octree::scale(){    
    
    if(!pcd->IsEmpty()){
        // Fit to the unit cube
        auto scale = pcd->GetMaxBound() - pcd->GetMinBound();        
        auto center = pcd->GetCenter();
        pcd -> Scale(1/scale.maxCoeff(), center);
        open3d::visualization::DrawGeometries({pcd},"Point Cloud");
        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }      
}

//----- octree_division -----//
void Octree::octree_division(){

    if(!pcd->IsEmpty()){
        octree->ConvertFromPointCloud(*pcd,  0.01);
        open3d::visualization::DrawGeometries({octree}, "Octree");
    }       
    else{
         open3d::utility::LogInfo("You need to apply previous steps prior to do this!");
    }      
}

// ----------- Voxelization-------------//
void Octree::voxelization(){

    if(!pcd->IsEmpty()){
        auto voxel = open3d::geometry::VoxelGrid::CreateFromPointCloud(*pcd, 0.05);
        PrintVoxelGridInformation(*voxel);
        open3d::visualization::DrawGeometries({voxel}, "voxel");
    }       
    else{
         open3d::utility::LogInfo("You need to apply previous steps prior to do this!");
    }      
}

void Octree::PrintVoxelGridInformation(const open3d::geometry::VoxelGrid& voxel_grid) {
    
    open3d::utility::LogInfo("geometry::VoxelGrid with {:d} voxels",
                    voxel_grid.voxels_.size());
    open3d::utility::LogInfo("               origin: [{:f} {:f} {:f}]",
                    voxel_grid.origin_(0), voxel_grid.origin_(1),
                    voxel_grid.origin_(2));
    open3d::utility::LogInfo("               voxel_size: {:f}", voxel_grid.voxel_size_);
    return;
    
}

