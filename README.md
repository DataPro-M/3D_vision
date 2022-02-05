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

| Original | Voxel Downsampling  | Normal Estimation | Crop Point Cloud |
|:---------------:|:---------------:|:---------------:|:---------------:|
|<img  src="images/Day_02_01_org.gif" width="300"/>  |<img  src="images/Day_02_02_dws.gif" width="300"/>|<img  src="images/Day_02_03_nrm.gif" width="300"/> |<img  src="images/Day_02_04_crop.gif" width="300"/> |

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

| Painting point cloud | Removing object  | Convex hull  | 
|:---------------:|:---------------:|:---------------:|
|<img  src="images/Day_03_01_paint.gif" width="300"/>  |<img  src="images/Day_03_02_dist.gif" width="300"/>|<img  src="images/Day_03_03_convex.gif" width="300"/> |

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


<table>
  <thead>
    <tr>      
      <th>DBSCAN Clustering</th>
      <th>Plane segmentation</th>
      <th colspan="2">Hidden point removal</th>
    </tr>
  </thead>

  <tbody>    
    <tr>
      <td rowspan="2"><img  src="images/Day_03_04_DBSCAN.gif" width="300"/></td>
      <td rowspan="2"><img  src="images/Day_03_05_plain_seg.gif" width="300"/></td>
      <td>Before</td>
      <td>After</td>
    </tr>
    <tr>      
      <td><img  src="images/Day_03_06_hid_b4.gif" width="300"/></td>
      <td><img  src="images/Day_03_07_hid_aftr.gif" width="300"/></td>
    </tr>
  </tbody>
</table>

***

<h2 align="center">
      <i class="fas fa-calendar-day" aria-hidden="true">  Day 5 of #3D_vision_journey </i>
</h2>

<p align="center">
  <img  src="images/open3d_logo.png" height="50"/>  
</p>



- [Day 05 C++ Examples](day02-05)

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

