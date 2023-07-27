## Ubuntu 20.04+ Virtual Machine on Windows
[Manual of setup Ubuntu 20.04+ VM](https://github.com/bol-edu/course-lab_1/files/11862640/Ubuntu_VM_on_Windows.pdf).

## Install Xilinx Vitis 2022.1 on Ubuntu 20.04+ Machine
* The Xilinx Vitis 2022.1 requires roughly 200 GB of disk space to install
* Install necessary dependencies before Vitis installation: `sudo apt install libtinfo5 libncurses5 -y`
* Offical installation guide: https://docs.xilinx.com/r/2022.1-English/ug1400-vitis-embedded/Installation-Requirements  
* Add below line to `/home/<user>/.bashrc` after completing Vitis installation  
`source <Vitis_install_path>/Xilinx/Vitis/2022.1/settings64.sh`  
* [Manual of Vitis_on_Ubuntu_VM](https://github.com/bol-edu/course-lab_1/files/12188820/Vitis_on_Ubuntu_VM.pdf)

## Notice
Do not click Yes, Upgrade Now or execute `sudo apt upgrade` in your Ubuntu VM. The Vitis maybe not working.

![000](https://github.com/bol-edu/course-lab_1/assets/98332019/2aef1059-9bb8-4f84-b341-ecb0ce45e8ba)
