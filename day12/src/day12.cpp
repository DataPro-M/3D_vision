#include "include/ISSKeypoint.h"


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
    IssKeypoint IssKey;
    // read the point cloud path & store it in 'cloud_ptr'                
    IssKey.path_2_mesh  = fullPath.c_str();


	while(x != 4) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the mesh data" << endl;
        cout << "2.  Compute the ISS Keypoints" << endl; 
        cout << "3.  Key points Visualization" << endl;
        cout << "4.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console    
      
 
		switch(x) {
            case 1: 
                IssKey.load_as_mesh();                                        
                break;

            case 2:
                IssKey.compute_iss_keypoints();                 
                break;

            case 3:
                IssKey.kp_visualization();                 
                break;
        
            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}