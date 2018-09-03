#!/usr/bin/env bash
#Copyleft 2018 Abhiram Shibu
#QUESTION - 1.your OS and version, release number, kernel version 2. all available shells 3. computer CPU information like processor type, speed etc 4. memory information 5. hard disk information like size of hard-disk, cache memory, model etc 6. File system (Mounted)
. colors.sh
echo -e "$GREEN"
echo OS INFO: $(uname -o)
echo OS Version: $(cat /etc/issue)
echo Kernel Version: $(uname -v)
echo Release Number: $(uname -r)
echo Shells: $(cat /etc/shells)
echo CPU INFO
echo $(lshw -c cpu)
echo CACHE INFO
head -10 /proc/cpuinfo | grep cache
echo MEM INFO
echo $(lshw -c memory)
echo DISK INFO
echo $(lshw -c disk)
echo  Mounted File Systems
findmnt -m -o TARGET
echo -e $RESET