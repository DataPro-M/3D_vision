#include "include/OutlierRemoval.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.

    // OutlierRemoval class
    OutRemove O_R;

	while(x != 8) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the point cloud data" << endl;
        cout << "2.  Visualize the pcd (last modified!)" << endl;   
        cout << "3.  Paint all poits gray" << endl;             
        cout << "4.  Down sampling" << endl;
        cout << "5.  Statistical outlier removal  " << endl;
        cout << "6.  Radius outlier removal" << endl;
        cout << "7.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
        // --- get path of the pointcloud data ---//
        char * dir = getcwd(NULL, 0); // get current working dir path --> /bin 
        fs::path p = dir;
      
        fs::path fullPath = p.parent_path().parent_path(); // go back two dirs
        string fileName("data/pointcloud/table_scene_lms400.pcd");
        fullPath /= fileName; // add filename to path
        cout  << "fullPath of data is: " << fullPath.c_str() << endl;
        
		switch(x) {
            case 1:
                
                // read the point clousd path & store it in 'cloud_ptr'                
                
                O_R.path_2_pc = fullPath.c_str();
                O_R.load_PC();
                O_R.visualize_PC();       
                                        
                break; 

            case 2: 
                // visualize                
                O_R.visualize_PC();
                break;

            case 3:
                O_R.paint_gray();                 
                O_R.visualize_PC();
                break;

            case 4:
                O_R.DownSample_PC();
                O_R.visualize_PC();
                break;
            
            case 5:
                O_R.Stat_outlier_removal();     
                O_R.visualize_PC();
                break;

            case 6:
                O_R.Radius_outlier_removal();
                O_R.visualize_PC();          
                break;             

            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}