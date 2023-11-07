﻿//-------------------------------------------------------------------------------------------------
// File : asdxResTexture.h
// Desc : Texture Resource Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <cstdint>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// SUBRESOURCE_OPTION enum
///////////////////////////////////////////////////////////////////////////////////////////////////
enum SUBRESOURCE_OPTION
{
    SUBRESOURCE_OPTION_CUBEMAP = 0x1 << 0,      //!< キューブマップです.
    SUBRESOURCE_OPTION_VOLUME  = 0x1 << 1,      //!< ボリュームテクスチャです.
    SUBRESOURCE_OPTION_SRGB    = 0x1 << 2,      //!< sRGBフォーマットを可能であれば指定します.
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// SubResource structure
///////////////////////////////////////////////////////////////////////////////////////////////////
struct SubResource
{
    uint32_t     Width;          //!< 横幅です.
    uint32_t     Height;         //!< 縦幅です.
    uint32_t     Pitch;          //!< 1行当たりのバイト数です.
    uint32_t     SlicePitch;     //!< 1スライス当たりのバイト数です(つまり，テクセルデータのバイト数).
    uint8_t*     pPixels;        //!< テクセルデータです.

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    SubResource()
    : Width     ( 0 )
    , Height    ( 0 )
    , Pitch     ( 0 )
    , SlicePitch( 0 )
    , pPixels   ( nullptr )
    { /* DO_NOTHING */ }

    //---------------------------------------------------------------------------------------------
    //! @brief      解放処理を行います.
    //---------------------------------------------------------------------------------------------
    void Release()
    {
        if (pPixels != nullptr)
        {
            delete[] pPixels;
            pPixels = nullptr;
        }
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////
// ResTexture structure
///////////////////////////////////////////////////////////////////////////////////////////////////
struct ResTexture
{
    uint32_t             Width;          //!< 画像の横幅です.
    uint32_t             Height;         //!< 画像の縦幅です.
    uint32_t             Depth;          //!< 画像の奥行です.
    uint32_t             Format;         //!< 画像のフォーマットです.
    uint32_t             MipMapCount;    //!< ミップマップ数です.
    uint32_t             SurfaceCount;   //!< サーフェイス数です(1次元配列テクスチャ, 2次元配列テクスチャ, キューブマップの場合のみ1以上の数が入ります).
    uint32_t             Option;         //!< オプションフラグです.
    SubResource*         pResources;     //!< サブリソースです.

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    ResTexture()
    : Width         ( 0 )
    , Height        ( 0 )
    , Depth         ( 0 )
    , Format        ( 0 )
    , MipMapCount   ( 0 )
    , SurfaceCount  ( 0 )
    , Option        ( 0 )
    , pResources    ( nullptr )
    { /* DO_NOTHING */ }

    //---------------------------------------------------------------------------------------------
    //! @brief      解放処理を行います.
    //---------------------------------------------------------------------------------------------
    void Release()
    {
        uint32_t mipCount = ( MipMapCount > 0 ) ? MipMapCount : 1;

        for( uint32_t i=0; i<SurfaceCount * mipCount; ++i )
        { pResources[i].Release(); }

        if (pResources != nullptr)
        {
            delete[] pResources;
            pResources = nullptr;
        }
    }

    //---------------------------------------------------------------------------------------------
    //! @brief      ファイルからテクスチャリソースを生成します.
    //!             読み込み可能なファイルはDDS, BMP, JPG, PNG, TIFF, GIF, HDP, TGA, HDRです.
    //!
    //! @param[in]      filename        ファイル名です.
    //! @retval true    リソース生成に成功.
    //! @retval false   リソース生成に失敗.
    //---------------------------------------------------------------------------------------------
    bool LoadFromFileA( const char* filename );

    //---------------------------------------------------------------------------------------------
    //! @brief      ファイルからテクスチャリソースを生成します.
    //!             読み込み可能なファイルはDDS, BMP, JPG, PNG, TIFF, GIF, HDP, TGA, HDRです.
    //!
    //! @param[in]      filename        ファイル名です.
    //! @retval true    リソース生成に成功.
    //! @retval false   リソース生成に失敗.
    //---------------------------------------------------------------------------------------------
    bool LoadFromFileW( const wchar_t* filename );

    //---------------------------------------------------------------------------------------------
    //! @brief      メモリストリームからテクスチャリソースを生成します.
    //!             メモリストリームの形式は DDS, BMP, JPG, PNG, TIFF, GIF, HDP, である必要があります.
    //!
    //! @param[in]      pBuffer         バッファです.
    //! @param[in]      bufferSize      バッファサイズです.
    //! @retval true    リソース生成に成功.
    //! @retval false   リソース生成に失敗.
    //---------------------------------------------------------------------------------------------
    bool LoadFromMemory( const uint8_t* pBuffer, uint32_t bufferSize );
};


//-------------------------------------------------------------------------------------------------
//! @brief      ダミーテクスチャを生成します.
//!
//! @retval true    リソース生成に成功.
//! @retval false   リソース生成に失敗.
//-------------------------------------------------------------------------------------------------
bool CreateDummyResTexture( asdx::ResTexture& resTexure );


} // namespace asdx