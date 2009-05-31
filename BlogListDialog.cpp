/*
 * BlogListDialog.cpp
 *      blog一覧表示ダイアログ インプリメンテーション ファイル
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/BlogListDialog.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 7     07/07/23 14:37 Tsujimura543
 * 余分な空行を削除
 * 
 * 6     07/07/23 14:28 Tsujimura543
 * コードを整理
 * 
 * 5     07/07/03 10:33 Tsujimura543
 * Visual Studio 2005 でのビルド結果を反映
 * 
 * 4     06/10/25 20:49 Tsujimura543
 * (1) ping種別を指定できるようにした
 * (2) ping サイトのURLではなく、ping
 * サイト名称を優先的に表示するようにした
 * 
 * 3     06/10/20 2:08 Tsujimura543
 * (1) 「Google ブログ検索」に対応した
 * (2) pingサーバの登録数上限を5個増やした
 * 
 * 2     04/07/07 12:09 Tsujimura543
 */

#include "anewex.h"
#include "BlogListDialog.h"
#include "BlogSettingDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/BlogListDialog.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlogListDialog ダイアログ

CBlogListDialog::CBlogListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CBlogListDialog::IDD, pParent)
{
    m_blogListing  = NULL;
    m_numberOfBlog = 0;
    m_safe_blogListing  = NULL;
    m_safe_numberOfBlog = 0;
    changed        = false;

	//{{AFX_DATA_INIT(CBlogListDialog)
	//}}AFX_DATA_INIT
}

void CBlogListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlogListDialog)
	DDX_Control(pDX, IDC_LIST_BLOGS, m_blogList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBlogListDialog, CDialog)
	//{{AFX_MSG_MAP(CBlogListDialog)
	ON_BN_CLICKED(IDC_APPEND_BLOG, OnAppendBlog)
	ON_BN_CLICKED(IDC_DELETE_BLOG, OnDeleteBlog)
	ON_WM_SHOWWINDOW()
	ON_LBN_DBLCLK(IDC_LIST_BLOGS, OnDblclkListBlogs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlogListDialog 各種メソッド

#ifdef  _MSC_VER
#pragma warning ( disable : 4996 )  // for Visual C++ 2005
#endif

// BLOGLIST 1個分コピー
void CBlogListDialog::CopyBlogInfo( BLOGLIST *dst, const BLOGLIST *src )
{
    strcpy( dst->blogName, src->blogName );
    strcpy( dst->blogURL,  src->blogURL );
    if ( (dst->pingSiteList) && (dst->numOfPingSite > 0) ) {
        delete [] dst->pingSiteList;
        dst->pingSiteList  = NULL;
        dst->numOfPingSite = 0;
    }
    int numOfPingSite = src->numOfPingSite;
    if ( numOfPingSite > 0 ) {
        dst->numOfPingSite = numOfPingSite;
        dst->pingSiteList  = new PINGSITELIST[numOfPingSite];

        int j;
        for ( j = 0; j < numOfPingSite; j++ ) {
            dst->pingSiteList[j].ctrlID   = src->pingSiteList[j].ctrlID;
            dst->pingSiteList[j].isTarget = src->pingSiteList[j].isTarget;
            dst->pingSiteList[j].sendTime = src->pingSiteList[j].sendTime;
            dst->pingSiteList[j].pingType = src->pingSiteList[j].pingType;
            strcpy( dst->pingSiteList[j].siteName,
                    src->pingSiteList[j].siteName );
            strcpy( dst->pingSiteList[j].siteURL,
                    src->pingSiteList[j].siteURL );
        }
    }
    else {
        dst->numOfPingSite = 0;
        dst->pingSiteList  = NULL;
    }
}

// BLOGLIST のコピー 
void CBlogListDialog::CopyBlogList(
            BLOGLIST       **dst, int &numOfDstList,
            const BLOGLIST *src,  int numOfSrcList )
{
    numOfDstList = numOfSrcList;
    *dst = new BLOGLIST[numOfSrcList];

    int i;
    for ( i = 0; i < numOfSrcList; i++ )
        CopyBlogInfo( &((*dst)[i]), &src[i] );
}

// BLOGLIST の解放
void CBlogListDialog::DeleteBlogList( BLOGLIST **dst, int &numOfDstList )
{
    int i;
    for ( i = numOfDstList; i > 0; i-- ) {
        if ( (*dst)[i - 1].numOfPingSite > 0 )
            delete [] (*dst)[i - 1].pingSiteList;
    }
    delete [] (*dst);
    *dst = NULL;
    numOfDstList = 0;
}

#ifdef  _MSC_VER
#pragma warning ( default : 4996 )  // for Visual C++ 2005
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlogListDialog メッセージ ハンドラ

#ifdef  _MSC_VER
#pragma warning ( disable : 4996 )  // for Visual C++ 2005
#endif

void CBlogListDialog::OnAppendBlog() 
{
    int ret;
	CBlogSettingDialog dlgBlogList;
    dlgBlogList.disableListingButton = true;
	ret = dlgBlogList.DoModal();

    if ( (ret == IDOK)                  &&
         (dlgBlogList.m_blogName != "") &&
         (dlgBlogList.m_blogURL  != "") &&
         (dlgBlogList.m_feedURL  != "")    ) {
        m_numberOfBlog++;
        if ( m_blogListing == NULL ) {
            m_blogListing = new BLOGLIST[m_numberOfBlog];
            strcpy( m_blogListing[0].blogName, dlgBlogList.m_blogName );
            strcpy( m_blogListing[0].blogURL,  dlgBlogList.m_blogURL  );
            strcpy( m_blogListing[0].feedURL,  dlgBlogList.m_feedURL  );
            m_blogListing[0].numOfPingSite = 0;
            m_blogListing[0].pingSiteList  = NULL;
        }
        else {
            BLOGLIST    *p = new BLOGLIST[m_numberOfBlog];
            int         i;
            for ( i = 0; i < (int)(m_numberOfBlog - 1); i++ )
                CopyBlogInfo( &(p[i]), &(m_blogListing[i]) );
            strcpy( p[i].blogName, dlgBlogList.m_blogName );
            strcpy( p[i].blogURL,  dlgBlogList.m_blogURL  );
            strcpy( p[i].feedURL,  dlgBlogList.m_feedURL  );
            p[i].numOfPingSite = 0;
            p[i].pingSiteList  = NULL;
            int n = m_numberOfBlog - 1;
            DeleteBlogList( &m_blogListing, n );
            m_blogListing = p;
        }
        m_blogList.AddString( dlgBlogList.m_blogName );
        changed = true;
    }
}

#ifdef  _MSC_VER
#pragma warning ( default : 4996 )  // for Visual C++ 2005
#endif

void CBlogListDialog::OnDeleteBlog() 
{
    int numOfSelect = m_blogList.GetSelCount();

    if ( numOfSelect > 0 ) {
        CString targetBlog;
        int     *pIndex = new int[numOfSelect];

        m_blogList.GetSelItems( numOfSelect, pIndex );

        int i, j, k;
        for ( i = 0; i < numOfSelect; i++ ) {
            m_blogList.GetText( pIndex[i], targetBlog );
            for ( j = 0; j < (int)m_numberOfBlog; j++ ) {
                if ( !strcmp( m_blogListing[j].blogName , targetBlog ) ) {
                    m_blogList.DeleteString( pIndex[i] );
                    for ( k = j; k < (int)m_numberOfBlog - 1; k++ )
                        CopyBlogInfo( &(m_blogListing[k]),
                                      &(m_blogListing[k + 1]) );
                    delete [] m_blogListing[m_numberOfBlog-1].pingSiteList;
                    m_blogListing[m_numberOfBlog-1].pingSiteList  = NULL;
                    m_blogListing[m_numberOfBlog-1].numOfPingSite = 0;
                    m_numberOfBlog--;
                    break;
                }
            }
        }

        BLOGLIST    *p;
        int         n;
        CopyBlogList( &p, n, m_blogListing, m_numberOfBlog );
        DeleteBlogList( &m_blogListing, n );
        m_blogListing = p;

        delete [] pIndex;
        changed = true;
    }
}

void CBlogListDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    static bool initialized = false;
    if ( bShow ) {
        CopyBlogList( &m_safe_blogListing, m_safe_numberOfBlog,
                      m_blogListing,       m_numberOfBlog );
        int i;
        for ( i = 0; i < m_numberOfBlog; i++ )
            m_blogList.AddString( m_blogListing[i].blogName );
        initialized = true;
    }
}

void CBlogListDialog::OnOK() 
{
    if ( m_safe_blogListing )
        DeleteBlogList( &m_safe_blogListing, m_safe_numberOfBlog );

	CDialog::OnOK();
}

void CBlogListDialog::OnCancel() 
{
    if ( m_safe_blogListing ) {
        if ( changed ) {
            DeleteBlogList( &m_blogListing, m_numberOfBlog );
            CopyBlogList( &m_blogListing,     m_numberOfBlog,
                          m_safe_blogListing, m_safe_numberOfBlog );
        }

        DeleteBlogList( &m_safe_blogListing, m_safe_numberOfBlog );
    }

	CDialog::OnCancel();
}

#ifdef  _MSC_VER
#pragma warning ( disable : 4996 )  // for Visual C++ 2005
#endif

void CBlogListDialog::OnDblclkListBlogs() 
{
    int numOfSelect = m_blogList.GetSelCount();

    if ( numOfSelect > 0 ) {
        CString             targetBlog;
        CBlogSettingDialog  dlgBlogList;
        int                 *pIndex = new int[numOfSelect];
        int                 ret;
        int                 location;

        m_blogList.GetSelItems( numOfSelect, pIndex );

        int i, j;
        for ( i = 0; i < numOfSelect; i++ ) {
            location = pIndex[i]; /* 念のため、初期化しておく */
            m_blogList.GetText( pIndex[i], targetBlog );
            for ( j = 0; j < (int)m_numberOfBlog; j++ ) {
                if ( !strcmp( m_blogListing[j].blogName, targetBlog ) ) {
                    location = j;
                    break;
                }
            }

            BLOGLIST    *p = &(m_blogListing[location]);
            dlgBlogList.disableListingButton = true;
            dlgBlogList.editMode             = true;
            dlgBlogList.m_blogName = p->blogName;
            dlgBlogList.m_blogURL  = p->blogURL;
            dlgBlogList.m_feedURL  = p->feedURL;
	        ret = dlgBlogList.DoModal();

            if ( (ret == IDOK)                  &&
                 (dlgBlogList.m_blogName != "") &&
                 (dlgBlogList.m_blogURL  != "") &&
                 (dlgBlogList.m_feedURL  != "") &&
                 ((strcmp(dlgBlogList.m_blogName, p->blogName) != 0) ||
                  (strcmp(dlgBlogList.m_blogURL,  p->blogURL)  != 0) ||
                  (strcmp(dlgBlogList.m_feedURL,  p->feedURL)  != 0)    ) ) {
                m_blogList.DeleteString( pIndex[i] );
                strcpy( p->blogName, dlgBlogList.m_blogName );
                strcpy( p->blogURL,  dlgBlogList.m_blogURL  );
                strcpy( p->feedURL,  dlgBlogList.m_feedURL  );
                m_blogList.AddString( dlgBlogList.m_blogName );
                changed = true;
            }
        }

        delete [] pIndex;
    }
}

#ifdef  _MSC_VER
#pragma warning ( default : 4996 )  // for Visual C++ 2005
#endif
