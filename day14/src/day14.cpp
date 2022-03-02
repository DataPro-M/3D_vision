#include "include/ICPReg.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.

    // --- get path of the pointcloud data ---//
    char * dir = getcwd(NULL, 0); // get current working dir path --> /bin 
    fs::path p = dir;

    fs::path fullPath = p.parent_path().parent_path(); // go back two dirs
    string fileName_pc("data/pointcloud/cloud_bin_0.pcd");
    fullPath /= fileName_pc; // add filename to path

    fs::path fullPath_msh = fullPath.parent_path(); // go back two dirs
    string fileName_msh("cloud_bin_1.pcd");
    fullPath_msh /= fileName_msh; // add filename to path

    
    cout  << "fullPath_pc of data is: " << fullPath.c_str() << endl;
    cout  << "fullPath_msh of data is: " << fullPath_msh.c_str() << endl;
    

    // OutlierRemoval class
    ICPReg icpreg;
    // read the point clouds path & store it in 'cloud_ptr'                
    icpreg.path_2_pc_1  = fullPath.c_str();
    icpreg.path_2_pc_2 = fullPath_msh.c_str();


	while(x != 7) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the point cloud data" << endl;
        cout << "2.  Point-to-point ICP" << endl; 
        cout << "3.  P-t-P ICP with 2000 iterations" << endl;
        cout << "4.  Point-to-plane ICP" << endl;
        cout << "5.  Apply noise to source" << endl;
        cout << "6.  Robust point-to-plane ICP" << endl;
        cout << "7.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console    
      
 
		switch(x) {
            case 1: 
                icpreg.load_PCs();                                        
                break;

            case 2:
                icpreg.p2p_icp();               
                break;

            case 3:
                icpreg.p2p_icp_iter();          
                break;
            
            case 4:
                icpreg.p2plane_icp();          
                break;

            case 5:
                icpreg.apply_noise_2_source();          
                break;

            case 6:
                icpreg.robust_p2p_icp();          
                break;
        
            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}