clear
echo "User name is $USER"
echo "Logname is $LOGNAME"
echo "Current Shell is $SHELL"
echo "Home Directory is $HOME"
echo "Operating System `uname -o`"
echo "Current Path $PATH"
echo "Current Directory `pwd`"
echo "Current Logged Users $nouser"
echo "About OS Version `uname -a`"
echo "Model: `cat /proc/ide/hda/model` "
echo "available shells are: `cat /etc/shells`"
echo "`xinput --list --short`"
echo "CPU information are: `cat /proc/cpuinfo`"
echo "Memeory information are:`cat /proc/meminfo`"
echo "hard disk information: `lscpu`"
echo "file system mounted `df -T`"
