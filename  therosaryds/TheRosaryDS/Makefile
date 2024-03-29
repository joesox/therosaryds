# This Makefile is optimized for PALib AppWizard for Visual Studio 2005
# By Rodrigo Sieiro

OFILES   +=
PATH 		:= $(DEVKITARM)/bin:$(PATH)
ARM7BIN		:= -7 $(PAPATH)/lib/arm7/arm7.bin

TEXT1 		:= The RosaryDS v1.3
TEXT2 		:= by JSDS
TEXT3 		:= therosaryds.googlecode.com

ICON 		:= -b $(CURDIR)/../data/logo.bmp
LOGO		:= -o $(CURDIR)/../data/logo_wifi.bmp

#-------------------------------------------------------------------------------
# TARGET is the name of the output file
# BUILD is the directory where object files & intermediate files will be placed
# RELEASE is where the binary files will be placed
# SOURCES is a list of directories containing source code
# DATA is a list of directories containing data files
# INCLUDES is a list of directories containing extra header files
#-------------------------------------------------------------------------------

TARGET		:=	$(shell basename $(CURDIR))
BUILD		:=	build
RELEASE     :=  Release
SOURCES		:=	gfx source data
DATA		:=	data
INCLUDES	:=	include build data

#-------------------------------------------------------------------------------
# options for code generation
#-------------------------------------------------------------------------------

ARCH	:=	-mthumb-interwork

# note: arm9tdmi isn't the correct CPU arch, but anything newer and LD
# *insists* it has a FPU or VFP, and it won't take no for an answer!

CFLAGS	:=	-g -Wall -O2\
 		-mcpu=arm9tdmi -mtune=arm9tdmi -fomit-frame-pointer\
		-ffast-math \
		$(ARCH)

CFLAGS	+=	$(INCLUDE) -DARM9 -I$(DEVKITPRO)/PAlib/include/nds

ASFLAGS	:=	-g $(ARCH)
LDFLAGS	:=	-g $(ARCH) -mno-fpu -L$(DEVKITPRO)/PAlib/lib

#-------------------------------------------------------------------------------
# the prefix on the compiler executables
#-------------------------------------------------------------------------------

PREFIX			:=	arm-eabi-

#-------------------------------------------------------------------------------
# any extra libraries we wish to link with the project
#-------------------------------------------------------------------------------

LIBS	:= -lfat -lnds9 -ldswifi9
LIBSPA	:= -lpa9
LIBN3D 	:= $(DEVKITPRO)/libn3d
OGRETOOLS := $(OGRE_HOME)/OgreCommandLineTools
 
#-------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level 
# containing include and lib
#-------------------------------------------------------------------------------

LIBDIRS	:=	$(DEVKITPRO)/libnds $(LIBN3D)
LIBDIRPA	:=	$(PAPATH)

#-------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add 
# additional rules for different file extensions
#-------------------------------------------------------------------------------

ifneq ($(BUILD),$(notdir $(CURDIR)))
 
export OUTPUT	:=	$(CURDIR)/$(RELEASE)/$(TARGET)
export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir))\
						$(foreach dir,$(DATA),$(CURDIR)/$(dir))
export CC		:=	$(PREFIX)gcc
export CXX		:=	$(PREFIX)g++
export AR		:=	$(PREFIX)ar
export OBJCOPY	:=	$(PREFIX)objcopy

#-------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#-------------------------------------------------------------------------------

export LD		:=	$(CXX)
 
CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
PCXFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.pcx)))
BINFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.bin)))
PALFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.pal)))
RAWFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.raw)))
MAPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.map)))
JPEGFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.jpg)))
MODFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.mod)))
GIFFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.gif)))
BMPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.bmp)))
MESHFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.mesh)))
 
export OFILES	:=	$(MAPFILES:.map=.o) $(RAWFILES:.raw=.o) $(PALFILES:.pal=.o)\
					$(BINFILES:.bin=.o) $(PCXFILES:.pcx=.o) $(JPEGFILES:.jpg=.o)\
					$(MODFILES:.mod=.o) $(GIFFILES:.gif=.o) $(BMPFILES:.bmp=.o)\
					$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
 
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include/nds) \
					-I$(PAPATH)/include/nds\
					-I$(CURDIR)/$(BUILD)
 
export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)
export LIBPATHPA	:=	$(foreach dir,$(LIBDIRPA),-L$(dir)/lib)
 
.PHONY: $(BUILD) clean rebuild
 
#-------------------------------------------------------------------------------

$(BUILD):
	@[ -d $(CURDIR)/$(RELEASE) ] || mkdir -p $(CURDIR)/$(RELEASE)
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile
 
#-------------------------------------------------------------------------------

clean:

	@echo Cleaning... $(TARGET)
	@rm -fr $(BUILD) *.elf *.*ds* $(RELEASE)/*.*ds*
 
rebuild: clean $(BUILD)

content:
	$(OGRETOOLS)/OgreXmlConverter.exe -OutputFolder data/ $(CURDIR)/$(DATA)
	#$(LIBN3D)/utilities/bin/ogre2n3d.exe -OutputFolder data/ $(LIBN3D)/samples/media/cube.mesh.xml
	#$(LIBN3D)/utilities/bin/ogre2n3d.exe -OutputFolder data/ $(LIBN3D)/samples/media/knot.mesh.xml
	#$(LIBN3D)/utilities/bin/tex2n3d.exe -OutputFolder data/ $(LIBN3D)/samples/media/texture.psd
#-------------------------------------------------------------------------------

else
 
DEPENDS	:= $(OFILES:.o=.d)
 
#-------------------------------------------------------------------------------
# main targets
#-------------------------------------------------------------------------------
$(OUTPUT).ds.gba	: 	$(OUTPUT).nds
$(OUTPUT).nds		: 	$(OUTPUT).bin
$(OUTPUT).bin		:	$(OUTPUT).elf
$(OUTPUT).elf		:	$(OFILES)
 
#-------------------------------------------------------------------------------

%.ds.gba: %.nds
	@dsbuild $< 
	@echo Built: $(notdir $(OUTPUT)).nds
	@echo Built: $(notdir $@)
	@cp $(CURDIR)/../$(RELEASE)/$(notdir $@) ../$(RELEASE)/$(notdir $(OUTPUT)).sc.nds 
	@echo Built: $(notdir $(OUTPUT)).sc.nds

#-------------------------------------------------------------------------------
%.nds: %.bin
	
	@ndstool -c $@ -9 $(TARGET).bin $(ARM7BIN) $(LOGO) $(ICON) "$(TEXT1);$(TEXT2);$(TEXT3)"

#-------------------------------------------------------------------------------
%.bin: %.elf
	
	@$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
 
#-------------------------------------------------------------------------------
%.elf:
	@echo Linking...
	@$(LD)  $(LDFLAGS) -specs=ds_arm9.specs $(OFILES) $(LIBPATHPA) $(LIBSPA) $(LIBPATHS) $(LIBS) -o $(TARGET).elf
 
 
 
#-------------------------------------------------------------------------------
# Compile Targets for C/C++
#-------------------------------------------------------------------------------
 
#-------------------------------------------------------------------------------
%.o : %.cpp
	@echo $(notdir $<)
	@$(CXX) -MM $(CFLAGS) -o $*.d $<
	@$(CXX) $(CFLAGS) -c $< -o$@
 
#-------------------------------------------------------------------------------
%.o : %.c
	@echo $(notdir $<)
	@$(CC) -MM $(CFLAGS) -o $*.d $<
	@$(CC)  $(CFLAGS) -c $< -o$@
 
#-------------------------------------------------------------------------------
%.o : %.s
	@echo $(notdir $<)
	@$(CC) -MM $(CFLAGS) -o $*.d $<
	@$(CC)  $(ASFLAGS) -c $< -o$@
 
define bin2o
	cp $(<) $(*).tmp
	$(OBJCOPY) -I binary -O elf32-littlearm -B arm \
	--rename-section .data=.rodata \
	--redefine-sym _binary_$*_tmp_start=$*\
	--redefine-sym _binary_$*_tmp_end=$*_end\
	--redefine-sym _binary_$*_tmp_size=$*_size\
	$(*).tmp $(@)
	echo "extern const u8" $(*)"[];" > $(*).h
	echo "extern const u32" $(*)_size[]";" >> $(*).h
	rm $(*).tmp
endef
 
#-------------------------------------------------------------------------------
%.o	:	%.pcx
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)
 
#-------------------------------------------------------------------------------
%.o	:	%.bin
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)
 
#-------------------------------------------------------------------------------
%.o	:	%.raw
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)
 
#-------------------------------------------------------------------------------
%.o	:	%.pal
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)
 
#-------------------------------------------------------------------------------
%.o	:	%.map
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#-------------------------------------------------------------------------------
%.o	:	%.mdl
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#-------------------------------------------------------------------------------
%.o	:	%.jpg
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#-------------------------------------------------------------------------------
%.o	:	%.mod
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#-------------------------------------------------------------------------------
%.o	:	%.gif
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#-------------------------------------------------------------------------------
%.o	:	%.bmp
#-------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

 
-include $(DEPENDS) 
#-------------------------------------------------------------------------------
endif
#-------------------------------------------------------------------------------
