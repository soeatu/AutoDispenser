################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../ADT7410_TempSencer.c \
../Dispenser.c \
../HC_SR04.c \
../Hardware_Setup.c \
../MTU_PWM.c \
../RS232C_signal.c \
../RX220_OrigunalProject.c \
../SCI1.c \
../Timer.c \
../dbsct.c \
../intprg.c \
../resetprg.c \
../sbrk.c \
../temperture.c \
../vecttbl.c 

COMPILER_OBJS += \
ADT7410_TempSencer.obj \
Dispenser.obj \
HC_SR04.obj \
Hardware_Setup.obj \
MTU_PWM.obj \
RS232C_signal.obj \
RX220_OrigunalProject.obj \
SCI1.obj \
Timer.obj \
dbsct.obj \
intprg.obj \
resetprg.obj \
sbrk.obj \
temperture.obj \
vecttbl.obj 

C_DEPS += \
ADT7410_TempSencer.d \
Dispenser.d \
HC_SR04.d \
Hardware_Setup.d \
MTU_PWM.d \
RS232C_signal.d \
RX220_OrigunalProject.d \
SCI1.d \
Timer.d \
dbsct.d \
intprg.d \
resetprg.d \
sbrk.d \
temperture.d \
vecttbl.d 

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo cDepSubCommand.tmp=
	@sed -e "s/^/ /" "cDepSubCommand.tmp"
	ccrx -subcommand="cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo cSubCommand.tmp=
	@sed -e "s/^/ /" "cSubCommand.tmp"
	ccrx -subcommand="cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

