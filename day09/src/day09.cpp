#include "include/Voxelization.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.
    // --- get path of the pointcloud data ---//
    char * dir = getcwd(NULL, 0); // get current working dir path --> /bin 
    fs::path p = dir;

    fs::path fullPath = p.parent_path().parent_path(); // go back two dirs
    string fileName_pc("data/pointcloud/Bunny.ply");
    fullPath /= fileName_pc; // add filename to path

    fs::path fullPath_msh = fullPath.parent_path(); // go back two dirs
    string fileName_msh("Armadillo.ply");
    fullPath_msh /= fileName_msh; // add filename to path

    
    cout  << "fullPath_pc of data is: " << fullPath.c_str() << endl;
    cout  << "fullPath_msh of data is: " << fullPath_msh.c_str() << endl;

    // OutlierRemoval class
    Voxel voxel;
    // read the point clousd path & store it in 'cloud_ptr'                
    voxel.path_2_msh = fullPath_msh.c_str();
    voxel.path_2_pc  = fullPath.c_str();

	while(x != 8) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the point cloud data" << endl;
        cout << "2.  Visualize the pcd (last modified!)" << endl;
        cout << "3.  Shift the point cloud" << endl; 
        cout << "4.  Scale the point cloud" << endl;             
        cout << "5.  Voxelization" << endl;
        cout << "6.  Convert to mesh  " << endl;
        cout << "7.  Mesh Voxelization" << endl;
        cout << "8.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console    
      
 
		switch(x) {
            case 1:
                
                
                
                voxel.load_PC();
                voxel.visualize_PC();       
                                        
                break; 

            case 2: 
                // visualize                
                voxel.visualize_PC();
                break;

            case 3:
                voxel.shift(1, 0.5);                 
                voxel.visualize_PC();
                break;

            case 4:
                voxel.scale();                 
                voxel.visualize_PC();
                break;

            case 5:
                voxel.voxelization();
                
                break;
            
            case 6:
                voxel.convert_to_mesh();     
                break;

            case 7:
                voxel.mesh_voxelization();
                voxel.visualize_PC();          
                break;             

            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}