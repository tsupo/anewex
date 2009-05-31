/*
 * InputPingSiteURL.h
 *      pingサイトURL入力ダイアログ ヘッダー ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/InputPingSiteURL.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 5     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 4     06/10/25 20:49 Tsujimura543
 * (1) ping種別を指定できるようにした
 * (2) ping サイトのURLではなく、ping
 * サイト名称を優先的に表示するようにした
 * 
 * 3     06/10/20 2:06 Tsujimura543
 * 「編集」時はダイアログのタイトルを変更するようにした
 * 
 * 2     04/07/07 12:04 Tsujimura543
 */

#if !defined(AFX_INPUTPINGSITEURL_H__8BDC2069_1F72_4034_9479_8A06B5FD5B45__INCLUDED_)
#define AFX_INPUTPINGSITEURL_H__8BDC2069_1F72_4034_9479_8A06B5FD5B45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInputPingSiteURL ダイアログ

class CInputPingSiteURL : public CDialog
{
// コンストラクション
public:
	CInputPingSiteURL(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CInputPingSiteURL)
	enum { IDD = IDD_DIALOG_INPUT_PINGSITE };
	CEdit	m_pingSiteEdit2;
	CEdit	m_pingSiteEdit;
	CString	m_pingSiteURL;
	CString	m_pingSiteName;
	//}}AFX_DATA

    bool    m_mode; // true: 編集、false: 追加
    int     m_pingType; // weblogUpdates.ping / weblogUpdates.extendedPing

// オーバーライド
	//{{AFX_VIRTUAL(CInputPingSiteURL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CInputPingSiteURL)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnRadioPingtypeNormal();
	afx_msg void OnRadioPingtypeExtended();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_INPUTPINGSITEURL_H__8BDC2069_1F72_4034_9479_8A06B5FD5B45__INCLUDED_)
