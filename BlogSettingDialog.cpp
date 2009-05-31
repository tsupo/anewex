/*
 * BlogSettingDialog.cpp
 *      blog���ݒ�_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/BlogSettingDialog.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 5     07/07/23 14:30 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 4     07/01/05 22:37 Tsujimura543
 * ���{��ȊO��Windows�œ��������Ƃ����ꍇ�́A�p�ꃂ�[�h�œ���
 * ����悤�ɂ���
 * 
 * 3     06/10/20 2:07 Tsujimura543
 * �u�t�B�[�hURL�v����ǉ�
 * 
 * 2     04/07/07 12:09 Tsujimura543
 */

#include "anewex.h"
#include "BlogSettingDialog.h"
#include "BlogListDialog.h"
#ifndef	lint

static char	*rcs_id =
"$Header: /comm/anewex/BlogSettingDialog.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlogSettingDialog �_�C�A���O

CBlogSettingDialog::CBlogSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CBlogSettingDialog::IDD, pParent)
{
    disableListingButton = false;
    editMode             = false;
    changed              = false;
	//{{AFX_DATA_INIT(CBlogSettingDialog)
	m_blogName = _T("");
	m_blogURL = _T("");
	m_feedURL = _T("");
	//}}AFX_DATA_INIT
}

void CBlogSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlogSettingDialog)
	DDX_Control(pDX, IDC_EDIT_FEEDURL, m_feedUrlEdit);
	DDX_Control(pDX, IDC_BUTTON_BLOGLIST, m_listing);
	DDX_Control(pDX, IDC_EDIT_BLOGURL, m_blogUrlEdit);
	DDX_Control(pDX, IDC_EDIT_BLOGNAME, m_blogNameEdit);
	DDX_Text(pDX, IDC_EDIT_BLOGNAME, m_blogName);
	DDV_MaxChars(pDX, m_blogName, 80);
	DDX_Text(pDX, IDC_EDIT_BLOGURL, m_blogURL);
	DDV_MaxChars(pDX, m_blogURL, 384);
	DDX_Text(pDX, IDC_EDIT_FEEDURL, m_feedURL);
	DDV_MaxChars(pDX, m_feedURL, 384);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBlogSettingDialog, CDialog)
	//{{AFX_MSG_MAP(CBlogSettingDialog)
	ON_BN_CLICKED(IDC_BUTTON_BLOGLIST, OnButtonBloglist)
	ON_WM_SHOWWINDOW()
	ON_EN_KILLFOCUS(IDC_EDIT_BLOGNAME, OnKillfocusEditBlogname)
	ON_EN_KILLFOCUS(IDC_EDIT_BLOGURL, OnKillfocusEditBlogurl)
	ON_EN_KILLFOCUS(IDC_EDIT_FEEDURL, OnKillfocusEditFeedurl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlogSettingDialog ���b�Z�[�W �n���h��

void CBlogSettingDialog::OnButtonBloglist() 
{
	CBlogListDialog dlgBlogList;
    dlgBlogList.m_blogListing  = m_blogListing;
    dlgBlogList.m_numberOfBlog = m_numberOfBlog;
	dlgBlogList.DoModal();
    if ( dlgBlogList.changed ) {
        m_blogListing  = dlgBlogList.m_blogListing;
        m_numberOfBlog = dlgBlogList.m_numberOfBlog;
        changed = true;

        EndDialog( IDOK );
    }
}

void CBlogSettingDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( disableListingButton ) {
        m_listing.EnableWindow( FALSE );

	    CString title;
        if ( editMode ) {
    	    title.LoadString( IDS_EDIT_BLOG_INFO );
            SetWindowText( title ); // Blog �ݒ�ύX
        }
        else {
    	    title.LoadString( IDS_ADD_BLOG_INFO );
            SetWindowText( title ); // Blog �ǉ�
        }
    }
    else
        m_listing.EnableWindow( TRUE );
}

void CBlogSettingDialog::OnKillfocusEditBlogname() 
{
    CString str;
	m_blogNameEdit.GetWindowText( str );
    if ( str.GetLength() > 0 )
        m_blogName = str;
}

void CBlogSettingDialog::OnKillfocusEditBlogurl() 
{
    CString str;
    m_blogUrlEdit.GetWindowText( str );
    if ( str.GetLength() > 0 )
        m_blogURL = str;
}

void CBlogSettingDialog::OnKillfocusEditFeedurl() 
{
    CString str;
    m_feedUrlEdit.GetWindowText( str );
    if ( str.GetLength() > 0 )
        m_feedURL = str;
}
