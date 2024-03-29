# 3D_vision
My 3D vision journey

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 1 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

`Hello world`

- [Day 01](day01)

### Lessons Learned

- [x] install open3D
- [x] load Pointcloud data
- [x] visualize Pointcloud data

### Screenshots

<img  src="images/Day_01.gif" /> 

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 2 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>


- [Day 02](day02-05)

### Lessons Learned

- [x] PointCloud Voxel Downsampling
- [x] Vertex  Normal Estimation
- [x] Crop point cloud 

### Screenshots

<img  src="images/Day_02.gif" />

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 3 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>



- [Day 03](day02-05)

### Lessons Learned

- [x] Painting point cloud 
- [x] Point cloud distance and removing object
- [x] Convex hull  

### Screenshots

<img  src="images/Day_03.gif" />

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 4 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

 

- [Day 04](day02-05)

### Lessons Learned

- [x] DBSCAN Clustering: Group local point cloud clusters together 
- [x] Plane segmentation 
- [x] Hidden point removal   

### Screenshots

<img  src="images/Day_04.gif" />

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 5 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>



- [Day 05 C++ Examples](day02-05/src/)

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./pointCloud <path/to/fragment.ply>
```

### Lessons Learned

- [x] open3d c++ [CMakeLists.txt](day02-05/CMakeLists.txt) 
- [x] load Pointcloud data
- [x] visualize Pointcloud data
- [x] PointCloud Voxel Downsampling
- [x] Vertex  Normal Estimation
- [x] Crop point cloud 
- [x] DBSCAN Clustering: Group local point cloud clusters together 
- [x] Plane segmentation 
- [x] bounding box



### Screenshots

| C++ examples |  bounding box  | 
|:---------------:|:---------------:|
|<img  src="images/Day_04_00.png" width="300"/>  |<img  src="images/Day_04_01_bbox.gif" width="300"/>|


***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 6 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>


- [Day 06](day06)

### Lessons Learned

**Finding neighbouring points**
- [x] Painting the 1500th point red  
- [x] KDTreeFlann
- [x] search_knn_vector_3d
- [x] search_radius_vector_3d 
- [x] search_hybrid_vector_3d 

### Screenshots

<img  src="images/Day_06.gif" />

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 7 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>



- [Day 07 C++ KDTree](day06-07/src/)

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./KDTree
```

### Lessons Learned

- [x] open3d c++ [CMakeLists.txt](day06-07/CMakeLists.txt) 
- [x] path/to/the/pointCloud/data
- [x] Paint all points gray
- [x] Get access & Paint the Nth point
- [x] KNN Search (paint 200 NN points blue)
- [x] Radius Nearest Neighbors Search
- [x] Hybrid search



### Screenshots

<img  src="images/Day_07_01.png" width="300"/> 

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 8 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

`Point Cloud Outlier Removal` 

- [Day 08 python OutlierRemoval](day08/)

- [Day 08 C++ OutlierRemoval](day08/src/)

- [dataset: table_scene_lms400.pcd](https://github.com/PointCloudLibrary/data/blob/master/tutorials/table_scene_lms400.pcd)

<img  src="images/Day_08_05_cpp.png" /> 

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./OutlierRemoval
```

### Lessons Learned

- [x] open3d c++ [CMakeLists.txt](day08/CMakeLists.txt) 
- [x] Statistical outlier removal
- [x] Radius outlier removal

### Screenshots

<img  src="images/Day_08.gif" />

_**Note:** Outliers: red points_


***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 9 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

Point Cloud `shifting, scaling, and Voxelization` 

- [Day 09 python ](day09/)

- [Day 09 C++ ](day09/src/)

- [dataset: Bunny.ply](https://github.com/naucoin/VTKData/blob/master/Data/bunny.ply)

<img  src="images/Day_09_00.png" /> 

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./Voxelization
```

### Lessons Learned

- [x] open3d c++ [CMakeLists.txt](day09/CMakeLists.txt) 
- [x] Point cloud Shifting, and Scaling
- [x] Voxelization

### Screenshots

<img  src="images/Day_09.gif" />

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 10 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

Point Cloud `shifting, scaling, and Voxelization` 

- [Day 10 python ](day10/)
- [Day 10 C++ ](day10/src/)

<img  src="images/Day_10_11.png" /> 

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./PoissonSurfaceSeconstruction
```

### Lessons Learned

- [x] Poisson surface reconstruction
- [x] Visualizing Densities
- [x] Remove low density vertices
- [x] Mesh to point cloud
- [x] Alpha Shape
- [x] Ball pivoting
- [x] Normal estimation

### Screenshots
| Original PointCloud   |  Mesh (surface reconstructed)   |
|:---------------:|:---------------:|
|<img  src="images/Day_10_01.png" width="300"/>  |<img  src="images/Day_10_02.png" width="300"/>|

|Densities (Violet=low) | remove low densities |
|:---------------------:|:--------------------:|
|<img  src="images/Day_10_03.png" width="300"/>  |<img  src="images/Day_10_04.png" width="300"/>  |


| Mesh                  | mesh to point cloud (750 sampling) | Alpha Shape  |
|:---------------------:|:--------------------:|:--------------------:|
|<img  src="images/Day_10_05.png" width="300"/>  |<img  src="images/Day_10_06.png" width="300"/>  |<img  src="images/Day_10_07.png" width="300"/>  |

|  mesh to point cloud (3000 sampling) | Ball pivoting| Normal estimation
|:---------------------:|:----------------------:|:----------------------:|
|<img  src="images/Day_10_08.png" width="300"/> |<img  src="images/Day_10_09.png" width="300"/> |<img  src="images/Day_10_10.png" width="300"/> |



***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 11 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

Point Cloud `shifting, scaling, and Voxelization` 

- [Day 11 python ](day11/)
- [Day 11 C++ ](day11/src/)

<img  src="images/Day_11_00.png" /> 

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./Transformation
```

### Lessons Learned

- [x] Translate
- [x] Rotation
- [x] Scale
- [x] General Transformation

### Screenshots
| Translate   |  Rotation  |Scale| General Transformation |
|:---------------:|:---------------:|:---------------------:|:--------------------:|
|<img  src="images/Day_11_01.png" width="300"/>  |<img  src="images/Day_11_02.png" width="300"/>|<img  src="images/Day_11_03.png" width="300"/>  |<img  src="images/Day_11_04.png" width="300"/>  |

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 12 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

`ISS keypoints`

- [Day 12 python ](day12/)
- [Day 12 C++ ](day12/src/)

<img  src="images/Day_12_05.png" /> 

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./ISSKeypoint
```

### Lessons Learned

- [x] Creating a spheres from key points
- [x] converting mesh to pointCloud
- [x] Compute ISS Keypoints on Armadillo
- [x] c++: open3d::utility::ScopeTimer

### Screenshots

| Mesh   |  Point cloud  | keypoints visualization| 
|:------:|:-------------:|:----------------------:|
|<img  src="images/Day_12_01.png" width="300"/>  |<img  src="images/Day_12_02.png" width="300"/>|<img  src="images/Day_12_03.png" width="300"/>  |

|  Creating a spheres from key points| ScopeTimer  | 
|:----------------------------------:|:-----------:|
|<img  src="images/Day_12_04.png" width="300"/>  |<img  src="images/Day_12_06.png" width="300"/>  |

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 13 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

`Octree`

- [Day 13 python ](day13/)
- [Day 13 C++ ](day13/src/)

<img  src="images/Day_13_00.png" /> 

RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./Octree 
```

### Lessons Learned

- [x] Octree division
- [x] Voxelization
- [x] Octree division (VoxelGrid to Octree)
- [x] Octree to VoxelGrid

### Screenshots

| Mesh to Point cloud (2000 samples)   |Octree division  |  Voxelization|   
|:------:|:-------------:|:----------------------:|
|<img  src="images/Day_13_01.png" width="300"/>  |<img  src="images/Day_13_02.png" width="300"/>|<img  src="images/Day_13_03.png" width="300"/>  |<img  



***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 14 & 15 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>

`ICP Registrations`

- [Day 14-15 python ](day14-15/)
- [Day 14-15 C++ ](day14-15/src/)

<img  src="images/Day_14-15.png" /> 


RUN:
```
  mkdir build
  cd build
  cmake ..
  make

  cd ../bin
  ./ICPReg
```

### Lessons Learned

- [x] transforming & transformation matrix
  - 4x4 matrix(`[R, t; 0, 1]`), 
  - `R` is a 3x3 `rotation matrix` and 
  - `t` is a 3x1 `translation vector`.
- [x] Applying point-to-point ICP
- [x] P-2-P ICP with 2000 iterations
- [x] Point-2-Plane ICP
- [x] Applying noise to point cloud
- [x] Robust point-to-plane ICP

### Screenshots

| Source + Target PCs   |  Source PC + Noise  |
|:------------------:|:--------------------:|
|<img  src="images/Day_14_01.png" width="300"/>  |<img  src="images/Day_14_05.png" width="300"/>|

|| point-to-point ICP   |P-2-P ICP with 2000 iterations    |Point-2-Plane ICP | 
|:------|:------:|:-------------:|:----------------------:|
||<img  src="images/Day_14_02.png" width="300"/>  |<img  src="images/Day_14_03.png" width="300"/>|<img  src="images/Day_14_04.png" width="300"/>  |
|__Run time__| 2.85 s ± 22.9 ms |11.9 s ± 264 ms | 2.75 s ± 25.6 ms  |
|__Fitness__ |0.372  |0.621|0.620  |
|__Inlier RMSE__| 0.00776 |0.006583|0.006581  |

|  Noisy source + Vanilla point-to-plane ICP| Noisy source +  Robust point-to-plane ICP | 
|:----------------------------------:|:-----------:|
|<img  src="images/Day_14_06.png" width="300"/>  |<img  src="images/Day_14_07.png" width="300"/>  |


***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 16 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>
    
</p>

<p align="center">  
  <img  src="images/mediapipe.png" height="40"/>    
</p>

`Draw the detected face landmarks: 2D and 3D`

- [Day 16 python ](day16/)

### Lessons Learned

- [x] Draw the detected face landmarks
- [x] read the video frame and do face mesh detection
- [x] Draw face landmarks in 3D in real time

### Screenshots

<img  src="images/Day_16.gif" /> 



