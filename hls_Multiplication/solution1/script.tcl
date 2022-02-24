############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_Multiplication
set_top multip_2num
add_files hls_Multiplication/Multiplication.cpp
add_files hls_Multiplication/Multiplication.h
add_files -tb hls_Multiplication/MultipTester.cpp
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 5 -name default
config_export -format ip_catalog -rtl verilog
#source "./hls_Multiplication/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
