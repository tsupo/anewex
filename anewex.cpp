/*
 * anewex.cpp
 *      アプリケーション メイン
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewex.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 4     07/07/23 14:20 Tsujimura543
 * コードを整理
 * 
 * 3     07/01/05 22:37 Tsujimura543
 * 日本語以外のWindowsで動かそうとした場合は、英語モードで動作
 * するようにした
 * 
 * 2     04/07/07 12:10 Tsujimura543
 */

#include "anewex.h"
#include "anewexDlg.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/anewex.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp

BEGIN_MESSAGE_MAP(CAnewexApp, CWinApp)
	//{{AFX_MSG_MAP(CAnewexApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp クラスの構築

CAnewexApp::CAnewexApp()
{
    m_langCode = GetThreadLocale();
    if ( m_langCode != 0x0411 )
        m_langCode = 0x0409;  // 「日本語」以外の場合は強制的に「英語」にする
    SetThreadLocale( m_langCode );
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CAnewexApp オブジェクト

CAnewexApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp クラスの初期化

BOOL CAnewexApp::InitInstance()
{
	AfxEnableControlContainer();

	CAnewexDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}
