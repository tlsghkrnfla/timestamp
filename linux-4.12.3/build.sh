#!/bin/bash

make modules_install && make install
cp /boot/vmlinuz-4.12.3 ./
cp /boot/initrd.img-4.12.3 ./

