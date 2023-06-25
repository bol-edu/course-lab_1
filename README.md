# course-lab_1
Board: PYNQ-Z2, Vitis version: 2022.1 <br />
PYNQ-Z2 SD card image: v2.7 

[Youtube Demo Video](https://youtu.be/bXwMO-fN6BM) (Vitis version: 2020.2)

# Running 2022.1-Workbook-Lab1 on Ubuntu VM
The [2022.1-Workbook-Lab1.pdf](https://github.com/bol-edu/course-lab_1/blob/2022.1/2022.1-Workbook-Lab1.pdf) was tested on Windows host Vitis. While you running Workbook on Ubuntu VM, some items are needed to concern in following experimental steps.

## Vitis HLS
* The Vitis HLS can be invoked by two ways: (1) using MobaXterm SSH to Ubuntu VM and executing `vitis_hls` (2) opening Ubuntu VM terminal and executing `vitis_hls`(recommended).
* `vitis_hls` is running as a GUI. It is maybe slow under MobaXterm connection and while remote GUI is not working you need to restart MobaXterm.
* `git clone https://github.com/bol-edu/course-lab_1 ~/course-lab_1`, then change to `/course-lab_1` and execute `vitis_hls`.

![hls00](https://github.com/bol-edu/course-lab_1/assets/98332019/48d7250d-43b9-4399-b6e2-46cd71f21a5c)
  
* Click Create Project and name Project `hls_ip` under directory `~/course-lab_1`

![hls01](https://github.com/bol-edu/course-lab_1/assets/98332019/21a3a6e8-6f34-494b-a5eb-ef280aef8f70)

* No Add in Design Files & Testbench Files pages, then change Part to `xc7z020clg400-1` which is explained as Workbook p.4.

![hs02](https://github.com/bol-edu/course-lab_1/assets/98332019/13828340-eaf1-4fef-b0e7-61cbb53ccb54)

* Righ click on hls_ip/Source -> New Source File -> add `Multiplication.cpp` and `Multiplication.h` from `~/course-lab_1/hls_Multiplication`
* Change original `#include "multiplication.h"` to `#include "Multiplication.h"` and comment out `#pragma HLS INTERFACE ap_ctrl_none port=return` (as Workbook p.8 & p.9) in Multiplication.cpp, then save (ctrl-s).
  
![hls03](https://github.com/bol-edu/course-lab_1/assets/98332019/988d6181-a8c9-40ff-a146-fd33940869f9)

* Righ click on hls_ip/Test Bench -> New Source File -> add `MultipTester.cpp` from `~/course-lab_1/hls_Multiplication`
* Change original `#include "multiplication.h"` to `#include "Multiplication.h"` in MultipTester.cpp and save (ctrl-s).

![hls04](https://github.com/bol-edu/course-lab_1/assets/98332019/df7f1bfb-8ea1-4a73-b4d4-1693534b1198)

* Project -> Project Settings -> Synthesis Settings - Top Function name to `multip_2num` as Workbook p.6.

![hls05](https://github.com/bol-edu/course-lab_1/assets/98332019/a98bf20a-4c5f-4a79-816f-a679d4ec591e)

* Complete validations of C Simulation, C Synthesis, Cosimulation (Dump Trace all) and Open Wave Veiwer for your designed multiplier as Workbook p.7 ~ p.11.
* Export RTL as IP as Workbook p.11. Your designed multiplier `multip_2num` saved as a IP in directory `~/course-lab_1/hls_ip` which can be reused in later Vivado block design.
  
![hls07](https://github.com/bol-edu/course-lab_1/assets/98332019/e396a56d-9b78-4aff-98a6-c5dd9a3edc86)

## Vivado
* Close Vitis HLS GUI and execute `vivado` as Workbook p.12.

![vivado00](https://github.com/bol-edu/course-lab_1/assets/98332019/72290594-2f1d-43d3-a1dd-577c2e7f0ecd)

* Click Create Project and name Project `vivado` under directory `~/course-lab_1`

![vivado01](https://github.com/bol-edu/course-lab_1/assets/98332019/7c02e145-5673-4ae6-a750-389e2e2f85a1)
![vivado02](https://github.com/bol-edu/course-lab_1/assets/98332019/59a863c1-ccd1-4bbc-93f6-57b1ffc4a507)
![vivado03](https://github.com/bol-edu/course-lab_1/assets/98332019/61b4d83c-a5bc-4b23-ad2c-8307cb7fdcf0)
![vivado04](https://github.com/bol-edu/course-lab_1/assets/98332019/8cbd7dce-4521-4b00-95f1-f844fde70b15)

* Setting -> IP -> Repository -> IP Repositories -> ＋ -> ~/course-lab_1 -> hls_ip -> select -> Multip_2num -> OK

![vivado05](https://github.com/bol-edu/course-lab_1/assets/98332019/259b9725-1a62-4082-bddf-a821495b82e1)
![vivado06](https://github.com/bol-edu/course-lab_1/assets/98332019/8052fd17-46c0-425c-b866-102c55ff7c52)
![vivado07](https://github.com/bol-edu/course-lab_1/assets/98332019/634721b5-545f-4233-8622-fdaa76f9e962)
![vivado08](https://github.com/bol-edu/course-lab_1/assets/98332019/92315a20-3e6e-4e66-bb1d-ac35b829d0b5)

* Vivado block design as Workbook p.16 ~ p.20.
* Generate Bitstream takes about 18 minutes to finish on Ubuntu VM (8GB memory & 2 vcpu of i7＠2.20GHz) with 2 jobs (Vivado launching runs) as Workbook p.20.
* The Windows `MakeBit.bat` can not work on Ubuntu VM as Workbook p.21, please refer the provided copy example. The copy example assume your Vivado project is `/home/ubuntu/course-lab_1/vivado`.
```console
cd ~/course-lab_1
cp ./vivado/vivado.runs/impl_1/design_1_wrapper.bit ./Multip2Num.bit
cp ./vivado/vivado.gen/sources_1/bd/design_1/hw_handoff/design_1.hwh ./Multip2Num.hwh
```
## PYNQ-Z2 Board
* Rent your pynq-z2 board from OnlineFPGA and connect it via web browser
```
all online device boards
{'device': 'pynq_01',  'status': 'available'}
{'device': 'pynq_02',  'status': 'available'}
{'device': 'pynq_03',  'status': 'available'}
{'device': 'pynq_04',  'status': 'available'}
{'device': 'pynq_05',  'status': 'available'}
{'device': 'pynq_06',  'status': 'available'}
{'device': 'pynq_07',  'status': 'available'}
{'device': 'pynq_09',  'status': 'available'}
{'device': 'pynq_11',  'status': 'available'}
{'device': 'pynq_12',  'status': 'available'}
{'device': 'pynq_13',  'status': 'available'}
{'device': 'pynq_14',  'status': 'available'}
{'device': 'pynq_15',  'status': 'available'}
{'device': 'pynq_16',  'status': 'available'}
{'device': 'pynq_17',  'status': 'available'}
{'device': 'pynq_18',  'status': 'available'}

please enter pynq device name which you want to rent:
>> pynq_05
device pynq_05 is available
do you want to rent this device? (y/n)
>> y
user test1@gmail.com rented device pynq_05 successfully
jupyter web ip port is 140.112.207.200:20500, web passwd is EjbnxV and timeup at 06/25/2023 01:20:21

```
![pynq00](https://github.com/bol-edu/course-lab_1/assets/98332019/6d432bb8-759e-40ea-82fb-de039dd3a10c)

Upload `Multip2Num.bit`, `Multip2Num.hwh` and [Multip2Num.ipynb](https://github.com/bol-edu/course-lab_1/blob/2022.1/ipy_Multip2Num/Multip2Num.ipynb) to Jupyter Notebook from local via web browser. (Not MobaXterm as Workbook p.21)

![pynq01](https://github.com/bol-edu/course-lab_1/assets/98332019/0b23df28-f28d-45b6-af34-58c404089b3d)

![pynq02](https://github.com/bol-edu/course-lab_1/assets/98332019/b4981f5d-1f2d-459f-9236-b84130a43c6d)

* Click `Multip2Num.ipynb` to open in new tab and Run its cell.

![pynq03](https://github.com/bol-edu/course-lab_1/assets/98332019/ff06fc30-c7c5-4691-afb7-49690c5b22cd)


