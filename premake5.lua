include "Dependencies.lua"

workspace "ScientificComputing"
	architecture "x86_64"
	startproject "Mathematics"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "libs/"
group ""

include "Libs"