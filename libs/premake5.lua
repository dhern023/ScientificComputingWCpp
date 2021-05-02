project "Mathematics"
	kind "StaticLib"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"linear_algebra/**.h",
		"linear_algebra/**.cpp",
	}
	
	includedirs
	{
		"linear_algebra",
		"%{IncludeDir.linear_algebra}",
	}

	links
	{
		"linear_algebra",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "MATH_DEBUG"
		runtime "Debug"
		symbols "on"

		links
		{
		}

	filter "configurations:Release"
		defines "MATH_RELEASE"
		runtime "Release"
		optimize "on"

		links
		{
		}

	filter "configurations:Dist"
		defines "MATH_DIST"
		runtime "Release"
		optimize "on"

		links
		{
		}