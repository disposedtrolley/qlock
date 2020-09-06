echo Executing GDB with .gdbinit to connect to OpenOCD.\n

# Connect to OpenOCD
target remote localhost:3333

# Load the binary.
load build/qlock.elf
symbol-file build/qlock.elf

# Reset the target and call its init script
monitor reset init

# Halt the target. The init script should halt the target, but just in case
monitor halt
