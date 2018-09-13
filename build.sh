#!/bin/bash

make modules_install && make install
cp /boot/vmlinuz-4.4.7CLUSTERirq+ ./
cp /boot/initrd.img-4.4.7CLUSTERirq+ ./

