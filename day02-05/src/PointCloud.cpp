#include "include/PointCloud.h"




void PointCloud::load_PC() {
    printf("\033c"); // For Linux/Unix : clear console
    cout << "Trying to add point cloud...\n";
    //----- Create a pointer to store the point cloud -----    
    //auto cloud_ptr = std::make_shared<open3d::geometry::PointCloud>();
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
    pcd = cloud_ptr;

    
}

void PointCloud::visualize_PC() {
    
    // if there is no data loaded
    if(pcd->HasNormals()){ 
        
        open3d::visualization::Visualizer vis; 
        // create a visualizer window
        vis.CreateVisualizerWindow("Open3D Test", 1600, 900);
        vis.AddGeometry(pcd);
        vis.Run();               
        vis.DestroyVisualizerWindow(); 
        
        //cout << "Finally is_window_closed: " << vis.PollEvents() << endl;  
               
    }else{
         open3d::utility::LogInfo("Nothing to visualize");
    } 
    
}

void PointCloud::DownSample_PC() {
    // if there is no data loaded
    if(pointcloud_has_normal){ 
        //----- Down sampling -----//
        open3d::utility::LogInfo("Downsample the point cloud with a voxel of 0.05");
        pcd = cloud_ptr -> VoxelDownSample(0.05);       
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }     
}

void PointCloud::vertex_normal_estimation(){
    //----- Vertex  normal estimation -----//
    open3d::utility::LogInfo("Recompute the normal of the downsampled point cloud");
    //Compute normal for every point parameter[radius: searching radius, max_nn: maximum nearest neighbor]
    cloud_ptr -> EstimateNormals(open3d::geometry::KDTreeSearchParamHybrid(0.1, 30));
    open3d::utility::LogInfo("Print a normal vector of the 0th point:");
    cout << cloud_ptr->normals_[0] << endl;

    // what will be visualized
    pcd = cloud_ptr;

}
//------------- crop --------------
void PointCloud::crop(){
    string crop_path = "/media/pi/Transcend/Komijani/ML/3D_vision/3D_vision/data/crop/cropped.json";
    // if there is no data loaded
    if(pointcloud_has_normal){ 
        // reads a json file that specifies polygon selection area
        auto polygon_volume = std::make_shared<open3d::visualization::SelectionPolygonVolume>();
        if (open3d::io::ReadIJsonConvertible(crop_path, *polygon_volume)) {
                open3d::utility::LogInfo("Crop point cloud.\n");
                // filters out points. Only the chair remains.
                chair = polygon_volume->CropPointCloud(*cloud_ptr);// chair
                // pcd is what will be visualized 
                pcd = chair;
        }       
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }
      
}

//------------- paint --------------
void PointCloud::paint(){
    // if there is no data loaded
    if(pointcloud_has_normal){ 
        cout << "Paint it yellow7";
		Eigen::Vector3d colorIn = {1,0.706,0}; // Paint yellow
	    pcd->PaintUniformColor(colorIn);              
    }
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }  
}

//------------- remove chair ---------------
void PointCloud::remove_chair(){
    // if there is no data loaded
    if(chair->IsEmpty()){
        open3d::utility::LogInfo("Please first choose item 5 to crop the chair!");                    
    }
    else{
        // Compute the distance from the source point cloud [pcd] to a target point cloud [chair]
        auto dists = cloud_ptr->ComputePointCloudDistance(*chair);

        vector<size_t> ind;        
        for(int i{}, e = dists.size(); i < e; i++)  {
            if(abs(dists[i]) > 0.01){
                ind.push_back(i);       
            }
        }
        open3d::utility::LogInfo("The chair has removed!");    
        pcd =  cloud_ptr -> SelectByIndex(ind);
    }  
}

// ---------- DBSCAN Clustering -----//
void PointCloud::DBSCAN(){
    // check if the PC is loaded
    if(pointcloud_has_normal){ 
        // [Group local point cloud clusters together]
        std::vector<int>labels = cloud_ptr -> ClusterDBSCAN(0.02, 10, true);

        int max_label = *max_element(labels.begin(),labels.end());
        open3d::utility::LogInfo("point cloud has {:d} clusters.", max_label+1);
        std::vector<Eigen::Vector3d> vColor; // Define color vector
        vColor.reserve(1 + max_label);
        // Generate random color
        for (int i = 0; i <= max_label; i++){
            double R = (rand()%(200-0)+0)/255.0;
            double G = (rand()%(128-100)+100)/255.0;
            double B = (rand()%(250-25)+25)/255.0;
            Eigen::Vector3d c = {R, G, B};
            vColor.push_back(c);
        }
        // Color each point cloud cluster
        std::vector<Eigen::Vector3d> pcColor;
        pcColor.reserve(labels.size());
        for (int i = 0; i < labels.size(); i++)
        {
            int label = labels[i];
            if (label <0)
            {
                Eigen::Vector3d c = {0,0,0}; // noise=-1 set color to black
                pcColor.push_back(c);
            }
            else
            {
                Eigen::Vector3d c = vColor[label];
                pcColor.push_back(c);
            }
        }
        // Paint point cloud
        cloud_ptr -> colors_ = pcColor;

        // what will be visualized
        pcd = cloud_ptr;
        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }  
}

//----- Plane segmentation -----//
void PointCloud::plane_seg(){
    // check if the PC is loaded
    if(pointcloud_has_normal){ 
        double distance_threshold = 0.01;
        int ransac_n = 3;
        int num_iterations = 1000;    
        std::tuple<Eigen::Vector4d, std::vector<size_t> > vRes = 
                        cloud_ptr -> SegmentPlane(distance_threshold, ransac_n, num_iterations); // Return plane model and inliers
        // [a b c d] plane model
        Eigen::Vector4d para = std::get<0>(vRes);
        // Inliers
        std::vector<size_t> inliers = std::get<1>(vRes);
        
        // Paint inliers red
        shared_ptr<open3d::geometry::PointCloud> inPC = cloud_ptr -> SelectByIndex(inliers, false);
        const Eigen::Vector3d colorIn = {1,0,0};
        inPC->PaintUniformColor(colorIn);
        // Paint inliers black
        shared_ptr<open3d::geometry::PointCloud> outPC = cloud_ptr -> SelectByIndex(inliers, true);
        const Eigen::Vector3d colorOut = { 1,1,1 }; // everything white except plain
        outPC->PaintUniformColor(colorOut);
        
        open3d::utility::LogInfo("The plane segmented to red!");          

        // what will be visualized if you press 2
        *inPC += *outPC; //merging 2 point clouds (in & out)
        pcd = inPC;
        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }  
}

//----- bounding_box -----//
void PointCloud::bounding_box(){
    // check if the PC is loaded
    if(pointcloud_has_normal){ 
        
        //----- Get axis aligned/oriented bounding box -----//
        open3d::geometry::AxisAlignedBoundingBox bounding_box_aligned = pcd -> GetAxisAlignedBoundingBox();
        std::shared_ptr<open3d::geometry::AxisAlignedBoundingBox> bounding_box(
                    new open3d::geometry::AxisAlignedBoundingBox(bounding_box_aligned));
        bounding_box -> color_ = Eigen::Vector3d(1, 0, 0); // Set bounding box color
        open3d::utility::LogInfo("visualization of bounding box!");   

        open3d::visualization::Visualizer vis; 
        // create a visualizer window
        vis.CreateVisualizerWindow("Open3D Test", 1600, 900);
        vis.AddGeometry(pcd);
        vis.AddGeometry(bounding_box);
        vis.Run();               
        vis.DestroyVisualizerWindow(); 
        
    }       
    else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }  
}
    

