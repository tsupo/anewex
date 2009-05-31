/*
 * anewex.cpp
 *      �A�v���P�[�V���� ���C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewex.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     07/07/23 14:20 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 3     07/01/05 22:37 Tsujimura543
 * ���{��ȊO��Windows�œ��������Ƃ����ꍇ�́A�p�ꃂ�[�h�œ���
 * ����悤�ɂ���
 * 
 * 2     04/07/07 12:10 Tsujimura543
 */

#include "anewex.h"
#include "anewexDlg.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/anewex.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp

BEGIN_MESSAGE_MAP(CAnewexApp, CWinApp)
	//{{AFX_MSG_MAP(CAnewexApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp �N���X�̍\�z

CAnewexApp::CAnewexApp()
{
    m_langCode = GetThreadLocale();
    if ( m_langCode != 0x0411 )
        m_langCode = 0x0409;  // �u���{��v�ȊO�̏ꍇ�͋����I�Ɂu�p��v�ɂ���
    SetThreadLocale( m_langCode );
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CAnewexApp �I�u�W�F�N�g

CAnewexApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp �N���X�̏�����

BOOL CAnewexApp::InitInstance()
{
	AfxEnableControlContainer();

	CAnewexDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}
