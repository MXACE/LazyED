QT_PATH = os.getenv("QT_PATH")

workspace "LazyED"
	configurations { "Debug", "Release" }
	
	project "LazyED"
		kind "ConsoleApp"
		language "C++"
		system "Windows"
		architecture "x86_64"
		
		includedirs {
			"bin/moc",
			"bin/uic",
			"src",
			QT_PATH .. "/msvc2017_64/include",
			QT_PATH .. "/msvc2017_64/include/QtCore", 
			QT_PATH .. "/msvc2017_64/include/QtGui", 
			QT_PATH .. "/msvc2017_64/include/QtWidgets"
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
		
		files { "src/**.cpp", "src/**.c", "bin/moc/**.cpp" }
		
		defines {
			"_CRT_SECURE_NO_WARNINGS"
		}
		
		filter "configurations:Debug"
			defines { "LED_DEBUG" }
			optimize "Off"
			symbols "On"
		
		filter "configurations:Release"
			defines { "LED_RELEASE" }
			optimize "On"
			symbols "Off"