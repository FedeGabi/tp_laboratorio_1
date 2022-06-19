################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/Parser.c \
../src/Passenger.c \
../src/TP_[4].c \
../src/filters.c \
../src/inputs.c \
../src/ordenamientos.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/Parser.o \
./src/Passenger.o \
./src/TP_[4].o \
./src/filters.o \
./src/inputs.o \
./src/ordenamientos.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/Parser.d \
./src/Passenger.d \
./src/TP_[4].d \
./src/filters.d \
./src/inputs.d \
./src/ordenamientos.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


