## Install Xilinx Vitis on Ubuntu 20.04+ Machine
The Xilinx Vitis needs minimum 16 GB system memory (32 GB+ is recommended) on a physical/virtual Ubuntu 20.04+ machine.
* Install necessary dependencies before Vitis installation: `sudo apt install libtinfo5 libncurses5 -y`
* Offical installation guide: https://docs.xilinx.com/r/2022.1-English/ug1400-vitis-embedded/Installation-Requirements  
* Refer the [HLS Tools Installation Guide 2022.1 of Windows](https://github.com/bol-edu/course-lab_1/blob/2022.1/HLS%20Tools%20Installation%20Guide%202022.1.pdf)  
* Add below lines to `/home/<user>/.bashrc` after completing Vitis installation  
`source <Vitis_install_path>/Xilinx/Vitis/2022.1/settings64.sh`  
`source <Vitis_install_path>/xilinx/xrt/setup.sh`  
* Before running Vitis `source /home/<user>/.bashrc`
