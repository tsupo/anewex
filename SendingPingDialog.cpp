/*
 * SendingPingDialog.cpp
 *      ping送信ダイアログ インプリメンテーション ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/SendingPingDialog.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 4     07/07/23 14:35 Tsujimura543
 * コードを整理
 * 
 * 3     05/11/11 18:19 Tsujimura543
 * 「ping 送信中」表示ダイアログの使い方を変えてみた
 * 
 * 2     05/01/07 13:58 Tsujimura543
 * OnTimer() を追加
 */

#include "anewex.h"
#include "SendingPingDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/SendingPingDialog.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SendingPingDialog ダイアログ

SendingPingDialog::SendingPingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SendingPingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(SendingPingDialog)
	//}}AFX_DATA_INIT
}

void SendingPingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SendingPingDialog)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(SendingPingDialog, CDialog)
	//{{AFX_MSG_MAP(SendingPingDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ProceedingDialog 追加メソッド

void    SendingPingDialog::ChangeDialogText(
                const char *title,
                const char *message
            )
{
    SetWindowText( title );

    CStatic *sp = (CStatic *)GetDlgItem( IDC_STATIC_PROCEEDING );
    sp->SetWindowText( message );
}
