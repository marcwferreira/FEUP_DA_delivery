# Urban Logistics for Goods Delivery

IMPORTANT - the files generate by the program is stored in the output folder (on the main folder, together with src, documentation, etc)

## Installation

```
mkdir output/
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

```
./project --help

		 <MODE>
                   1: Optimization of the number of trucks
                          ./project <MODE> <PACKAGES> <TRUCKS> [OUTPUT]
                   2: Optimization of the profit
                          ./project <MODE> <PACKAGES> <TRUCKS> [OUTPUT]
                   3: Optimization of the express deliveries
                          ./project <MODE> <PACKAGES> [TIME] [OUTPUT]

                <PACKAGES>
                   Name of Packages dataset in input folder

                <TRUCKS>
                   Name of Trucks dataset in input folder

                [TIME]
                   Number of seconds of work time. Must be always be positive (Optional)

                [OUTPUT]
                   Name of output file. Always optional
```
