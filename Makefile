
SRC_DIR=./src
BIN_DIR=./bin/target
INT_DIR=./bin/int
MOC_DIR=./bin/moc
UIC_DIR=./bin/uic


MOC=$(QT_PATH)/msvc2017_64/bin/moc.exe
UIC=$(QT_PATH)/msvc2017_64/bin/uic.exe
PREMAKE=premake5.exe
MSBUILD=MSBuild.exe

HEADERS=$(foreach file,$(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/**/*.h),$(subst $(SRC_DIR)/,,$(file)))
FORMS=$(foreach file,$(wildcard $(SRC_DIR)/*.ui) $(wildcard $(SRC_DIR)/**/*.ui),$(subst $(SRC_DIR)/,,$(file)))

clean-int:
	@rm -rf $(INT_DIR)

clean-moc:
	@rm -rf $(MOC_DIR)

clean-bin:
	@rm -rf $(BIN_DIR)

clean-uic:
	@rm -rf $(UIC_DIR)

clean-proj:
	@rm -f *.sln *.vcxproj *.vcxproj.filters *.vcxproj.user

clean: clean-int clean-moc clean-bin clean-uic clean-proj 

$(MOC_DIR)/%.h: $(SRC_DIR)/%.h
	$(MOC) -o $@ $<

prebuild: clean
	@mkdir -p $(MOC_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(INT_DIR)
	@mkdir -p $(UIC_DIR)
	$(foreach file,$(HEADERS),$(shell mkdir -p $(MOC_DIR)/$$(dirname $(file))))
	$(foreach file,$(FORMS),$(shell mkdir -p $(UIC_DIR)/$$(dirname $(file))))
	$(foreach file,$(HEADERS),$(shell $(MOC) -o $(subst .h,.cpp,$(MOC_DIR)/$$(dirname $(file))/moc_$$(basename $(file))) $(SRC_DIR)/$(file)))
	$(foreach file,$(FORMS),$(shell $(UIC) -o $(subst .ui,.h,$(UIC_DIR)/$$(dirname $(file))/ui_$$(basename $(file))) $(SRC_DIR)/$(file)))

build-project: prebuild
	$(PREMAKE) vs2019
	$(MSBUILD) LazyED.vcxproj /property:Configuration=Debug

build: prebuild
	$(PREMAKE) vs2019
	$(MSBUILD) LazyED.sln /property:Configuration=Debug

build-project-release: prebuild
	$(PREMAKE) vs2019
	$(MSBUILD) LazyED.vcxproj /property:Configuration=Release
	
build-release: prebuild
	$(PREMAKE) vs2019
	$(MSBUILD) LazyED.sln /property:Configuration=Release

run:
	$(BIN_DIR)/Debug/LazyED.exe
	
run-release:
	$(BIN_DIR)/Release/LazyED.exe

debug:
	gdb $(BIN_DIR)/Debug/LazyED.exe
	