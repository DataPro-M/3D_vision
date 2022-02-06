#include "include/KDTree.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.
    KDTree KDT;
	while(x != 8) {
        cout << "\nHello Open3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Load the point cloud data" << endl;
        cout << "2.  Visualize the pcd (last modified!)" << endl;   
        cout << "3.  Paint all poits gray" << endl;             
        cout << "4.  Paint the 1500th point red" << endl;
        cout << "5.  KNN Search (paint 200 NN points blue) " << endl;
        cout << "6.  Radius Nearest Neighbors Search" << endl;
        cout << "7.  Hybrid search" << endl;
        cout << "8.  Quit\n" << endl;
        /*
        
        
        cout << "8.  DBSCAN Clustering" << endl;
        cout << "9.  Plane segmentation" << endl;
        cout << "10. bounding box\n" << endl;
        
        */

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
        char * dir = getcwd(NULL, 0); // get current working dir path --> /bin 
        fs::path p = dir;

      
        fs::path fullPath = p.parent_path().parent_path(); // go two dir up
        string fileName("data/pointcloud/cloud_bin_0.pcd");
        fullPath /= fileName; // add filename to path
        cout  << "fullPath of data is: " << fullPath.c_str() << endl;
        
		switch(x) {
            case 1:
                
                // read the point clousd path & store it in 'cloud_ptr'                
                
                KDT.path_2_pc = fullPath.c_str();
                KDT.load_PC();
                KDT.visualize_PC();       
                                        
                break; 

            case 2:                 
                KDT.visualize_PC();
                break;

            case 3:
                KDT.paint_gray();                 
                KDT.visualize_PC();
                break;

            case 4:
                KDT.point_paint();
                KDT.visualize_PC();
                break;
            
            case 5:
                KDT.KNN();
                KDT.visualize_PC();
                break;

            case 6:
                KDT.SearchRadius(); 
                KDT.visualize_PC();          
                break;

            case 7:
                KDT.HybridSearch();
                KDT.visualize_PC();
                break; 

            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}