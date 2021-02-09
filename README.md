# LazyED
LazyED (short: LED). Assisting tool for Elite Dangerous

# Requirements
This Project is built using MSYS2, premake5, MSBuild and Qt 5.  
In MSYS2 the following packages must be installed:  
- make 4.7

Furthermore, and environment variables named QT_PATH and QT_TOOLS pointing to the desired version of Qt must be present.  
Example:  
- QT_PATH="C:/Qt/Qt5.12.10/5.12.10"
- QT_TOOLS="C:/Qt/Qt5.12.10/Tools" (only necessary for the VS Code extension 'Qt')
  
The executables premake5.exe, moc.exe and MSBuild.exe also need to be in the Path environment variable.  
For Qt5 the Visual Studio msvc2017_64