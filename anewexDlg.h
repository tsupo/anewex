/*
 * anewexDlg.h
 *      メインダイアログ ヘッダー ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewexDlg.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 6     07/07/23 14:17 Tsujimura543
 * コードを整理
 * 
 * 5     07/07/23 13:26 Tsujimura543
 * ユーザ名とパスワードの指定が必要なproxyサーバ経由での
 * 通信にも対応した
 * 
 * 4     07/01/05 22:37 Tsujimura543
 * 日本語以外のWindowsで動かそうとした場合は、英語モードで動作
 * するようにした
 * 
 * 3     06/10/20 2:08 Tsujimura543
 * (1) 「Google ブログ検索」に対応した
 * (2) pingサーバの登録数上限を5個増やした
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */

#if !defined(AFX_ANEWEXDLG_H__397426FA_F366_43A4_913D_3C6E8C8EA9A1__INCLUDED_)
#define AFX_ANEWEXDLG_H__397426FA_F366_43A4_913D_3C6E8C8EA9A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern "C" {
#include "xmlRPC.h"
}
#include "anewexStruct.h"

/////////////////////////////////////////////////////////////////////////////
// CAnewexDlg ダイアログ

class CAnewexDlg : public CDialog
{
// 構築
public:
	CAnewexDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ
    ~CAnewexDlg();                      // デストラクタ
    void    Init();                     // 初期設定
    void    ReadSetting();              // 初期設定ファイル読取り
    void    WriteSetting();             // 初期設定ファイル書出し
    void    SetCheck( int ctrlID, int pingSiteID );
                                        // ラジオボタン ON/OFF 設定
    void    ToggleTarget( CButton *cp, int pingSiteID );
                                        // ラジオボタン ON/OFF 切替
    void    InitPingSiteList( BLOGLIST *p, bool initialSetting = false );
                                        // ping 送信先サイトリスト初期化
    void    EditPingSite( int pingSiteID );
                                        // ping サイトURL編集
    void    GetProxyInfo( char *url,
                          int  &port,
                          char *username,
                          char *password ); // proxy 情報取得
    void    WriteProxyTxt();                // proxy 情報書出し
    void    DeleteProxyTxt();               // proxy 情報削除

    BLOGLIST        *m_blogListing;     // ping を送信したい blog のリスト
    BLOGLIST        *m_targetBlog;      // 現在選択されている blog
    PINGSITELIST    *m_pingSiteListing; // ping 送信先サイトのリスト
    int             m_numberOfBlog;     // ping を送信したい blog の数
    int             m_numberOfPingSite; // ping 送信先サイトの数
    int             m_proxyPort;                    // proxy ポート番号
    char            m_proxyURL[MAX_PATH];           // proxy URL
    char            m_proxyUsername[MAX_USERIDLEN]; // proxy ユーザ名
    char            m_proxyPassword[MAX_USERIDLEN]; // proxy パスワード

// ダイアログ データ
	//{{AFX_DATA(CAnewexDlg)
	enum { IDD = IDD_ANEWEX_DIALOG };
	CComboBox	m_blogList;
	CString	m_blogName;
	BOOL	m_useProxy;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAnewexDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;
    bool  m_changed;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAnewexDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetting();
	afx_msg void OnVersion();
	afx_msg void OnAddPingsite();
	afx_msg void OnRadioWeblogscom();
	afx_msg void OnRadioBloggersjp();
	afx_msg void OnRadioBlogpeople();
	afx_msg void OnRadioMyblog();
	afx_msg void OnRadioBulkfeeds();
	afx_msg void OnRadioGoo();
	afx_msg void OnRadioPingsite001();
	afx_msg void OnRadioPingsite002();
	afx_msg void OnRadioPingsite003();
	afx_msg void OnRadioPingsite004();
	afx_msg void OnRadioPingsite005();
	afx_msg void OnRadioPingsite006();
	afx_msg void OnRadioPingsite007();
	afx_msg void OnRadioPingsite008();
	afx_msg void OnRadioPingsite009();
	afx_msg void OnRadioPingsite010();
	afx_msg void OnRadioPingsite011();
	afx_msg void OnRadioPingsite012();
	afx_msg void OnRadioPingsite013();
	afx_msg void OnRadioPingsite014();
	afx_msg void OnPing();
	afx_msg void OnSelchangeCombo();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	afx_msg void OnDoubleclickedRadioPingsite001();
	afx_msg void OnDoubleclickedRadioPingsite002();
	afx_msg void OnDoubleclickedRadioPingsite003();
	afx_msg void OnDoubleclickedRadioPingsite004();
	afx_msg void OnDoubleclickedRadioPingsite005();
	afx_msg void OnDoubleclickedRadioPingsite006();
	afx_msg void OnDoubleclickedRadioPingsite007();
	afx_msg void OnDoubleclickedRadioPingsite008();
	afx_msg void OnDoubleclickedRadioPingsite009();
	afx_msg void OnDoubleclickedRadioPingsite010();
	afx_msg void OnDoubleclickedRadioPingsite011();
	afx_msg void OnDoubleclickedRadioPingsite012();
	afx_msg void OnDoubleclickedRadioPingsite013();
	afx_msg void OnDoubleclickedRadioPingsite014();
	afx_msg void OnCheckproxy();
	afx_msg void OnButtonproxy();
	afx_msg void OnRadioGoogle();
	afx_msg void OnRadioTechnorati();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_ANEWEXDLG_H__397426FA_F366_43A4_913D_3C6E8C8EA9A1__INCLUDED_)
