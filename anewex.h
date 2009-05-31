/*
 * anewex.h 
 *      アプリケーション メイン ヘッダーファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewex.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 3     07/01/05 22:37 Tsujimura543
 * 日本語以外のWindowsで動かそうとした場合は、英語モードで動作
 * するようにした
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */

#if !defined(AFX_ANEWEX_H__DC3492C2_77A2_4B61_B8B2_C31634861EDC__INCLUDED_)
#define AFX_ANEWEX_H__DC3492C2_77A2_4B61_B8B2_C31634861EDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows ヘッダーから殆ど使用されないスタッフを除外します。

#include <afxwin.h>         // MFC のコアおよび標準コンポーネント
#include <afxext.h>         // MFC の拡張部分
#include <afxdisp.h>        // MFC のオートメーション クラス
#include <afxdtctl.h>		// MFC の Internet Explorer 4 コモン コントロール サポート
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC の Windows コモン コントロール サポート
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"		// メイン シンボル
#include "anewexStruct.h"

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp:

class CAnewexApp : public CWinApp
{
public:
	CAnewexApp();

// オーバーライド
	//{{AFX_VIRTUAL(CAnewexApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
    LCID    m_langCode;

	//{{AFX_MSG(CAnewexApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_ANEWEX_H__DC3492C2_77A2_4B61_B8B2_C31634861EDC__INCLUDED_)
