/*
 * SendingPingDialog.h
 *      ping送信ダイアログ ヘッダー ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/SendingPingDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 3     05/11/11 18:19 Tsujimura543
 * 「ping 送信中」表示ダイアログの使い方を変えてみた
 * 
 * 2     05/01/07 13:58 Tsujimura543
 * OnTimer() を追加
 */

#if !defined(AFX_SENDINGPINGDIALOG_H__623F8CF8_BCF8_405D_BEF9_4F7F014971B9__INCLUDED_)
#define AFX_SENDINGPINGDIALOG_H__623F8CF8_BCF8_405D_BEF9_4F7F014971B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// SendingPingDialog ダイアログ

class SendingPingDialog : public CDialog
{
// コンストラクション
public:
	SendingPingDialog(CWnd* pParent = NULL);   // 標準のコンストラクタ
    void    ChangeDialogText( const char *title, const char *message );

// ダイアログ データ
	//{{AFX_DATA(SendingPingDialog)
	enum { IDD = IDD_DIALOG_SENDING };
	//}}AFX_DATA

// オーバーライド
	//{{AFX_VIRTUAL(SendingPingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(SendingPingDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SENDINGPINGDIALOG_H__623F8CF8_BCF8_405D_BEF9_4F7F014971B9__INCLUDED_)
