/*
 * ProxySettingDialog.cpp
 *      proxy�T�[�o���ݒ�_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/ProxySettingDialog.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 5     07/07/23 14:34 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 4     07/07/23 13:26 Tsujimura543
 * ���[�U���ƃp�X���[�h�̎w�肪�K�v��proxy�T�[�o�o�R�ł�
 * �ʐM�ɂ��Ή�����
 * 
 * 3     04/07/07 12:09 Tsujimura543
 * 2     04/07/07 12:08 Tsujimura543
 */

#include "anewex.h"
#include "ProxySettingDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/ProxySettingDialog.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProxySettingDialog �_�C�A���O

CProxySettingDialog::CProxySettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProxySettingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProxySettingDialog)
	m_proxyPort = 0;
	m_proxyURL = _T("");
	m_proxyUsername = _T("");
	m_proxyPassword = _T("");
	//}}AFX_DATA_INIT
}

void CProxySettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProxySettingDialog)
	DDX_Text(pDX, IDC_EDIT_PROXYPORT, m_proxyPort);
	DDV_MinMaxLong(pDX, m_proxyPort, 0, 65535);
	DDX_Text(pDX, IDC_EDIT_PROXYURL, m_proxyURL);
	DDV_MaxChars(pDX, m_proxyURL, 256);
	DDX_Text(pDX, IDC_EDIT_PROXYUSERNAME, m_proxyUsername);
	DDV_MaxChars(pDX, m_proxyUsername, 80);
	DDX_Text(pDX, IDC_EDIT_PROXYPASSWORD, m_proxyPassword);
	DDV_MaxChars(pDX, m_proxyPassword, 80);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProxySettingDialog, CDialog)
	//{{AFX_MSG_MAP(CProxySettingDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
