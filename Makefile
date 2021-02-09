
SRC_DIR=./src
BIN_DIR=./bin/target
INT_DIR=./bin/int
MOC_DIR=./bin/moc


MOC="C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\bin\\moc.exe"
PREMAKE="premake5.exe"
MSBUILD="C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe"

MOC_DEPS=$(foreach file,$(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/**/*.h),$(subst $(SRC_DIR)/,,$(file)))

clean-int:
	rm -rf $(INT_DIR)

clean-moc:
	rm -rf $(MOC_DIR)

clean-bin:
	rm -rf $(BIN_DIR)

clean-proj:
	rm *.sln *.vcxproj

clean: clean-int clean-moc clean-bin clean-proj

$(MOC_DIR)/%.h: $(SRC_DIR)/%.h
	$(MOC) -o $@ $<

prebuild:
	@mkdir -p $(MOC_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(INT_DIR)
	$(foreach file,$(MOC_DEPS),$(shell mkdir -p $(MOC_DIR)/$$(dirname $(file))))
	$(foreach file,$(MOC_DEPS),$(shell $(MOC) -o $(MOC_DIR)/$(file) $(SRC_DIR)/$(file)))
	@$(foreach file,$(MOC_DEPS),powershell -Command "if ( [String]::IsNullOrWhiteSpace((Get-Content $(MOC_DIR)/$(file))) ) { rm $(MOC_DIR)/$(file) }";)

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
	