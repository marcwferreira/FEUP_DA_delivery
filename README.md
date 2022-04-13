# Urban Logistics for Goods Delivery

First Group Work (T1) of Algorithm Design

## Installation

```
mkdir build/
cd build
cmake ..
```

## Compilation

```
cmake --build .
```

## Run

```
./project <MODE> <PACKAGES> [TRUCKS] [OUTPUT]
```

## Help

````
./project --help

		<MODE>
		   1: Optimization of the number of trucks
			  ./project <MODE> <PACKAGES> <TRUCKS> [OUTPUT]
		   2: Optimization of the profit
			  ./project <MODE> <PACKAGES> <TRUCKS> [OUTPUT]
		   3: Optimization of the express deliveries
			  ./project <MODE> <PACKAGES> [OUTPUT]

		<PACKAGES>
		   Name of Packages dataset in input folder

		[TRUCKS]
		   Name of Trucks dataset in input folder

		[OUTPUT]
		   Name of output file. Always optional
```
