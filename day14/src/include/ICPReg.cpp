#include "ICPReg.h"

// draw_registration_result
void draw_registration_result(const open3d::geometry::PointCloud &source,
                              const open3d::geometry::PointCloud &target,
                              const Eigen::Matrix4d &Transforamtion){
    shared_ptr<open3d::geometry::PointCloud> source_temp(new open3d::geometry::PointCloud);
    shared_ptr<open3d::geometry::PointCloud> target_temp(new open3d::geometry::PointCloud);
    *source_temp = source;
    *target_temp = target;
    source_temp -> PaintUniformColor(Eigen::Vector3d(1, 0.706, 0));
    target_temp -> PaintUniformColor(Eigen::Vector3d(0, 0.651, 0.929));
    source_temp -> Transform(Transforamtion);
    open3d::visualization::DrawGeometries({source_temp, target_temp},
                                  "Registration result");
}

//----- Load mesh and convert to point cloud-----//    
void ICPReg::load_PCs() {
    
    source = open3d::io::CreatePointCloudFromFile(path_2_pc_1);
    target = open3d::io::CreatePointCloudFromFile(path_2_pc_2);

    printf("\033c"); // For Linux/Unix : clear console
    cout << "Trying to load PCs...\n";
    // if there is no data loaded
    if(!source->IsEmpty() && !target->IsEmpty()){ 
        
        
        if (open3d::io::ReadPointCloud(path_2_pc_1, *source) && open3d::io::ReadPointCloud(path_2_pc_2, *target))
        {
            open3d::utility::LogInfo("Successfully read \n{}\n{}\n", path_2_pc_1,path_2_pc_2);
        }
        else
        {
            open3d::utility::LogInfo("Failed to read \n{}\n{}\n", path_2_pc_1,path_2_pc_2);        
        }
        trans_init << 0.862,  0.011, -0.507,  0.5,
                     -0.139,  0.967, -0.215,  0.7,
                      0.487,  0.255,  0.835, -1.4,
                      0.0,    0.0,    0.0,    1.0;

        cout << "Trans_init:" << '\n' << trans_init << endl;        
        open3d::utility::LogInfo("Initial alignment:");
        
        draw_registration_result(*source, *target, trans_init);

        auto evaluation = open3d::pipelines::registration::EvaluateRegistration(*source, *target, threshold, trans_init);
        cout << "  fitness: " << evaluation.fitness_  << " (The higher, the better)"<< endl;
        cout << "  inlier_rms: " << evaluation.inlier_rmse_  << " (The lower, the better)"<< endl;

    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    }       
}

void ICPReg::p2p_icp(){
    if(!source->IsEmpty() && !target->IsEmpty()){
        cout << "Point-to-point ICP: " << endl;
        auto reg_p2p = open3d::pipelines::registration::RegistrationICP(*source, *target, threshold, trans_init, 
        open3d::pipelines::registration::TransformationEstimationPointToPoint());
        auto evaluation = open3d::pipelines::registration::EvaluateRegistration(*source, *target, threshold, reg_p2p.transformation_);
        cout << "  fitness: " << evaluation.fitness_  << " (The higher, the better)"<< endl;
        cout << "  inlier_rms: " << evaluation.inlier_rmse_  << " (The lower, the better)"<< endl;
        draw_registration_result(*source, *target, reg_p2p.transformation_);
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
}

void ICPReg::p2p_icp_iter(){
    if(!source->IsEmpty() && !target->IsEmpty()){
        std::cout << "P-t-P ICP with 2000 iterations:" << std::endl;
        auto reg_p2p = open3d::pipelines::registration::RegistrationICP(*source, *target, threshold,
                    trans_init, open3d::pipelines::registration::TransformationEstimationPointToPoint(),
                    open3d::pipelines::registration::ICPConvergenceCriteria(0, 0, 2000));
        auto evaluation = open3d::pipelines::registration::EvaluateRegistration(*source, *target, threshold, reg_p2p.transformation_);
        std::cout << "  fitness: " << evaluation.fitness_  << " (The higher, the better)"<< std::endl;
        std::cout << "  inlier_rms: " << evaluation.inlier_rmse_  << " (The lower, the better)"<< std::endl;
        draw_registration_result(*source, *target, reg_p2p.transformation_);
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
}

void ICPReg::p2plane_icp(){
    if(!source->IsEmpty() && !target->IsEmpty()){
        std::cout << "point-to-plane ICP:" << std::endl;
        auto reg_p2p = open3d::pipelines::registration::RegistrationICP(*source, *target, threshold,
                    trans_init, open3d::pipelines::registration::TransformationEstimationPointToPlane());
        auto evaluation = open3d::pipelines::registration::EvaluateRegistration(*source, *target, threshold, reg_p2p.transformation_);
        std::cout << "  fitness: " << evaluation.fitness_  << " (The higher, the better)"<< std::endl;
        std::cout << "  inlier_rms: " << evaluation.inlier_rmse_  << " (The lower, the better)"<< std::endl;
        draw_registration_result(*source, *target, reg_p2p.transformation_);
    }else{
         open3d::utility::LogInfo("Please try to load the correct data first!");
    } 
}







