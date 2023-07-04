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
* Change original `#include "multiplication.h"` to `#include "Multiplication.h"` (Ubuntu/Linux is case sensitivity) and comment out `#pragma HLS INTERFACE ap_ctrl_none port=return` in Multiplication.cpp (as Workbook p.8 & p.9), then save (ctrl+s).
  
![hls03](https://github.com/bol-edu/course-lab_1/assets/98332019/988d6181-a8c9-40ff-a146-fd33940869f9)

* Righ click on hls_ip/Test Bench -> New Source File -> add `MultipTester.cpp` from `~/course-lab_1/hls_Multiplication`
* Change original `#include "multiplication.h"` to `#include "Multiplication.h"` (Ubuntu/Linux is case sensitivity) in MultipTester.cpp and save (ctrl+s).

![hls04](https://github.com/bol-edu/course-lab_1/assets/98332019/5d6e0ea8-26fc-4eb4-8a7a-0eef53a519ec)

* Project -> Project Settings -> Synthesis Settings - Top Function name to `multip_2num` as Workbook p.6.

![hls05](https://github.com/bol-edu/course-lab_1/assets/98332019/a98bf20a-4c5f-4a79-816f-a679d4ec591e)

* Complete validations of C Simulation, C Synthesis, Cosimulation (Dump Trace all) and Open Wave Veiwer for your multiplier as Workbook p.7 ~ p.11.

![hls07-1](https://github.com/bol-edu/course-lab_1/assets/98332019/33e40c06-760b-4b09-866b-48249c19892c)
![hls07-2](https://github.com/bol-edu/course-lab_1/assets/98332019/e38662e6-23f5-420a-b768-bd2119f2ff8b)
![hls07-3](https://github.com/bol-edu/course-lab_1/assets/98332019/58bb0a54-4106-49d3-8c57-1b359a1171f3)

* Before Export RTL as IP, you need to remove comment out `#pragma HLS INTERFACE ap_ctrl_none port=return` in `Multiplication.cpp` (ctrl+s) and re-run C Synthesis as Workbook p.11.

![hls08-2](https://github.com/bol-edu/course-lab_1/assets/98332019/1591db57-de30-44c5-ac9a-ad248cd5f6f9)
![hls08-3](https://github.com/bol-edu/course-lab_1/assets/98332019/01200611-106a-400e-a246-9348cd6e864e)
![hls08-4](https://github.com/bol-edu/course-lab_1/assets/98332019/3eead3bb-4eb8-48f2-a461-496d03bdf4f8)

* Export RTL as IP as Workbook p.11. Your multiplier `multip_2num` saved as a IP in directory `~/course-lab_1/hls_ip` which can be reused in later Vivado block design.
    
![hls08-0](https://github.com/bol-edu/course-lab_1/assets/98332019/6c3af30a-56ab-47ce-b33c-f17e1dad8823)
![hls08-1](https://github.com/bol-edu/course-lab_1/assets/98332019/1bb55065-36c7-4840-bcde-8000cd7f2a48)


## Vivado
* Close Vitis HLS GUI and execute `vivado` as Workbook p.12.

![vivado00](https://github.com/bol-edu/course-lab_1/assets/98332019/72290594-2f1d-43d3-a1dd-577c2e7f0ecd)

* Click Create Project and name Project `vivado` under directory `~/course-lab_1`

![vivado01](https://github.com/bol-edu/course-lab_1/assets/98332019/7c02e145-5673-4ae6-a750-389e2e2f85a1)
![vivado02](https://github.com/bol-edu/course-lab_1/assets/98332019/59a863c1-ccd1-4bbc-93f6-57b1ffc4a507)
![vivado03](https://github.com/bol-edu/course-lab_1/assets/98332019/61b4d83c-a5bc-4b23-ad2c-8307cb7fdcf0)
![vivado04](https://github.com/bol-edu/course-lab_1/assets/98332019/8cbd7dce-4521-4b00-95f1-f844fde70b15)

* Add multiplier `multip_2num` IP to Vivado: Settings -> IP -> Repository -> IP Repositories -> ＋ -> ~/course-lab_1 -> hls_ip -> select -> Multip_2num -> OK

![vivado05](https://github.com/bol-edu/course-lab_1/assets/98332019/259b9725-1a62-4082-bddf-a821495b82e1)
![vivado06](https://github.com/bol-edu/course-lab_1/assets/98332019/8052fd17-46c0-425c-b866-102c55ff7c52)
![vivado07](https://github.com/bol-edu/course-lab_1/assets/98332019/634721b5-545f-4233-8622-fdaa76f9e962)
![vivado08](https://github.com/bol-edu/course-lab_1/assets/98332019/9d768a3f-1783-429b-8803-a705a88db403)

* Create Block Design: double click Create Block Design -> add ZYNQ7 -> add multiplier `multip_2num` -> click regenerate layout -> click Run Block Automation -> double click ZYNQ7 block -> click Clock Configuration -> change to 100Mhz (due to your clock period is 10ns) -> click Run Connection Automation as Workbook p.16 ~ p.19.
  
![vivado-design00](https://github.com/bol-edu/course-lab_1/assets/98332019/c1cd1e65-c6f5-47b8-83be-4aea99f1f555)
![vivado-design01](https://github.com/bol-edu/course-lab_1/assets/98332019/ff08bb92-f50e-4b7a-a950-d207ec452018)
![vivado-design02](https://github.com/bol-edu/course-lab_1/assets/98332019/75f09f12-6303-45bd-b803-73eae499a8c2)
![vivado-design03](https://github.com/bol-edu/course-lab_1/assets/98332019/8e6b8efd-82a1-4949-bb46-2d0a4938a0aa)
![vivado-design04](https://github.com/bol-edu/course-lab_1/assets/98332019/61695bfc-18e6-45a6-a0ca-aa8a2592cfec)
![vivado-design05](https://github.com/bol-edu/course-lab_1/assets/98332019/bb04d1cd-6082-4f31-b325-44277815a94b)
![vivado-design06](https://github.com/bol-edu/course-lab_1/assets/98332019/a0f12ffd-0237-4065-a214-70e7d80ff7cc)
![vivado-design07](https://github.com/bol-edu/course-lab_1/assets/98332019/5ce162c4-ffe6-4a85-8b1f-5ae4ca554401)
![vivado-design08](https://github.com/bol-edu/course-lab_1/assets/98332019/6442ce22-51c4-4ebe-aa0d-68fcfd0aa0e5)
![vivado-design09](https://github.com/bol-edu/course-lab_1/assets/98332019/0b70e8c7-e951-4c52-b240-382207b14268)
![vivado-design10](https://github.com/bol-edu/course-lab_1/assets/98332019/e7072e59-6b7b-4b1d-bc68-09d9d11800dd)
![vivado-design11](https://github.com/bol-edu/course-lab_1/assets/98332019/a4370a16-9423-4141-bef8-7f8af80a1756)
![vivado-design12](https://github.com/bol-edu/course-lab_1/assets/98332019/22db7dfb-207b-4994-ad60-366050b2e4bc)

* Right click design_1 in Sources window to generate HDL wrapper as Workbook p.20.

![vivado-design13](https://github.com/bol-edu/course-lab_1/assets/98332019/a60db0f2-34d2-4539-85e4-7348a70bba4f)
![vivado-design14](https://github.com/bol-edu/course-lab_1/assets/98332019/1e29a3ed-81de-4241-b48e-37153a6b9ec7)
![vivado-design15](https://github.com/bol-edu/course-lab_1/assets/98332019/b496d461-f64a-4c6b-b4c4-db4de30a679f)

* Generate FPGA bitstream takes about 18 minutes to finish on Ubuntu VM (8GB memory & 2 vcpu of i7＠2.20GHz) with 2 jobs as Workbook p.20. While you see Bitstream Generation Completed window pop (you can cancel the window), your bitstream files are ready to download.

![vivado-design16](https://github.com/bol-edu/course-lab_1/assets/98332019/c4e78b6c-5e64-48ac-aab6-52b06f60d0a3)
![vivado-design17](https://github.com/bol-edu/course-lab_1/assets/98332019/70e1e43d-2ec0-4e1c-927d-cf39c5678b1e)
![vivado-design18](https://github.com/bol-edu/course-lab_1/assets/98332019/f3510428-3eeb-4027-a73e-d0b544d72c97)

* The Windows `MakeBit.bat` script can not work on Ubuntu VM as Workbook p.21, please refer the provided copy example. The copy example assume your Vivado project is `~/course-lab_1/vivado`. After copy FPGA bitstream files to `~/course-lab_1`, you can download `Multip2Num.bit` and `Multip2Num.hwh` via MobaXterm.
```console
cd ~/course-lab_1
cp ./vivado/vivado.runs/impl_1/design_1_wrapper.bit ./Multip2Num.bit
cp ./vivado/vivado.gen/sources_1/bd/design_1/hw_handoff/design_1.hwh ./Multip2Num.hwh
```
![moba](https://github.com/bol-edu/course-lab_1/assets/98332019/ccfa2e5d-ae5a-40f0-9166-123b88009e01)

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

* Click `Multip2Num.ipynb` to open it in new tab and Run its cell. You have verified multiplier `multip_2num` work correctly on FPGA board.

![pynq_final-00](https://github.com/bol-edu/course-lab_1/assets/98332019/19ae614f-da84-44ca-a02d-fdbf8c737507)
![pynq_final-01](https://github.com/bol-edu/course-lab_1/assets/98332019/65210e08-ca9e-4178-9bc7-38cd0bf0860a)


