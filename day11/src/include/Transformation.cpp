#include "Transformation.h"

//----- translate -----//    
void Transformation::translate() {
    auto mesh = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    //open3d::visualization::DrawGeometries({mesh});
    auto mesh_tx = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    auto mesh_ty = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    mesh_tx -> Translate(Eigen::Vector3d(1.3, 0, 0));
    mesh_ty -> Translate(Eigen::Vector3d(0, 1.3, 0));
    cout << "mesh center position:" << mesh -> GetCenter() << endl;
    cout << "mesh_tx center position:" << mesh_tx -> GetCenter() << endl;
    cout << "mesh_tx center position:" << mesh_ty -> GetCenter() << endl;
    open3d::visualization::DrawGeometries({mesh, mesh_tx, mesh_ty}, "Translate");     
}

//----- Rotation -----//    
void Transformation::rotation() {
    auto mesh1 = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    auto mesh1_r = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    auto R = mesh1_r -> GetRotationMatrixFromXYZ(Eigen::Vector3d(PI/2, 0, PI/4));
    mesh1_r ->Rotate(R, Eigen::Vector3d(0, 0, 0));
    open3d::visualization::DrawGeometries({mesh1, mesh1_r}, "Rotation");    
}

//----- Scale -----//    
void Transformation::scale() {
    auto mesh2 = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    auto mesh2_s = open3d::geometry::TriangleMesh::CreateCoordinateFrame(); 
    mesh2_s -> Translate(Eigen::Vector3d(2, 1, 0));
    mesh2_s -> Scale(0.2, Eigen::Vector3d(0, 0, 0));
    open3d::visualization::DrawGeometries({mesh2, mesh2_s}, "Scale");   
}

//----- Scale -----//    
void Transformation::general_transformation() {
    auto mesh3 = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    auto mesh3_t = open3d::geometry::TriangleMesh::CreateCoordinateFrame();
    Eigen::Matrix<double, 4, 4> T;
    T = Eigen::MatrixXd::Identity(4,4);
    auto RR = mesh3 -> GetRotationMatrixFromXYZ(Eigen::Vector3d(0, PI/3, PI/2));
    for(int i = 0; i<3; i++){
        for(int j = 0; j <3; j++){
            T(i, j) = RR(i, j);
        }
    }
    T(0, 3) = 1;
    T(1,3) = 1.3;
    cout << "T: \n" << T << endl;
    mesh3_t -> Transform(T);
    open3d::visualization::DrawGeometries({mesh3, mesh3_t}, "General Transformation");  
}



