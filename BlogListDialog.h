/*
 * BlogListDialog.h
 *      blog一覧表示ダイアログ ヘッダー ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/BlogListDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 3     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */
#if !defined(AFX_BLOGLISTDIALOG_H__47206742_967D_42C1_AA8D_AB0D5CD4D7A8__INCLUDED_)
#define AFX_BLOGLISTDIALOG_H__47206742_967D_42C1_AA8D_AB0D5CD4D7A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "anewexStruct.h"

/////////////////////////////////////////////////////////////////////////////
// CBlogListDialog ダイアログ

class CBlogListDialog : public CDialog
{
// コンストラクション
public:
	CBlogListDialog(CWnd* pParent = NULL);  // 標準のコンストラクタ
    void    CopyBlogInfo( BLOGLIST *dst, const BLOGLIST *src );
                                            // BLOGLIST 1個分コピー
    void    CopyBlogList( BLOGLIST **dst, int &numOfDstList,
                          const BLOGLIST *src, int numOfList );
                                            // BLOGLIST のコピー
    void    DeleteBlogList( BLOGLIST **dst, int &numOfDstList );
                                            // BLOGLIST の解放

    BLOGLIST    *m_blogListing;     // ping を送信したい blog のリスト
    int         m_numberOfBlog;     // ping を送信したい blog の数
    BLOGLIST    *m_safe_blogListing;// ping を送信したい blog のリスト (退避用)
    int         m_safe_numberOfBlog;// ping を送信したい blog の数     (退避用)
    bool        changed;

// ダイアログ データ
	//{{AFX_DATA(CBlogListDialog)
	enum { IDD = IDD_DIALOG_BLOGLIST };
	CListBox	m_blogList;
	//}}AFX_DATA

// オーバーライド
	//{{AFX_VIRTUAL(CBlogListDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CBlogListDialog)
	afx_msg void OnAppendBlog();
	afx_msg void OnDeleteBlog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkListBlogs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_BLOGLISTDIALOG_H__47206742_967D_42C1_AA8D_AB0D5CD4D7A8__INCLUDED_)
