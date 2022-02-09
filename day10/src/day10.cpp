#include "include/PoissonSurfaceSeconstruction.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.

    // --- get path of the pointcloud data ---//
    char * dir = getcwd(NULL, 0); // get current working dir path --> /bin 
    fs::path p = dir;

    fs::path fullPath = p.parent_path().parent_path(); // go back two dirs
    string fileName_pc("data/pointcloud/eagle.ply");
    fullPath /= fileName_pc; // add filename to path

    fs::path fullPath_msh = fullPath.parent_path(); // go back two dirs
    string fileName_msh("Bunny.ply");
    fullPath_msh /= fileName_msh; // add filename to path

    
    cout  << "fullPath_pc of data is: " << fullPath.c_str() << endl;
    cout  << "fullPath_msh of data is: " << fullPath_msh.c_str() << endl;

    // OutlierRemoval class
    Poisson poisson;
    // read the point clousd path & store it in 'cloud_ptr'                
    poisson.path_2_pc  = fullPath.c_str();
    poisson.path_2_pc_2 = fullPath_msh.c_str();


	while(x != 8) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the point cloud data" << endl;
        cout << "2.  Poisson surface reconstruction" << endl; 
        cout << "3.  Density visualization" << endl;             
        cout << "4.  Mesh to point cloud" << endl;
        cout << "5.  Alpha Shape" << endl;
        cout << "6.  Ball pivoting" << endl;
        cout << "7.  Normal estimation" << endl;
        cout << "8.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console    
      
 
		switch(x) {
            case 1: 
                poisson.load_PC();                                        
                break;

            case 2:
                poisson.poisson_surface_reconstruction();                 
                break;

            case 3:
                poisson.density_visualization();                 
                break;

            case 4:
                poisson.mesh_2_pc();                
                break;
            
            case 5:
                poisson.alpha_shape();     
                break;

            case 6:
                poisson.ball_pivoting();
                break;

            case 7:
                poisson.normal_estimation();
                
                break;          
                                   

            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}