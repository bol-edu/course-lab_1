## Install Xilinx Vitis on Ubuntu 20.04+ Machine
The Xilinx Vitis needs minimum 32 GB system memory (64 GB is recommended) on a physical/virtual machine.
* Install necessary dependencies before Vitis installation: `sudo apt install libtinfo5 libncurses5 -y`
* Follow offical installation guide: https://docs.xilinx.com/r/2022.1-English/ug1400-vitis-embedded/Installation-Requirements  
* Add below lines to `/home/<user>/.bashrc` after completing Vitis installation  
`source <Vitis_install_path>/Xilinx/Vitis/2022.1/settings64.sh`  
`source <Vitis_install_path>/xilinx/xrt/setup.sh`  
* Before running Vitis `source /home/<user>/.bashrc`
