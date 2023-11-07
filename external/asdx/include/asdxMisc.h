﻿//-----------------------------------------------------------------------------
// File : asdxMisc.h
// Desc : Utility Moudle.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <vector>
#include <list>


#ifdef ASDX_AUTO_LINK
//-----------------------------------------------------------------------------
// Linker
//-----------------------------------------------------------------------------
#pragma comment( lib, "shlwapi.lib" )
#endif//ASDX_AUTO_LINK


namespace asdx {

//-----------------------------------------------------------------------------
//! @brief      指定された数値の倍数に切り上げます.
//!
//! @param [in]     val     数値.
//! @param [in]     base    倍数.
//! @return     val を base の倍数に切り上げた結果を返却します.
//-----------------------------------------------------------------------------
inline
uint32_t RoundUp( uint32_t val, uint32_t base )
{ return ( val + ( base - 1 ) ) & ~( base - 1 ); }

//-----------------------------------------------------------------------------
//! @brief      指定された数値の倍数に切り上げます.
//!
//! @param [in]     val     数値.
//! @param [in]     base    倍数.
//! @return     val を base の倍数に切り上げた結果を返却します.
//-----------------------------------------------------------------------------
inline
uint64_t RoundUp( uint64_t val, uint64_t base )
{ return ( val + ( base - 1 ) ) & ~( base - 1 ); }

//-----------------------------------------------------------------------------
//! @brief      指定された数値の倍数に切り下げます.
//!
//! @param [in]     val     数値.
//! @param [in]     base    倍数.
//! @return     val を base の倍数に切り下げた結果を返却します.
//-----------------------------------------------------------------------------
inline
uint32_t RoundDown( uint32_t val, uint32_t base )
{ return  val & ~( base - 1 ); }

//-----------------------------------------------------------------------------
//! @brief      指定された数値の倍数に切り下げます.
//!
//! @param [in]     val     数値.
//! @param [in]     base    倍数.
//! @return     val を base の倍数に切り下げた結果を返却します.
//-----------------------------------------------------------------------------
inline
uint64_t RoundDown( uint64_t val, uint64_t base )
{ return  val & ~( base - 1 ); }

//-----------------------------------------------------------------------------
//! @brief      ファイルパスを検索します.
//!
//! @param[in]      filePath        検索するファイスパス.
//! @param[out]     result          検索結果の格納先.
//! @retval true    ファイルを発見.
//! @retval false   ファイルが見つからなかった.
//! @memo 検索ルールは以下の通り.
//!      .\
//!      ..\
//!      ..\..\
//!      .\res\
//!      %EXE_DIR%\
//!      %EXE_DIR%\..\
//!      %EXE_DIR%\..\..\
//!      %EXE_DIR%\res\
//-----------------------------------------------------------------------------
bool SearchFilePathW( const wchar_t* filePath, std::wstring& result );

//-------------------------------------------------------------------------------------------------
//! @brief      ファイルパスを検索します.
//!
//! @param[in]      filePath        検索するファイスパス.
//! @param[out]     result          検索結果の格納先.
//! @retval true    ファイルを発見.
//! @retval false   ファイルが見つからなかった.
//! @memo 検索ルールは以下の通り.
//!      .\
//!      ..\
//!      ..\..\
//!      .\res\
//!      %EXE_DIR%\
//!      %EXE_DIR%\..\
//!      %EXE_DIR%\..\..\
//!      %EXE_DIR%\res\
//-------------------------------------------------------------------------------------------------
bool SearchFilePathA( const char* filePath, std::string& result );

//-------------------------------------------------------------------------------------------------
//! @brief      ディレクトリ名を取得します.
//!
//! @param[in]      filePath        ファイルパス.
//! @return     指定されたファイルパスからディレクトリ名を抜き出します.
//-------------------------------------------------------------------------------------------------
std::wstring GetDirectoryPathW( const wchar_t* fielPath );

//-------------------------------------------------------------------------------------------------
//! @brief      ディレクトリ名を取得します.
//!
//! @param[in]      filePath        ファイルパス.
//! @return     指定されたファイルパスからディレクトリ名を抜き出します.
//-------------------------------------------------------------------------------------------------
std::string GetDirectoryPathA( const char* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      拡張子を取得します.
//!
//! @param[in]      filePath        ファイルパス.
//! @return     指定されたファイルパスから拡張子を抜き出します.
//-------------------------------------------------------------------------------------------------
std::wstring GetExtW( const wchar_t* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      ディレクトリ名を削除します.
//-------------------------------------------------------------------------------------------------
std::string RemoveDirectoryPathA(const char* filePath);

//-------------------------------------------------------------------------------------------------
//! @brief      ディレクトリ名を削除します.
//-------------------------------------------------------------------------------------------------
std::wstring RemoveDirectoryPathW(const wchar_t* filePath);

//-------------------------------------------------------------------------------------------------
//! @brief      拡張子を取得します.
//!
//! @param[in]      filePath        ファイルパス.
//! @return     指定されたファイルパスから拡張子を抜き出します.
//-------------------------------------------------------------------------------------------------
std::string GetExtA( const char* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      拡張子無しのファイルパスを取得します.
//!
//! @param[in]      filePath        ファイルパス.
//! @return     指定されたファイルパスから拡張子を取り除いたファイルパスを返却します.
//-------------------------------------------------------------------------------------------------
std::wstring GetPathWithoutExtW( const wchar_t* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      拡張子無しのファイルパスを取得します.
//!
//! @param[in]      filePath        ファイルパス.
//! @return     指定されたファイルパスから拡張子を取り除いたファイルパスを返却します.
//-------------------------------------------------------------------------------------------------
std::string GetPathWithoutExtA( const char* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      実行ファイルのファイルパスを取得します.
//!
//! @return     実行ファイルのファイルパスを返却します.
//-------------------------------------------------------------------------------------------------
std::wstring GetExePathW();

//-------------------------------------------------------------------------------------------------
//! @brief      実行ファイルのファイルパスを取得します.
//!
//! @return     実行ファイルのファイルパスを返却します.
//-------------------------------------------------------------------------------------------------
std::string GetExePathA();

//-------------------------------------------------------------------------------------------------
//! @brief      指定されたファイルパスが存在するかチェックします.
//!
//! @param[in]      filePath        チェックするファイルパス.
//! @return     指定されたファイルパスが存在する場合はtrueを返却します.
//-------------------------------------------------------------------------------------------------
bool IsExistFilePathW( const wchar_t* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      指定されたファイルパスが存在するかチェックします.
//!
//! @param[in]      filePath        チェックするファイルパス.
//! @return     指定されたファイルパスが存在する場合はtrueを返却します.
//-------------------------------------------------------------------------------------------------
bool IsExistFilePathA( const char* filePath );

//-------------------------------------------------------------------------------------------------
//! @brief      指定されたフォルダパスが存在するかチェックします.
//!
//! @param[in]      folderPath      チェックするフォルダパス.
//! @return     指定されたフォルダパスが存在する場合はtrueを返却します.
//-------------------------------------------------------------------------------------------------
bool IsExistFolderPathW( const wchar_t* folderPath );

//-------------------------------------------------------------------------------------------------
//! @brief      指定されたフォルダパスが存在するかチェックします.
//!
//! @param[in]      folderPath      チェックするフォルダパス.
//! @return     指定されたフォルダパスが存在する場合はtrueを返却します.
//-------------------------------------------------------------------------------------------------
bool IsExistFolderPathA( const char* folderPath );

//-------------------------------------------------------------------------------------------------
//! @brief      ワイド文字列に変換します.
//!
//! @param[in]      value       変換するマルチバイト文字列.
//! @return     指定された文字列をワイド文字列に変換した結果を返却します.
//-------------------------------------------------------------------------------------------------
std::wstring ToStringW( const std::string& value );

//-------------------------------------------------------------------------------------------------
//! @brief      マルチバイト文字列に変換します.
//!
//! @param[in]      value       変換するワイド文字列.
//! @return     指定された文字列をマルチバイト文字列に変換した結果を返却します.
//-------------------------------------------------------------------------------------------------
std::string  ToStringA( const std::wstring& value );

//-------------------------------------------------------------------------------------------------
//! @brief      UTF-8文字列に変換します.
//!
//! @param[in]      value       変換するワイド文字列.
//! @return     指定された文字列をUTF-8に変換した結果を返却します.
//-------------------------------------------------------------------------------------------------
std::string ToStringUTF8(const std::wstring& value);

//-------------------------------------------------------------------------------------------------
//! @brief      UTF-8文字列に変換します.
//!
//! @param[in]      value       変換するASCII文字列.
//! @return     指定された文字列をUTF-8に変換した結果を返却します.
//-------------------------------------------------------------------------------------------------
std::string ToStringUTF8(const std::string& value);

//-------------------------------------------------------------------------------------------------
//! @brief      指定文字で文字列を分割します.
//!
//! @param[in]      value       入力文字列.
//! @param[in]      delimiter   分割文字.
//! @return     指定文字で分割された文字列の配列を返却します.
//-------------------------------------------------------------------------------------------------
std::vector<std::string> Split( const std::string& value, char delimiter );

//-------------------------------------------------------------------------------------------------
//! @brief      指定文字で文字列を分割します.
//!
//! @param[in]      value       入力文字列.
//! @param[in]      delimiter   分割文字.
//! @return     指定文字で分割された文字列の配列を返却します.
//-------------------------------------------------------------------------------------------------
std::vector<std::wstring> Split(  const std::wstring& value, wchar_t delimiter );

//-------------------------------------------------------------------------------------------------
//! @brief      外部プロセスを実行します.
//!
//! @param[in]      cmd         コマンドライン.
//! @param[in]      wait        待機する場合は true.
//! @param[out]     retcode     リターンコード.
//-------------------------------------------------------------------------------------------------
bool RunProcess(const char* cmd, bool wait = true, int* retcode = nullptr);

//-------------------------------------------------------------------------------------------------
//! @brief      ファイルを開くダイアログを出します.
//-------------------------------------------------------------------------------------------------
bool OpenFileDlg(const char* filter, std::string& result, const std::string& defaultPath ="");

//-------------------------------------------------------------------------------------------------
//! @brief      ファイルを保存ダイアログを出します.
//-------------------------------------------------------------------------------------------------
bool SaveFileDlg(const char* filter, std::string& base, std::string& ext, const std::string& defaultPath ="");

//-------------------------------------------------------------------------------------------------
//! @brief      フォルダを開くダイアログを出します.
//-------------------------------------------------------------------------------------------------
bool OpenFolderDlg(std::string& result, const std::string& defaultPath = "");

//-------------------------------------------------------------------------------------------------
//! @brief      情報ダイアログを出します.
//-------------------------------------------------------------------------------------------------
void InfoDlg(const char* title, const char* msg);

//-------------------------------------------------------------------------------------------------
//! @brief      エラーダイアログを出します.
//-------------------------------------------------------------------------------------------------
void ErrorDlg(const char* title, const char* msg);

//-------------------------------------------------------------------------------------------------
//! @brief      DXGIフォーマットから1ピクセルあたりのビット数を求めます.
//-------------------------------------------------------------------------------------------------
int  GetBitsPerPixel(int dxgiFormat);

//-------------------------------------------------------------------------------------------------
//! @brief      DXGIフォーマットから1ピクセルあたりのバイト数を求めます.
//-------------------------------------------------------------------------------------------------
int  GetBytePerPixel(int dxgiFormat);

//-------------------------------------------------------------------------------------------------
//! @brief      SRGBフォーマットに変換できる場合はSRGBフォーマットを返します.
//-------------------------------------------------------------------------------------------------
uint32_t  MakeSRGB(uint32_t dxgiFormat);

//-------------------------------------------------------------------------------------------------
//! @brief      ディレクトリを一括削除します(サブディレクトリのファイル等も消えます)
//-------------------------------------------------------------------------------------------------
bool DeleteDirA(const char* path);

//-------------------------------------------------------------------------------------------------
//! @brief      ディレクトリを一括削除します(サブディレクトリのファイル等も消えます)
//-------------------------------------------------------------------------------------------------
bool DeleteDirW(const wchar_t* path);

//-------------------------------------------------------------------------------------------------
//! @brief      特定ディレクトリの指定された拡張子に対応するファイル一覧を取得します.
//-------------------------------------------------------------------------------------------------
bool SearchFilesA(const char* directory, const char* ext, std::list<std::string>& result);

//-------------------------------------------------------------------------------------------------
//! @brief      フルパスに変換します.
//!
//! @param[in]      path    変換するファイルパス.
//! @return     フルパスを返却します.
//-------------------------------------------------------------------------------------------------
std::string ToFullPath(const char* path);

//-------------------------------------------------------------------------------------------------
//! @brief      相対パスに変換します.
//!
//! @param[in]      base        基準となるパス.
//! @param[in]      path        変換するファイルパス.
//! @param[in]      directory   ファイルパスの場合は false, ディレクトリパスの場合は true を指定.
//! @return     基準となるパスからの相対パスを返却します.
//!             変換に失敗した場合は空文字列が返却されます.
//-------------------------------------------------------------------------------------------------
std::string ToRelativePath(const char* base, const char* path, bool directory = false);

//-----------------------------------------------------------------------------
//! @brief      バックスラッシュからスラッシュに変換します.
//!
//! @param[in]      path        変換するファイルパス.
//-----------------------------------------------------------------------------
std::string ToSlash(const std::string& path);

//-----------------------------------------------------------------------------
//! @brief      文字列を置換します.
//!
//! @param[in]      input       入力文字列.
//! @param[in]      pattern     検索パターン.
//! @param[in]      replace     置換文字列.
//-----------------------------------------------------------------------------
std::string Replace(const std::string& input, std::string pattern, std::string replace);

//-----------------------------------------------------------------------------
//! @brief      ToRelativePath() + ToSlash() + ".\\"の削除 を行います.
//-----------------------------------------------------------------------------
std::string ToRelativePathWithSlash(const std::string& base, const std::string& value);

//-----------------------------------------------------------------------------
//! @breif      小文字に変換します.
//!
//! @param[in]      value       変換する文字列.
//-----------------------------------------------------------------------------
std::string ToLower(const std::string& value);

//-----------------------------------------------------------------------------
//! @brief      環境変数を取得します.
//!
//! @param[in]      name        環境変数名.
//-----------------------------------------------------------------------------
std::string GetEnv(const char* name);


} // namespacec asdx
