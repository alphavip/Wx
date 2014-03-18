solution "TestWx"
    location "build"
    language "C++"
    objdir "obj"

    configurations { "Debug", "Release" }

    configuration "windows"
        defines { "WIN32", "_WIN32" }

    configuration "bsd"
        includedirs { "/usr/local/include" }
        libdirs { "/usr/local/lib" }

    configuration "macosx"
        buildoptions { "-stdlib=libc++" }
        linkoptions { "-stdlib=libc++" }

    configuration "vs*"
        flags "EnableSSE2"
        buildoptions { "-wd4996" }
        defines { "_CRT_SECURE_NO_WARNINGS" }

    configuration "not vs*"
        buildoptions { "-Wall", "-fexceptions", "-fno-strict-aliasing", "-Wno-multichar" }
    configuration {"not vs*", "windows"}
        buildoptions { "-static-libgcc", "-static-libstdc++" }

    configuration "Debug"
        flags "Symbols"
        defines "_DEBUG"
        targetdir "bin/debug"

    configuration { "Release", "not vs*", "not macosx" }
        flags "Symbols"
        buildoptions "-march=native"

    configuration "Release"
        flags { "OptimizeSpeed" }
        targetdir "bin/release"

    include "TestWx"
