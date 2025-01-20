include "Premake5/scripts/helpers.lua"
include "dependencies.lua"

include "sogeqte-dependencies.lua"

group "Dependencies"
    include "SOGEQtE/3rdparty/ADS/premake5.lua"
group ""

project "SOGEQtE"
    location "SOGEQtE"
    kind "ConsoleApp"
    buildoptions {"/Zc:__cplusplus", "/permissive-"}
    staticruntime "on"
    language "C++"
    cppdialect "C++20"

    targetdir("%{wks.location}/%{prj.name}/")
    objdir("build/int/" .. buildpattern .. "/%{prj.name}")

    files
    {
        "%{wks.location}/%{prj.name}/include/**.hpp",
        "%{wks.location}/%{prj.name}/source/**.cpp"
    }

    includedirs
    {
        -- Application

        "%{wks.location}/%{prj.name}/include",
        "%{wks.location}/%{prj.name}/%{SOGEQtEThirdpartyDirs.ADS}",

        -- Engine

        "%{wks.location}/SOGE/include",
        "%{wks.location}/%{IncludeThirdpartyDirs.spdlog}",
        "%{wks.location}/%{IncludeThirdpartyDirs.backwardcpp}",
        "%{wks.location}/%{IncludeThirdpartyDirs.EASTL}",
        "%{wks.location}/%{IncludeThirdpartyDirs.EABase}",
        "%{wks.location}/%{IncludeThirdpartyDirs.UUID_v4}",
        "%{wks.location}/%{IncludeThirdpartyDirs.eventpp}",
        "%{wks.location}/%{IncludeThirdpartyDirs.kangaru}",
        "%{wks.location}/%{IncludeThirdpartyDirs.eventpp}",
        "%{wks.location}/%{IncludeThirdpartyDirs.SDL3}",
        "%{wks.location}/%{IncludeThirdpartyDirs.cppfs}",
        "%{wks.location}/%{IncludeThirdpartyDirs.FMOD}",
        "%{wks.location}/%{IncludeThirdpartyDirs.glm}",
        "%{wks.location}/%{IncludeThirdpartyDirs.XoshiroCpp}",
        "%{wks.location}/%{IncludeThirdpartyDirs.SDL3}",
        "%{wks.location}/%{IncludeThirdpartyDirs.NRI}",
        "%{wks.location}/%{IncludeThirdpartyDirs.NVRHI}",
        "%{wks.location}/%{IncludeThirdpartyDirs.MONO}"
    }

    defines
    {
        "GLM_ENABLE_EXPERIMENTAL"
    }

    qt.enable()
    qtuseexternalinclude(true)
    qtpath(qt_path)
    qtprefix("Qt6")
    qtmodules { "core", "gui", "widgets", "qml", "network"}

    links
    {
        "SOGE",
        "ADS"
    }

    filter "system:windows"
        systemversion "latest"
        kind 'WindowedApp'
        entrypoint "wWinMainCRTStartup"

        defines
        {
            "SOGE_WINDOWS"
        }

    filter "configurations:Debug"
        symbols "on"
        qtsuffix "d"

        defines
        {
            "SOGE_DEBUG",
            "SOGEQTE_DEBUG"
        }

        postbuildcommands
        {
            setQtDeployOnPostbuild("%{wks.location}/%{prj.name}/%{prj.name}.exe", true)
        }

    filter "configurations:Release"
        optimize "on"

        defines
        {
            "SOGE_RELEASE",
            "SOGEQTE_RELEASE"
        }

        postbuildcommands
        {
            setQtDeployOnPostbuild("%{wks.location}/%{prj.name}/%{prj.name}.exe", false)
        }

    filter "system:windows"
        systemversion "latest"

        defines
        {
        }