project "TestWx"
    kind "WindowedApp"

    files { "**.cpp", "**.cc", "**.c", "**.h" }

    configuration "windows"
        if os.is("windows") then
        debugdir ".."
        end
        includedirs { "../event/include", "../wx/include" }
        libdirs { "../wx/lib/vc_lib" }
        links { "ws2_32", "mswsock", "kernel32", "user32" }
        flags { "Unicode" }
    configuration "vs*"
        includedirs { "../wx/include/msvc" }
    configuration { "vs* or codeblocks" }
        pchsource "Config.cpp"
        pchheader "Config.h"
    configuration { "not vs* or codeblocks" }
        excludes "Config.cpp"
    configuration "not vs*"
        buildoptions { "-std=c++11" }
    configuration { "not windows", "Debug" }
    --      buildoptions { "`wx-config --cxxflags --unicode=yes --debug=yes`" }
    --    linkoptions { "`wx-config --libs all --unicode=yes --debug=yes`" }
    configuration { "not windows", "Release" }
    --    buildoptions { "`wx-config --cxxflags --unicode=yes --debug=no`" }
    --    linkoptions { "`wx-config --libs all --unicode=yes --debug=no`" }
    configuration "not windows"
        links { "dl" }
