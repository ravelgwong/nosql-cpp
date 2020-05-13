##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=benchmark
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/ROG FX553V/Documents/nosql-cpp/benchmark"
ProjectPath            :="C:/Users/ROG FX553V/Documents/nosql-cpp/benchmark"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ROG FX553V
Date                   :=13/05/2020
CodeLitePath           :=D:/CodeLite
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="benchmark.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\CodeLite
Objects0=$(IntermediateDirectory)/codes_bTree_bTree.cpp$(ObjectSuffix) $(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(ObjectSuffix) $(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/codes_bTree_bTree.cpp$(ObjectSuffix): codes/bTree/bTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/codes_bTree_bTree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/codes_bTree_bTree.cpp$(DependSuffix) -MM codes/bTree/bTree.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ROG FX553V/Documents/nosql-cpp/benchmark/codes/bTree/bTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/codes_bTree_bTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/codes_bTree_bTree.cpp$(PreprocessSuffix): codes/bTree/bTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/codes_bTree_bTree.cpp$(PreprocessSuffix) codes/bTree/bTree.cpp

$(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(ObjectSuffix): codes/lsmTree/lsmTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(DependSuffix) -MM codes/lsmTree/lsmTree.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ROG FX553V/Documents/nosql-cpp/benchmark/codes/lsmTree/lsmTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(PreprocessSuffix): codes/lsmTree/lsmTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/codes_lsmTree_lsmTree.cpp$(PreprocessSuffix) codes/lsmTree/lsmTree.cpp

$(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(ObjectSuffix): codes/hashTable/hashTable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(DependSuffix) -MM codes/hashTable/hashTable.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ROG FX553V/Documents/nosql-cpp/benchmark/codes/hashTable/hashTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(PreprocessSuffix): codes/hashTable/hashTable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/codes_hashTable_hashTable.cpp$(PreprocessSuffix) codes/hashTable/hashTable.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


