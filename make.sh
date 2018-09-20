
make -j10
sleep 2
make modules -j10
sleep 2
make modules_install
sleep 2
make install
sleep 2
#update-initramfs -u -k 4.4.7CLUSTERirq+

