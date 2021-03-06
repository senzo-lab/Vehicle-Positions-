# Vehicle Positions Interview Challenge
I am required to find the 10 closest vehicles for a given set of reference coordinates.

## Approach
I split the task of finding the top ten vehicles into three steps: read data, calculate distances and sort vehicles.

Image

### Read data
- Create a struct to represent the position data in memory. This will make it easy to manapulate each vehicle as a single entity. The vehicles will be stored in an array in heap memory as it's a large dataset.
- Read *positions.dat* using *fread.* Data in *positions* is stored sequentially and will be read sequentially. Some vehicle data is not necessary for this problem like *registration*, *UTCTimestamp*. This data was not used to save memory.

### Calculate distances between vehicles and given reference coordinates
- Store reference coordinates in an array.
- Use *Harvesine equation* to calculate distance between vehicles and reference point. 

### Sort vehicles for each reference coordinate
- Test different sort algorithm
	- Bubble Sort / two for loops (Benchmark)
	- Selection Sort
	- Merge Sort
	- Quick Sort
- Choose best algorithm
- Display top ten vehicles for each point

## Implementation
I devided the solution into five files:
- *main.c*
- *sort.c*
- *dist.c*
- *read.c*
- *Makefile*

The compiled solution is *findvehicles.exe*.

### *main.c* 
This is the driver file. The program is executed from here. 
- Declare variables: vehicles, timing
- Call read data function
- Call calculate distances function
- Calculate duration
- Display data

### ***sort.c***
Performs all the sorting to determine the top vehicles. The algorithm used are
- Merge Sort
- Quick Sort
- Selection Sort
- Bubble Sort

### ***dist.c***
Calculates the distance between vehicles and coordinates.
- Reference potions
- calculate distance for a single point.
- calculate distance for a many points.

### ***Read.c***
- Open file for reading as a binary file.
- Read data sequentially to get
	- position ID
	- Registration (not used)
	- Latitude
	- Longitude
	- UTC Timestamp (not used)
- Vehicles struc array created 
- Display top ten vehicles

### ***Makefile***
Used to compile the program. To compile use `make all`. O2 optimisation was used.

## Results
When the solution was run these were the results.

### Speed
#### Sort
The order in which algorithms took to sort 2 million vehicles 10 times:
1. Merge Sort ***6-8 seconds***
2. Quick Sort ***4 minutes***
3. Selection Sort ***30-40 minutes***
4. Bubble Sort ***> 1 hour*** 

#### Read
The read speed on average was ***4 seconds***.

#### Memory
Merge Sort and quicksort were memory intensive. Therefore arrays were declared on the heap memory.

### Top ten vehicles
The top ten places for each reference coordinate was calculated and shown. Each column corresponds to a reference coordinate/point. The  *positionID* of the vehicles closest to a particular point is listed in that column.

**Merge Sort**
![mergesort](https://user-images.githubusercontent.com/70967943/162802274-c220e08c-99cf-4de1-99ee-f56dc01a5587.PNG)

**Quick sort**
![quicksort](https://user-images.githubusercontent.com/70967943/162802310-0e41f2d4-55ba-46a6-b4bb-243f8b586027.PNG)


## Type of solutions
I created two solutions for this project, `main` for the best performing algorithm and `allsorts` where you can choose which algorithm you want to use or test.

- Main branch on GitHub
- Allsorts branch on GitHub
