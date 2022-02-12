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
