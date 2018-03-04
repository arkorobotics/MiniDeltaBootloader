How to flash the Motion Controller with hacked firmware:
========================================================
Terminal 1:
------------------------------------------------------------------------------------------------------------------------------
$ cd [working directory]
$ openocd -f /usr/local/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/local/share/openocd/scripts/target/stm32f0x.cfg

output:
-------
adapter speed: 1000 kHz
adapter_nsrst_delay: 100
none separate
Info : Unable to match requested speed 1000 kHz, using 950 kHz
Info : Unable to match requested speed 1000 kHz, using 950 kHz
Info : clock speed 950 kHz
Info : STLINK v2 JTAG v17 API v2 SWIM v4 VID 0x0483 PID 0x3748
Info : using stlink api v2
Info : Target voltage: 3.126620
Info : stm32f0x.cpu: hardware has 4 breakpoints, 2 watchpoints

procedure:
----------
See Terminal 2


Terminal 2:
------------------------------------------------------------------------------------------------------------------------------
$ telnet localhost 4444

output:
-------
Trying ::1...
telnet: connect to address ::1: Connection refused
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Open On-Chip Debugger
>

procedure:
----------
> reset halt
adapter speed: 1000 kHz
target halted due to debug-request, current mode: Thread
xPSR: 0xc1000000 pc: 0xfffffffe msp: 0xfffffffc


> stm32f0x mass_erase 0
device id = 0x20016448
flash size = 128kbytes
stm32x mass erase complete

>flash write_bank 0 hacked_v41.bin 0




