/*
 * AboutDlg.cpp
 *      版数(バージョン番号)表示ダイアログ インプリメンテーション ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * $Log: /comm/anewex/AboutDlg.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 3     09/03/23 23:32 Tsujimura543
 * OpenSSL と iconv の版数を表示するようにした
 * 
 * 2     07/11/16 19:30 Tsujimura543
 * リソースから拾ってきたバージョン番号を表示するようにした
 * 
 * 1     07/11/16 19:16 Tsujimura543
 * anewex.cpp から分離独立させた
 */

#include "anewex.h"
#include "AboutDlg.h"
extern "C" {
#include "xmlRPC.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/AboutDlg.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if (WINVER >= 0x0500)
//#define IDC_HAND    MAKEINTRESOURCE(32649)
#ifdef IDC_HAND
#undef IDC_HAND
#endif
#endif /* WINVER >= 0x0500 */
#define IDC_HAND    IDC_HAND2

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg ダイアログ

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT

    m_hCursor = AfxGetApp()->LoadCursor( IDC_HAND );
}

CAboutDlg::~CAboutDlg()
{
    m_cFont.DeleteObject();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_SHOWWINDOW()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_ANEWEX_WEB_URL, OnAnewexWebUrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg メッセージ ハンドラ

void CAboutDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        // Web の URLとメールアドレスを下線付きで表示する
        LOGFONT tLogFont;
        CFont   *cWndFont;

        cWndFont = GetFont(); 
        cWndFont->GetLogFont( &tLogFont );
        tLogFont.lfUnderline = 1;
        m_cFont.CreateFontIndirect( &tLogFont );

        CStatic *s = (CStatic *)GetDlgItem( IDC_ANEWEX_WEB_URL );
        s->SetFont( &m_cFont, TRUE );

        CString str;
        str.LoadString( IDS_ANEWEX_VERSION );
        str = "anewex Version " + str;
        s = (CStatic *)GetDlgItem( IDC_ANEWEX_VERSION );
        s->SetWindowText( str );

        // OpenSSL 版数表示
        char    buf[BUFSIZ];
        size_t  sz = BUFSIZ;

        s = (CStatic *)GetDlgItem( IDC_OPENSSL );
        s->SetWindowText( getOpenSSLversion( buf, sz ) );

        // iconv 版数表示
        s = (CStatic *)GetDlgItem( IDC_ICONV );
        s->SetWindowText( getIconvVersion( buf, sz ) );
    }
}

BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if ( nHitTest == HTCLIENT ) {
        // Web の URLかメールアドレスにマウスポインタが来たら、
        // 指カーソルを表示する
		DWORD   dwPos = GetMessagePos();
		WORD    wX    = LOWORD( dwPos );
		WORD    wY    = HIWORD( dwPos );
		CPoint  poCursor( wX, wY );
		CRect   rcClient;

        CStatic *s = (CStatic *)GetDlgItem( IDC_ANEWEX_WEB_URL );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }
	}

	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CAboutDlg::OnAnewexWebUrl() 
{
	CString cmd;
	cmd.LoadString( IDS_ANEWEX_WEB_URL );
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}
