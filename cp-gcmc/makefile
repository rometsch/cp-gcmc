RM := rm -rf

# All of the sources participating in the build are defined here
CPP_SRCS := \
./Box.cpp \
./Rng.cpp \
./Rod.cpp \
./Sim.cpp \
./main.cpp \

OBJS += \
./Box.o \
./Rng.o \
./Rod.o \
./Sim.o \
./main.o \

CPP_DEPS += \
./Box.d \
./Rng.d \
./Rod.d \
./Sim.d \
./main.d \

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: cp-gcmc

# Tool invocations
cp-gcmc: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C++ Linker'
	g++ -O3 -o "cp-gcmc" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) n-body
	-@echo ' '
