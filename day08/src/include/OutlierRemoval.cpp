#include "OutlierRemoval.h"

void OutRemove::load_PC() {
    printf("\033c"); // For Linux/Unix : clear console
    cout << "Trying to add point cloud...\n";
    //----- Create a pointer to store the point cloud -----    
    //auto cloud_ptr = make_shared<open3d::geometry::PointCloud>();
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
    //cout << "IsEmpty?" << cloud_ptr->IsEmpty();
    // what will be visualized
    pcd = cloud_ptr;
    
}

void OutRemove::visualize_PC() {
    
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

//----- Paint all points gray -----//
void OutRemove::paint_gray(){

    if(!cloud_ptr->IsEmpty()){         
        open3d::utility::LogInfo("Paint all points Gray...");
        Eigen::Vector3d gray = {0.5, 0.5, 0.5}; 
        cloud_ptr -> PaintUniformColor(gray);

        // what will be visualized
        pcd = cloud_ptr;       
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }      
}

//----- Down sampling -----//
void OutRemove::DownSample_PC() {
    // if there is no data loaded
    if(!cloud_ptr->IsEmpty()){ 
        
        open3d::utility::LogInfo("Downsample the point cloud with a voxel of 0.02");
        pcd = cloud_ptr -> VoxelDownSample(0.02);       
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}

//----- Statistical outlier removal -----//    
void OutRemove::Stat_outlier_removal() {
    // if there is no data loaded
    if(!cloud_ptr->IsEmpty()){ 
        
        std::shared_ptr<open3d::geometry::PointCloud> cl;
        std::vector<size_t> ind;
        // nb_neighbors: Specifies how many neighbors are taken into account in order to calculate the average distance for a given point.
        // std_ratio: The lower this number the more aggressive the filter will be.
        std::tie(cl, ind) = pcd -> RemoveStatisticalOutliers(50, 1.0); 
        inlier_cloud  = pcd -> SelectByIndex(ind);
        outlier_cloud = pcd -> SelectByIndex(ind, true);
        inlier_cloud -> PaintUniformColor(Eigen::Vector3d(0.8, 0.8, 0.8));
        outlier_cloud -> PaintUniformColor(Eigen::Vector3d(1, 0, 0)); 

        // what will be visualized if you press 2
        *inlier_cloud += *outlier_cloud; //merging 2 point clouds (in & out)
        pcd = inlier_cloud;    
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}

    //----- Radius outlier removal -----//
void OutRemove::Radius_outlier_removal() {
    // if there is no data loaded
    if(!cloud_ptr->IsEmpty()){ 
        
        std::shared_ptr<open3d::geometry::PointCloud> cl;
        std::vector<size_t> ind;
        std::tie(cl, ind) = pcd -> RemoveRadiusOutliers(20, 0.05); // nb_points, std_radius

        inlier_cloud  = pcd -> SelectByIndex(ind);
        outlier_cloud = pcd -> SelectByIndex(ind, true);
        inlier_cloud  -> PaintUniformColor(Eigen::Vector3d(0.8, 0.8, 0.8));
        outlier_cloud -> PaintUniformColor(Eigen::Vector3d(1, 0, 0));

        // what will be visualized if you press 2
        *inlier_cloud += *outlier_cloud; //merging 2 point clouds (in & out)
        pcd = inlier_cloud;

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}