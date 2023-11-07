﻿//-------------------------------------------------------------------------------------------------
// File : asdxSound.h
// Desc : Sound Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <Windows.h>
#include <map>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// SndState
///////////////////////////////////////////////////////////////////////////////////////////////////
enum SndState
{
    Play,       //!< 再生状態.
    Stop,       //!< 停止状態.
    Pause,      //!< 一時停止状態.
    Done,       //!< 再生完了.
    Error,      //!< エラー状態.
};


///////////////////////////////////////////////////////////////////////////////////////////////////
// SndMgr class
///////////////////////////////////////////////////////////////////////////////////////////////////
class SndMgr
{
    //=============================================================================================
    // list of friend classes and methods.
    //=============================================================================================
    friend class Application;

public:
    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      シングルトンインスタンスを取得します.
    //---------------------------------------------------------------------------------------------
    static SndMgr& GetInstance();

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを登録します.
    //---------------------------------------------------------------------------------------------
    bool Open( uint32_t id, const char* filename );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータの登録を解除します.
    //---------------------------------------------------------------------------------------------
    void Close( uint32_t id );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを再生します.
    //---------------------------------------------------------------------------------------------
    void Play( uint32_t id, int loopCount = 0 );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを停止します.
    //---------------------------------------------------------------------------------------------
    void Stop( uint32_t id );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを一時停止します.
    //---------------------------------------------------------------------------------------------
    void Pause( uint32_t id );

    //---------------------------------------------------------------------------------------------
    //! @brief      一時停止したサウンドデータを再生します.
    //---------------------------------------------------------------------------------------------
    void Resume( uint32_t id );

    //---------------------------------------------------------------------------------------------
    //! @brief      状態を取得します.
    //---------------------------------------------------------------------------------------------
    SndState GetState( uint32_t id );

protected:
    //=============================================================================================
    // protected variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // protected methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      コールバック用のウィンドウハンドルを設定します.
    //! @note       Applicationから呼び出します.
    //---------------------------------------------------------------------------------------------
    void SetHandle( HWND handle );

    //---------------------------------------------------------------------------------------------
    //! @brief      コールバック処理です.
    //! @note       Applicationから呼び出します.
    //---------------------------------------------------------------------------------------------
    void OnNofity( uint32_t id, uint32_t param );

private:
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Status structure
    ///////////////////////////////////////////////////////////////////////////////////////////////
    struct Status
    {
        int         MaxLoopCount;   //!< 最大ループ数.
        int         CurLoopCount;   //!< 現在のループ数.
        int         State;          //!< 再生状態.
        uint32_t    DeviceId;       //!< デバイスID.
    };

    //=============================================================================================
    // private variables.
    //=============================================================================================
    static SndMgr                   s_Instance;     //!< 唯一のインスタンスです.
    std::map<uint32_t, Status>      m_Status;       //!< 状態管理用.
    std::map<uint32_t, uint32_t>    m_UserIds;      //!< デバイスID -> ユーザーID参照用.
    HWND                            m_Handle;       //!< ウィンドウハンドル.

    //=============================================================================================
    // private methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    SndMgr();

    //---------------------------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //---------------------------------------------------------------------------------------------
    ~SndMgr();
};

} // namespace asdx
