QT_PATH = os.getenv("QT_PATH")

workspace "LazyED"
	configurations { "Debug", "Release" }
	
	project "LazyED"
		kind "ConsoleApp"
		language "C++"
		architecture "x64_86"
		
		includedirs {
			"bin/moc",
			"src",
			QT_PATH .. "/msvc2017_64/include/QtCore", 
			QT_PATH .. "/msvc2017_64/include/QtGui", 
			QT_PATH .. "/msvc2017_64/include/QtWidgets", 
			QT_PATH .. "/msvc2017_64/include"
		}
		
		libdirs {
			QT_PATH .. "/msvc2017_64/lib"
		}
		
		links {
			"Qt5Cored.lib",
			"Qt5Guid.lib",
			"Qt5Widgetsd.lib"
		}
		
		targetdir "bin/target/%{cfg.buildcfg}"
		objdir "bin/int"
		
		files { "**.cpp", "**.c" }
		
		defines { "_CRT_SECURE_NO_WARNINGS" }
		
		filter "configurations:Debug"
			defines { "DEBUG" }
			optimize "Off"
			symbols "On"
		
		filter "configurations:Release"
			defines { "RELEASE" }
			optimize "On"
			symbols "Off"