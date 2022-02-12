#include "include/Transformation.h"


int main(int argc, char *argv[]) {

    int x = 0; // Automatically infer type. Not a type in itself.


    // OutlierRemoval class
    Transformation trans;



	while(x != 5) {
        cout << "\nOpen3d\n" << endl;
        cout << "Select an option" << endl;
        cout << "1.  Translate" << endl;
        cout << "2.  Rotation" << endl; 
        cout << "3.  Scale" << endl;             
        cout << "4.  General Transformation" << endl;       
        cout << "5.  Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console    
      
 
		switch(x) {
            case 1: 
                trans.translate();                                        
                break;

            case 2:
                trans.rotation();                 
                break;

            case 3:
                trans.scale();                 
                break;

            case 4:
                trans.general_transformation();                
                break;            
            
            default: // If no match is found.                          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;   
    
}