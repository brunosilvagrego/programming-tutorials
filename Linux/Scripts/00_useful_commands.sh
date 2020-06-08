# Displays the content of the identified file
cat filename

# Moves you to the identified directory
cd dirname

# Moves you to the home directory
cd ~

# Moves you to the parent directory
cd ..

# Copies one file/directory to the specified location
cp file1 file2

# Identifies the file type (binary, text, etc)
file filename

# Finds a file/directory
find filename dir

# Shows the beginning of a file
head filename

# Browses through a file from the end or the beginning
less filename

# Shows the contents of the directory specified
ls dirname

# List the contents of the current directory with more information
ls -l

# List the contents of the current directory, including hidden files
ls -a

# ls command with pipes and filters
# "grep" comes from the ed (a Unix line editor) command g/re/p which means “globally search for a regular expression and
# print all lines containing it”
ls -l | grep "Aug" | sort +4n | more

# Creates the specified directory
mkdir dirname

# Browses through a file from the beginning to the end
more filename

# Moves the location of, or renames a file/directory
mv file1 file2

# Shows the current directory the user is in
pwd

# Removes a file
rm filename

# Removes a directory
rmdir dirname

# Shows the end of a file
tail filename

# Creates a blank file or modifies an existing file or its attributes
touch filename

# Shows the location of a file
whereis filename

# Shows the location of a file if it is in your PATH
which filename

# This command uses symbolic permissions notation. The letters u, g, and o stand for "user", "group", and "other".
# The equals sign ("=") means "set the permissions exactly like this," and the letters "r", "w", and "x" stand for "read", "write",
# and "execute", respectively. The commas separate the different classes of permissions, and there are no spaces in between them.
chmod u=rwx,g=rx,o=r myfile

# This command is the equivalent to the previous command using octal permissions notation
chmod 754 myfile

# Displays disk space usage in human readable format
df -h

# Displays directory usage in human readable format
du -h

# Prints network connections, routing tables, interface statistics, masquerade connections, and multicast memberships
netstat

# Helps time a simple command or give resource usage
time

# This is System Load Average
uptime

# Reports a snapshot of the current processes
ps

# -a => Shows information about all users
# -u => Shows additional information
# -x => Shows information about processes without terminals
ps -aux

# Reports virtual memory statistics
vmstat

# Displays system tasks
top

# kills the process running with the indicated pid
kill -9 pid

# Brings the system down immediately
halt

# Powers off the system using predefined scripts to synchronize and clean up the system prior to shutting down
init 0

# Reboots the system by shutting it down completely and then restarting it
init 6

# Shuts down the system by powering off
poweroff

# Reboots the system
reboot

# Shuts down the system
shutdown