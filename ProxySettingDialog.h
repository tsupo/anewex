/*
 * ProxySettingDialog.h
 *      proxy�T�[�o���ݒ�_�C�A���O �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/ProxySettingDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 3     07/07/23 13:26 Tsujimura543
 * ���[�U���ƃp�X���[�h�̎w�肪�K�v��proxy�T�[�o�o�R�ł�
 * �ʐM�ɂ��Ή�����
 * 
 * 2     04/07/07 12:04 Tsujimura543
 */

#if !defined(AFX_PROXYSETTINGDIALOG_H__DA796FB3_CBA3_408E_AD69_16FF7A137FA8__INCLUDED_)
#define AFX_PROXYSETTINGDIALOG_H__DA796FB3_CBA3_408E_AD69_16FF7A137FA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProxySettingDialog �_�C�A���O

class CProxySettingDialog : public CDialog
{
// �R���X�g���N�V����
public:
	CProxySettingDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CProxySettingDialog)
	enum { IDD = IDD_DIALOG_PROXYSETTING };
	long	m_proxyPort;
	CString	m_proxyURL;
	CString	m_proxyUsername;
	CString	m_proxyPassword;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CProxySettingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CProxySettingDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_PROXYSETTINGDIALOG_H__DA796FB3_CBA3_408E_AD69_16FF7A137FA8__INCLUDED_)
