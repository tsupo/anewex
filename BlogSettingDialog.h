/*
 * BlogSettingDialog.h
 *      blog情報設定ダイアログ ヘッダー ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/BlogSettingDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 3     06/10/20 2:07 Tsujimura543
 * 「フィードURL」欄を追加
 * 
 * 2     04/07/07 12:04 Tsujimura543
 */

#if !defined(AFX_BLOGSETTINGDIALOG_H__33D77E4A_63FD_45B6_8013_94A6DC2DA547__INCLUDED_)
#define AFX_BLOGSETTINGDIALOG_H__33D77E4A_63FD_45B6_8013_94A6DC2DA547__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBlogSettingDialog ダイアログ

class CBlogSettingDialog : public CDialog
{
// コンストラクション
public:
	CBlogSettingDialog(CWnd* pParent = NULL);   // 標準のコンストラクタ
    bool        disableListingButton;   // ダイアログの動作モード #1
                                        // (「一覧」釦を enable にするか否か)
    bool        editMode;               // ダイアログの動作モード #2
    bool        changed;            // 設定に変更があるか否か
    BLOGLIST    *m_blogListing;     // ping を送信したい blog のリスト
    int         m_numberOfBlog;     // ping を送信したい blog の数

// ダイアログ データ
	//{{AFX_DATA(CBlogSettingDialog)
	enum { IDD = IDD_DIALOG_BLOGSETING };
	CEdit	m_feedUrlEdit;
	CButton	m_listing;
	CEdit	m_blogUrlEdit;
	CEdit	m_blogNameEdit;
	CString	m_blogName;
	CString	m_blogURL;
	CString	m_feedURL;
	//}}AFX_DATA

// オーバーライド
	//{{AFX_VIRTUAL(CBlogSettingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CBlogSettingDialog)
	afx_msg void OnButtonBloglist();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnKillfocusEditBlogname();
	afx_msg void OnKillfocusEditBlogurl();
	afx_msg void OnKillfocusEditFeedurl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_BLOGSETTINGDIALOG_H__33D77E4A_63FD_45B6_8013_94A6DC2DA547__INCLUDED_)
