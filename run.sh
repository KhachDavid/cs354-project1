#!/bin/bash

gcc -g -o Print_Table student_functions.c driver.c -Wall
./Print_Table > my_output1.txt
diff my_output1.txt table$1.txt