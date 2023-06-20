## Ubuntu 20.04+ Virtual Machine on Windows
[Manual of setup Ubuntu 20.04+ VM](https://github.com/bol-edu/soclab-nthusp23/files/11799408/Ubuntu_VM_on_Windows.pdf).

## Install Xilinx Vitis 2022.1 on Ubuntu 20.04+ Machine
* The Xilinx Vitis 2022.1 requires roughly 200 GB of disk space to install
* Install necessary dependencies before Vitis installation: `sudo apt install libtinfo5 libncurses5 -y`
* Offical installation guide: https://docs.xilinx.com/r/2022.1-English/ug1400-vitis-embedded/Installation-Requirements  
* Refer the [HLS Tools Installation Guide 2022.1 of Windows](https://github.com/bol-edu/course-lab_1/blob/2022.1/HLS%20Tools%20Installation%20Guide%202022.1.pdf)  
* Add below lines to `/home/<user>/.bashrc` after completing Vitis installation  
`source <Vitis_install_path>/Xilinx/Vitis/2022.1/settings64.sh`  
`source <Vitis_install_path>/xilinx/xrt/setup.sh`  
* Before running Vitis `source /home/<user>/.bashrc`
