SET PATH=C:\Program Files (x86)\keil MKD 5\ARM\ARMCC\Bin;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\Microsoft SQL Server\120\DTS\Binn\;C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\110\Tools\Binn\;C:\Program Files (x86)\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files (x86)\Microsoft SQL Server\120\Tools\Binn\ManagementStudio\;C:\Program Files (x86)\Microsoft SQL Server\120\DTS\Binn\;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files (x86)\Skype\Phone\;C:\Users\kargadan\AppData\Local\Programs\Python\Python36-32\Scripts\;C:\Users\kargadan\AppData\Local\Programs\Python\Python36-32\;%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;C:\Users\kargadan\AppData\Local\Programs\Python\Python36-32\Scripts\;C:\Users\kargadan\AppData\Local\Programs\Python\Python36-32\;C:\Users\kargadan\AppData\Local\Microsoft\WindowsApps;C:\Xilinx\win64;C:\modeltech64_10.5\win64;
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=LPC1768
SET CPU_VENDOR=NXP
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"C:\Program Files (x86)\keil MKD 5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\spi.__i"
"C:\Program Files (x86)\keil MKD 5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\system_lpc17xx.__i"
"C:\Program Files (x86)\keil MKD 5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\startup_lpc17xx._ia"
"C:\Program Files (x86)\keil MKD 5\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\SPI.lnp"
"C:\Program Files (x86)\keil MKD 5\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\SPI.axf" --i32combined --output ".\Objects\SPI.hex"
