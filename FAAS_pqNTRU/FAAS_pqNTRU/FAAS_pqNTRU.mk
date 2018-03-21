##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FAAS_pqNTRU
ConfigurationName      :=Debug
WorkspacePath          :=/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU
ProjectPath            :=/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ozgur Ozmen
Date                   :=21/03/18
CodeLitePath           :=/home/ozgur/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="FAAS_pqNTRU.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lb2
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_KAT.c$(ObjectSuffix) $(IntermediateDirectory)/src_packing.c$(ObjectSuffix) $(IntermediateDirectory)/src_param.c$(ObjectSuffix) $(IntermediateDirectory)/src_pqNTRUSign.c$(ObjectSuffix) $(IntermediateDirectory)/src_sign.c$(ObjectSuffix) $(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IntermediateDirectory)/src_poly_DSG.c$(ObjectSuffix) $(IntermediateDirectory)/src_poly_misc.c$(ObjectSuffix) $(IntermediateDirectory)/src_poly_NTT.c$(ObjectSuffix) $(IntermediateDirectory)/src_poly_poly.c$(ObjectSuffix) \
	$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(ObjectSuffix) $(IntermediateDirectory)/src_rng_crypto_stream.c$(ObjectSuffix) $(IntermediateDirectory)/src_rng_fastrandombytes.c$(ObjectSuffix) $(IntermediateDirectory)/src_rng_randombytes.c$(ObjectSuffix) $(IntermediateDirectory)/src_rng_shred.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_KAT.c$(ObjectSuffix): src/KAT.c $(IntermediateDirectory)/src_KAT.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/KAT.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_KAT.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_KAT.c$(DependSuffix): src/KAT.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_KAT.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_KAT.c$(DependSuffix) -MM src/KAT.c

$(IntermediateDirectory)/src_KAT.c$(PreprocessSuffix): src/KAT.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_KAT.c$(PreprocessSuffix) src/KAT.c

$(IntermediateDirectory)/src_packing.c$(ObjectSuffix): src/packing.c $(IntermediateDirectory)/src_packing.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/packing.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_packing.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_packing.c$(DependSuffix): src/packing.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_packing.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_packing.c$(DependSuffix) -MM src/packing.c

$(IntermediateDirectory)/src_packing.c$(PreprocessSuffix): src/packing.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_packing.c$(PreprocessSuffix) src/packing.c

$(IntermediateDirectory)/src_param.c$(ObjectSuffix): src/param.c $(IntermediateDirectory)/src_param.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/param.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_param.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_param.c$(DependSuffix): src/param.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_param.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_param.c$(DependSuffix) -MM src/param.c

$(IntermediateDirectory)/src_param.c$(PreprocessSuffix): src/param.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_param.c$(PreprocessSuffix) src/param.c

$(IntermediateDirectory)/src_pqNTRUSign.c$(ObjectSuffix): src/pqNTRUSign.c $(IntermediateDirectory)/src_pqNTRUSign.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/pqNTRUSign.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_pqNTRUSign.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_pqNTRUSign.c$(DependSuffix): src/pqNTRUSign.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_pqNTRUSign.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_pqNTRUSign.c$(DependSuffix) -MM src/pqNTRUSign.c

$(IntermediateDirectory)/src_pqNTRUSign.c$(PreprocessSuffix): src/pqNTRUSign.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_pqNTRUSign.c$(PreprocessSuffix) src/pqNTRUSign.c

$(IntermediateDirectory)/src_sign.c$(ObjectSuffix): src/sign.c $(IntermediateDirectory)/src_sign.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/sign.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_sign.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_sign.c$(DependSuffix): src/sign.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_sign.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_sign.c$(DependSuffix) -MM src/sign.c

$(IntermediateDirectory)/src_sign.c$(PreprocessSuffix): src/sign.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_sign.c$(PreprocessSuffix) src/sign.c

$(IntermediateDirectory)/src_test.c$(ObjectSuffix): src/test.c $(IntermediateDirectory)/src_test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_test.c$(DependSuffix): src/test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_test.c$(DependSuffix) -MM src/test.c

$(IntermediateDirectory)/src_test.c$(PreprocessSuffix): src/test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_test.c$(PreprocessSuffix) src/test.c

$(IntermediateDirectory)/src_poly_DSG.c$(ObjectSuffix): src/poly/DSG.c $(IntermediateDirectory)/src_poly_DSG.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/poly/DSG.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_poly_DSG.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_poly_DSG.c$(DependSuffix): src/poly/DSG.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_poly_DSG.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_poly_DSG.c$(DependSuffix) -MM src/poly/DSG.c

$(IntermediateDirectory)/src_poly_DSG.c$(PreprocessSuffix): src/poly/DSG.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_poly_DSG.c$(PreprocessSuffix) src/poly/DSG.c

$(IntermediateDirectory)/src_poly_misc.c$(ObjectSuffix): src/poly/misc.c $(IntermediateDirectory)/src_poly_misc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/poly/misc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_poly_misc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_poly_misc.c$(DependSuffix): src/poly/misc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_poly_misc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_poly_misc.c$(DependSuffix) -MM src/poly/misc.c

$(IntermediateDirectory)/src_poly_misc.c$(PreprocessSuffix): src/poly/misc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_poly_misc.c$(PreprocessSuffix) src/poly/misc.c

$(IntermediateDirectory)/src_poly_NTT.c$(ObjectSuffix): src/poly/NTT.c $(IntermediateDirectory)/src_poly_NTT.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/poly/NTT.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_poly_NTT.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_poly_NTT.c$(DependSuffix): src/poly/NTT.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_poly_NTT.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_poly_NTT.c$(DependSuffix) -MM src/poly/NTT.c

$(IntermediateDirectory)/src_poly_NTT.c$(PreprocessSuffix): src/poly/NTT.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_poly_NTT.c$(PreprocessSuffix) src/poly/NTT.c

$(IntermediateDirectory)/src_poly_poly.c$(ObjectSuffix): src/poly/poly.c $(IntermediateDirectory)/src_poly_poly.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/poly/poly.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_poly_poly.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_poly_poly.c$(DependSuffix): src/poly/poly.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_poly_poly.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_poly_poly.c$(DependSuffix) -MM src/poly/poly.c

$(IntermediateDirectory)/src_poly_poly.c$(PreprocessSuffix): src/poly/poly.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_poly_poly.c$(PreprocessSuffix) src/poly/poly.c

$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(ObjectSuffix): src/rng/crypto_hash_sha512.c $(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/rng/crypto_hash_sha512.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(DependSuffix): src/rng/crypto_hash_sha512.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(DependSuffix) -MM src/rng/crypto_hash_sha512.c

$(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(PreprocessSuffix): src/rng/crypto_hash_sha512.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_rng_crypto_hash_sha512.c$(PreprocessSuffix) src/rng/crypto_hash_sha512.c

$(IntermediateDirectory)/src_rng_crypto_stream.c$(ObjectSuffix): src/rng/crypto_stream.c $(IntermediateDirectory)/src_rng_crypto_stream.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/rng/crypto_stream.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_rng_crypto_stream.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_rng_crypto_stream.c$(DependSuffix): src/rng/crypto_stream.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_rng_crypto_stream.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_rng_crypto_stream.c$(DependSuffix) -MM src/rng/crypto_stream.c

$(IntermediateDirectory)/src_rng_crypto_stream.c$(PreprocessSuffix): src/rng/crypto_stream.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_rng_crypto_stream.c$(PreprocessSuffix) src/rng/crypto_stream.c

$(IntermediateDirectory)/src_rng_fastrandombytes.c$(ObjectSuffix): src/rng/fastrandombytes.c $(IntermediateDirectory)/src_rng_fastrandombytes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/rng/fastrandombytes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_rng_fastrandombytes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_rng_fastrandombytes.c$(DependSuffix): src/rng/fastrandombytes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_rng_fastrandombytes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_rng_fastrandombytes.c$(DependSuffix) -MM src/rng/fastrandombytes.c

$(IntermediateDirectory)/src_rng_fastrandombytes.c$(PreprocessSuffix): src/rng/fastrandombytes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_rng_fastrandombytes.c$(PreprocessSuffix) src/rng/fastrandombytes.c

$(IntermediateDirectory)/src_rng_randombytes.c$(ObjectSuffix): src/rng/randombytes.c $(IntermediateDirectory)/src_rng_randombytes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/rng/randombytes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_rng_randombytes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_rng_randombytes.c$(DependSuffix): src/rng/randombytes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_rng_randombytes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_rng_randombytes.c$(DependSuffix) -MM src/rng/randombytes.c

$(IntermediateDirectory)/src_rng_randombytes.c$(PreprocessSuffix): src/rng/randombytes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_rng_randombytes.c$(PreprocessSuffix) src/rng/randombytes.c

$(IntermediateDirectory)/src_rng_shred.c$(ObjectSuffix): src/rng/shred.c $(IntermediateDirectory)/src_rng_shred.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ozgur/Dropbox/OSU/2018_ACNS/FAAS_pqNTRU/FAAS_pqNTRU/src/rng/shred.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_rng_shred.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_rng_shred.c$(DependSuffix): src/rng/shred.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_rng_shred.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_rng_shred.c$(DependSuffix) -MM src/rng/shred.c

$(IntermediateDirectory)/src_rng_shred.c$(PreprocessSuffix): src/rng/shred.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_rng_shred.c$(PreprocessSuffix) src/rng/shred.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


