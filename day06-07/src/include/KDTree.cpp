#include "KDTree.h"

void KDTree::load_PC() {
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

    open3d::utility::LogInfo("Build KDTree...");
    kd_tree_.SetGeometry(*cloud_ptr);

    // what will be visualized
    pcd = cloud_ptr;
    
}

void KDTree::visualize_PC() {
    
    // if there is no data loaded
    if(pcd->HasNormals()){ 
        
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
void KDTree::paint_gray(){

    if(pointcloud_has_normal){         
        open3d::utility::LogInfo("Paint all points Gray...");
        Eigen::Vector3d gray = {0.5, 0.5, 0.5}; 
        for(size_t i = 0; i < cloud_ptr->points_.size(); i++){
            cloud_ptr -> colors_[i] = gray;
        } 

        // what will be visualized
        pcd = cloud_ptr;       
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }  
    
}

// ----- Pick the 1500th points as the anchor point and paint it red //
void KDTree::point_paint(){

    if(pointcloud_has_normal){         
        open3d::utility::LogInfo("Paint the 1500th point red.");
        cloud_ptr -> colors_[anchor_point] = Eigen::Vector3d(1, 0, 0);

        // what will be visualized
        pcd = cloud_ptr;      
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
        
}

//----- K Nearest Neighbors Search -----//
void KDTree::KNN(){    
    if(pointcloud_has_normal){      
        
            
        open3d::utility::LogInfo("Find its 200 nearest neighbors, and paint them blue.");
        
        vector<int> new_indices_vec(knn);
        vector<double> new_dists_vec(knn);
        kd_tree_.SearchKNN(cloud_ptr->points_[anchor_point], knn, new_indices_vec, new_dists_vec);
        for (size_t i = 1; i < new_indices_vec.size(); i++) {
            //open3d::utility::LogInfo("{:d}, {:f}", (int)new_indices_vec[i], sqrt(new_dists_vec[i]));
            cloud_ptr -> colors_[new_indices_vec[i]] = Eigen::Vector3d(0, 0, 1);
        } // Skip the first index since it is the anchor point itself.

        // what will be visualized
        pcd = cloud_ptr;          
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
        
}

//----- Radius Nearest Neighbors Search -----//
    
void KDTree::SearchRadius(){
    
    if(pointcloud_has_normal){
            
        //query all points with distances to the anchor point less than a given radius. 
        //paint these points with a green color.
        
        vector<int> indices_vec(knn);
        vector<double> dists_vec(knn);
        kd_tree_.SearchRadius(cloud_ptr->points_[anchor_point], radius, indices_vec, dists_vec);
        for (size_t i = 1; i < indices_vec.size(); i++) {
            cloud_ptr -> colors_[indices_vec[i]] = Eigen::Vector3d(0, 1, 0);
        } // Skip the first index since it is the anchor point itself.

        // what will be visualized
        pcd = cloud_ptr;          
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
        
}

//----- Hybrid search -----//
void KDTree::HybridSearch(){
    
    if(pointcloud_has_normal){
            
        // Radius K Neasrest Neighbors Search (Hybrid search)
        vector<int> hybrid_indices_vec(knn);
        vector<double> hybrid_dists_vec(knn);
        kd_tree_.SearchHybrid(cloud_ptr->points_[anchor_point], radius, 50, hybrid_indices_vec, hybrid_dists_vec);
        for (size_t i = 1; i < hybrid_indices_vec.size(); i++) {
            cloud_ptr -> colors_[hybrid_indices_vec[i]] = Eigen::Vector3d(0, 1, 0.8);
        } // Skip the first index since it is the anchor point itself. 

        // what will be visualized
        pcd = cloud_ptr;          
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
        
}
    
  
