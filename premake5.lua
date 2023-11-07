local project_dir="project"
location(project_dir)

-- ソリューション名.
workspace "AssetStudio3"
    -- 構成名.
    configurations { "Debug", "Develop", "Release" }
    platforms { "x86_64" }

-- プロジェクト名.
project "AssetStudio3"

    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    -- 出力ディレクトリ.
    targetdir "bin/%{cfg.buildcfg}"
    
    defines { 
        "ASDX_AUTO_LINK=1",
        "ASDX_ENABLE_IMGUI=1",
        "ASDX_ENABLE_PENTAB=1",
    }

    -- インクルードディレクトリ.
    includedirs { 
        "$(ProjectDir)../include",
        "$(ProjectDir)../external",
        "$(ProjectDir)../external/asdx/include",
        "$(ProjectDir)../external/imgui",
        "$(ProjectDir)../external/simdjson",
    }
    shaderincludedirs { "$(ProjectDir)../res/shaders" }

    -- 対称ファイル
    files { "**.h", "**.cpp", "**.hlsl", "**.hlsli" }

    -- シェーダモデルとエントリー名設定.
    shadermodel "6.0"
    shaderentry "main"

    -- ヘッダ変数名とヘッダーファイル名設定.
    shadervariablename "%%(Filename)"
    shaderheaderfileoutput "$(ProjectDir)../res/shaders/Compiled/%%(Filename).inc"

    -- シェーダヘッダファイル設定.
    filter { "files:**.hlsli" }
        flags "ExcludeFromBuild"

    -- 頂点シェーダ設定.
    filter { "files:**_VS.hlsl" }
        shadertype "Vertex"

    -- ピクセルシェーダ設定.
    filter { "files:**_PS.hlsl" }
        shadertype "Pixel"

    -- コンピュートシェーダ設定.
    filter { "files:**_CS.hlsl" }
        shadertype "Compute"

    -- 構成設定.
    filter { "configurations:Debug" }
        defines {"DEBUG"}
        shaderdefines {"DEBUG=1"}
        symbols "On"
    filter { "configurations:Develop" }
        defines {"NDEBUG"}
        shaderdefines {"NDEBUG=1"}
        optimize "On"
        symbols "On"
    filter { "configurations:Release" }
        defines {"NDEBUG"}
        shaderdefines {"NDEBUG=1"}
        optimize "On"
