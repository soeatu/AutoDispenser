################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp *.bls *.libelf *.rel *.lbk *.abs *.mi *.jmp *.fsy *.ud *.udm 1st/*.abs 1st/*.jmp 1st/*.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif 
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif 
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif 
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif 
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif 
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif 
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif 
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif 
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif 
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif 
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif 
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif 
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif 
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif 
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif


-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables
LINKER_OUTPUT_OUTPUTS += \
RX220_OrigunalProject.abs

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
RX220_OrigunalProject.lib

CONVERTOR_OUTPUT_OUTPUTS += \
RX220_OrigunalProject.mot

OBJS := \
$(COMPILER_OBJS) \
$(INDIVIDUAL_COMPILER_OBJS) \
$(ASSEMBLER_OBJS) \
$(CUSTOM_OBJS)

# All Target
all: $(CONVERTOR_OUTPUT_OUTPUTS) RX220_OrigunalProject.x RX220_OrigunalProject.udm

	@echo 'Build complete.'

%.mot: $(LINKER_OUTPUT_OUTPUTS) Converter.sub
	@echo 'Invoking: Converter'
	@echo 'Building target:'
	@echo ConverterRX220_OrigunalProject.tmp=
	@sed -e "s/^/    /" "ConverterRX220_OrigunalProject.tmp"
	rlink -subcommand="ConverterRX220_OrigunalProject.tmp"
	@echo 'Finished building target:'
	@echo.


RX220_OrigunalProject.abs: $(OBJS)  $(ALL_ASMS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) 
	@echo 'Invoking: Linker'
	@echo LinkerRX220_OrigunalProject.tmp=
	@sed -e "s/^/    /" "LinkerRX220_OrigunalProject.tmp"
	rlink -subcommand="LinkerRX220_OrigunalProject.tmp"
	@echo 'Finished building:'
	@echo.


RX220_OrigunalProject.lib: 
	@echo 'Invoking: Library Generator'
	@echo LibraryGeneratorRX220_OrigunalProject.tmp=
	@sed -e "s/^/    /" "LibraryGeneratorRX220_OrigunalProject.tmp"
	lbgrx -subcommand="LibraryGeneratorRX220_OrigunalProject.tmp"
	@echo 'Finished building:'
	@echo.

RX220_OrigunalProject.x: RX220_OrigunalProject.abs
		-C:\Users\sp9e9\.eclipse\com.renesas.platform_1435879475\Utilities\\ccrx\renesas_cc_converter.exe RX220_OrigunalProject.abs RX220_OrigunalProject.x

RX220_OrigunalProject.udm: $(LINKER_OUTPUT_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
	udcollector -subcommand=udSubcommand.tmp -output=RX220_OrigunalProject.udm

# Other Targets
clean:
	-$(RM) $(LINKER_OUTPUT_OUTPUTS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
	-rm -rf $(OBJS) $(C_DEPS) $(ASM_DEPS) $(DSP_DEPS) 
	-rm -rf /*.asm /*.p /*.pp /*.src /*.jmp /*.lst /*.prn /*.i /*.ud 
	@echo
	@echo 'Clean complete.'

.PHONY: all clean  
-include ../makefile.targets