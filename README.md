# course-lab_1
Board: PYNQ-Z2, Vitis version: 2022.1 <br />
PYNQ-Z2 SD card image: v2.7 

[Youtube Demo Video](https://youtu.be/bXwMO-fN6BM) (Vitis version: 2020.2)

# Running 2022.1-Workbook-Lab1 on Ubuntu VM
The [2022.1-Workbook-Lab1.pdf](https://github.com/bol-edu/course-lab_1/blob/2022.1/2022.1-Workbook-Lab1.pdf) was tested on Windows host Vitis. While you running Workbook-Lab1 on Ubuntu VM, below items are needed to concern.
* The Vitis HLS can be invoked by two ways: (1) using MobaXterm SSH to Ubuntu VM and executing `vitis_hls` (2) opening Ubuntu VM terminal and executing `vitis_hls`(recommended).
    
![001](https://github.com/bol-edu/course-lab_1/assets/98332019/651c4b19-be65-46e2-9f1b-6fba00d3b294)

* `vitis_hls` is running as a GUI. It is slow under MobaXterm and sometimes the GUI is not working you need to restart MobaXterm.    
* Changing original `#include "multiplication.h"` to `#include "Multiplication.h"` in Multiplication.cpp at Workbook p.5.
  
![002](https://github.com/bol-edu/course-lab_1/assets/98332019/91fe5cd8-07b0-4335-8c48-fb0fd1136f07)

* Changing original `#include "multiplication.h"` to `#include "Multiplication.h"` in MultipTester.cpp at Workbook p.5.

![003](https://github.com/bol-edu/course-lab_1/assets/98332019/5e736128-9d1b-4d57-b6d2-31f36f2ca0cb)

* Comment out `#pragma HLS INTERFACE ap_ctrl_none port=return` before running C Synthesis & Cosimulation at Workbook p.8 & p.9. (Both on Windows host Vitis & Ubuntu VM)

![04](https://github.com/bol-edu/course-lab_1/assets/98332019/97e21e36-bef7-403d-97a4-ca8aae108910)
  
* After Export RTL as IP is OK, then you need to close Vitis HLS GUI and execute `vivado` at Workbook p.12.

![vivado](https://github.com/bol-edu/course-lab_1/assets/98332019/8f639328-e9e2-492e-8988-6e2082878271)

* Generate Bitstream takes about 18 minutes to finish on Ubuntu VM (8GB memory & 2 vcpu of i7＠2.20GHz) with 2 jobs (Vivado launching runs) at Workbook p.20.
* The `MakeBit.bat` can not work on Ubuntu VM at Workbook p.21. If your Vivado project is `/home/ubuntu/lab1_vivado` created at Workbook p.13. You need replace `lab1_vivado` in following example with your created Vivado project name.
```console
cd ~/lab1_vivado
cp ./lab1_vivado.runs/impl_1/design_1_wrapper.bit ./Multip2Num.bit
cp ./lab1_vivado.gen/sources_1/bd/design_1/hw_handoff/design_1.hwh ./Multip2Num.hwh
```

