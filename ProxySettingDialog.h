/*
 * ProxySettingDialog.h
 *      proxyサーバ情報設定ダイアログ ヘッダー ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/ProxySettingDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 3     07/07/23 13:26 Tsujimura543
 * ユーザ名とパスワードの指定が必要なproxyサーバ経由での
 * 通信にも対応した
 * 
 * 2     04/07/07 12:04 Tsujimura543
 */

#if !defined(AFX_PROXYSETTINGDIALOG_H__DA796FB3_CBA3_408E_AD69_16FF7A137FA8__INCLUDED_)
#define AFX_PROXYSETTINGDIALOG_H__DA796FB3_CBA3_408E_AD69_16FF7A137FA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProxySettingDialog ダイアログ

class CProxySettingDialog : public CDialog
{
// コンストラクション
public:
	CProxySettingDialog(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CProxySettingDialog)
	enum { IDD = IDD_DIALOG_PROXYSETTING };
	long	m_proxyPort;
	CString	m_proxyURL;
	CString	m_proxyUsername;
	CString	m_proxyPassword;
	//}}AFX_DATA

// オーバーライド
	//{{AFX_VIRTUAL(CProxySettingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CProxySettingDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_PROXYSETTINGDIALOG_H__DA796FB3_CBA3_408E_AD69_16FF7A137FA8__INCLUDED_)
