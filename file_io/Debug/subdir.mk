################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lseek.c \
../main_files.c \
../open_demo.c \
../read_demo.c \
../write_demo.c 

C_DEPS += \
./lseek.d \
./main_files.d \
./open_demo.d \
./read_demo.d \
./write_demo.d 

OBJS += \
./lseek.o \
./main_files.o \
./open_demo.o \
./read_demo.o \
./write_demo.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./lseek.d ./lseek.o ./main_files.d ./main_files.o ./open_demo.d ./open_demo.o ./read_demo.d ./read_demo.o ./write_demo.d ./write_demo.o

.PHONY: clean--2e-

