/*
 * InputPingSiteURL.cpp
 *      ping�T�C�gURL���̓_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/InputPingSiteURL.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     07/07/23 14:32 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 5     07/01/05 22:37 Tsujimura543
 * ���{��ȊO��Windows�œ��������Ƃ����ꍇ�́A�p�ꃂ�[�h�œ���
 * ����悤�ɂ���
 * 
 * 4     06/10/25 20:49 Tsujimura543
 * (1) ping��ʂ��w��ł���悤�ɂ���
 * (2) ping �T�C�g��URL�ł͂Ȃ��Aping
 * �T�C�g���̂�D��I�ɕ\������悤�ɂ���
 * 
 * 3     06/10/20 2:06 Tsujimura543
 * �u�ҏW�v���̓_�C�A���O�̃^�C�g����ύX����悤�ɂ���
 * 
 * 2     04/07/07 12:09 Tsujimura543
 */

#include "anewex.h"
#include "InputPingSiteURL.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/InputPingSiteURL.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputPingSiteURL �_�C�A���O

CInputPingSiteURL::CInputPingSiteURL(CWnd* pParent /*=NULL*/)
	: CDialog(CInputPingSiteURL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputPingSiteURL)
	m_pingSiteURL = _T("");
	m_pingSiteName = _T("");
	//}}AFX_DATA_INIT

    m_mode = false;
    m_pingType = PING_TYPE_NORMAL;
}

void CInputPingSiteURL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputPingSiteURL)
	DDX_Control(pDX, IDC_EDIT_PINGSITE_NAME, m_pingSiteEdit2);
	DDX_Control(pDX, IDC_EDIT_PINGSITE_URL, m_pingSiteEdit);
	DDX_Text(pDX, IDC_EDIT_PINGSITE_URL, m_pingSiteURL);
	DDV_MaxChars(pDX, m_pingSiteURL, 384);
	DDX_Text(pDX, IDC_EDIT_PINGSITE_NAME, m_pingSiteName);
	DDV_MaxChars(pDX, m_pingSiteName, 80);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CInputPingSiteURL, CDialog)
	//{{AFX_MSG_MAP(CInputPingSiteURL)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_RADIO_PINGTYPE_NORMAL, OnRadioPingtypeNormal)
	ON_BN_CLICKED(IDC_RADIO_PINGTYPE_EXTENDED, OnRadioPingtypeExtended)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputPingSiteURL ���b�Z�[�W �n���h��

void CInputPingSiteURL::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( bShow ) {
        if ( m_mode ) {
	        CString title;
	        title.LoadString( IDS_EDIT_PING_SITE );
            SetWindowText( title ); // Ping ���M��̕ҏW
        }
        m_pingSiteEdit.SetFocus();
        m_pingSiteEdit.SetSel(0, -1, TRUE);
        m_pingSiteEdit.SetSel(-1, -1, FALSE);

        CButton *p = (CButton *)GetDlgItem( IDC_RADIO_PINGTYPE_NORMAL );
        p->SetCheck( m_pingType == PING_TYPE_NORMAL ? 1 : 0 );

        p = (CButton *)GetDlgItem( IDC_RADIO_PINGTYPE_EXTENDED );
        p->SetCheck( m_pingType == PING_TYPE_NORMAL ? 0 : 1 );
    }
}

void CInputPingSiteURL::OnRadioPingtypeNormal() 
{
    m_pingType = PING_TYPE_NORMAL;

    CButton *p = (CButton *)GetDlgItem( IDC_RADIO_PINGTYPE_NORMAL );
    p->SetCheck( 1 );

    p = (CButton *)GetDlgItem( IDC_RADIO_PINGTYPE_EXTENDED );
    p->SetCheck( 0 );
}

void CInputPingSiteURL::OnRadioPingtypeExtended() 
{
    m_pingType = PING_TYPE_EXTENDED;

    CButton *p = (CButton *)GetDlgItem( IDC_RADIO_PINGTYPE_EXTENDED );
    p->SetCheck( 1 );

    p = (CButton *)GetDlgItem( IDC_RADIO_PINGTYPE_NORMAL );
    p->SetCheck( 0 );
}
