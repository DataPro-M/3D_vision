#include "include/ICPReg.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.

    // --- get path of the pointcloud data ---//
    char * dir = getcwd(NULL, 0); // get current working dir path --> /bin 
    fs::path p = dir;

    fs::path fullPath = p.parent_path().parent_path(); // go back two dirs
    string fileName_pc("data/pointcloud/Armadillo.ply");
    fullPath /= fileName_pc; // add filename to path    
    cout  << "fullPath_pc of data is: " << fullPath.c_str() << endl;
    

    // OutlierRemoval class
    Octree octree;
    // read the point cloud path & store it in 'cloud_ptr'                
    octree.path_2_mesh  = fullPath.c_str();


	while(x != 5) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the mesh data" << endl;
        cout << "2.  Fit to the unit cube" << endl; 
        cout << "3.  Octree division" << endl;
        cout << "4.  Voxelization" << endl;
        cout << "5.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console    
      
 
		switch(x) {
            case 1: 
                octree.load_as_mesh();                                        
                break;

            case 2:
                octree.scale();                 
                break;

            case 3:
                octree.octree_division();                 
                break;
            
            case 4:
                octree.voxelization();                 
                break;
        
            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}