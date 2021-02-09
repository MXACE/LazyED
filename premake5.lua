workspace "LazyED"
	configurations { "Debug", "Release" }
	
	project "LazyED"
		kind "ConsoleApp"
		language "C++"
		
		includedirs {
			"bin/moc",
			"src",
			"C:/Qt/Qt5.12.10/5.12.10/msvc2017_64/include/QtCore", 
			"C:/Qt/Qt5.12.10/5.12.10/msvc2017_64/include/QtGui", 
			"C:/Qt/Qt5.12.10/5.12.10/msvc2017_64/include/QtWidgets", 
			"C:/Qt/Qt5.12.10/5.12.10/msvc2017_64/include"
		}
		
		libdirs {
			"C:/Qt/Qt5.12.10/5.12.10/msvc2017_64/lib"
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