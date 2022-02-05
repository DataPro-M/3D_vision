#include "include/PointCloud.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.
    PointCloud P_C;
	while(x != 11) {
        cout << "\nHello Open3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the point cloud data" << endl;
        cout << "2.  Visualize the pcd (last modified!)" << endl;
        cout << "3.  Down sampling" << endl;
        cout << "4.  Vertex  normal estimation" << endl;
        cout << "5.  Crop point cloud" << endl;
        cout << "6.  Paint point cloud" << endl;
        cout << "7.  remove chair" << endl;
        cout << "8.  DBSCAN Clustering" << endl;
        cout << "9.  Plane segmentation" << endl;
        cout << "10. bounding box\n" << endl;
        cout << "11. Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
		switch(x) {
            case 1:
            // read the point clousd path & store it in 'cloud_ptr'
            if( argc > 1) { 
                P_C.path_2_pc = string (argv[1]);
                P_C.load_PC();
                P_C.visualize_PC();
            }
            else {
                cout << "No path (to point cloud data) is detected.. exiting program";
            };                        
            break; 

            case 2:                 
                P_C.visualize_PC();
                break;

            case 3:                 
                P_C.DownSample_PC();
                P_C.visualize_PC();
                break;

            case 4:
                P_C.vertex_normal_estimation();
                P_C.visualize_PC();
                break;
            
            case 5:
                P_C.crop();
                P_C.visualize_PC();            
                break;

            case 6:
                P_C.paint(); 
                P_C.visualize_PC();           
                break;

            case 7:
                P_C.remove_chair();
                P_C.visualize_PC();            
                break;

            case 8:
                P_C.DBSCAN();
                P_C.visualize_PC();            
                break;

            case 9:
                P_C.plane_seg();
                       
                break;

            case 10:
                P_C.bounding_box();           
                break;           
                

            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}