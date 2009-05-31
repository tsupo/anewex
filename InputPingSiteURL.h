/*
 * InputPingSiteURL.h
 *      ping�T�C�gURL���̓_�C�A���O �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/InputPingSiteURL.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 5     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 4     06/10/25 20:49 Tsujimura543
 * (1) ping��ʂ��w��ł���悤�ɂ���
 * (2) ping �T�C�g��URL�ł͂Ȃ��Aping
 * �T�C�g���̂�D��I�ɕ\������悤�ɂ���
 * 
 * 3     06/10/20 2:06 Tsujimura543
 * �u�ҏW�v���̓_�C�A���O�̃^�C�g����ύX����悤�ɂ���
 * 
 * 2     04/07/07 12:04 Tsujimura543
 */

#if !defined(AFX_INPUTPINGSITEURL_H__8BDC2069_1F72_4034_9479_8A06B5FD5B45__INCLUDED_)
#define AFX_INPUTPINGSITEURL_H__8BDC2069_1F72_4034_9479_8A06B5FD5B45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInputPingSiteURL �_�C�A���O

class CInputPingSiteURL : public CDialog
{
// �R���X�g���N�V����
public:
	CInputPingSiteURL(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CInputPingSiteURL)
	enum { IDD = IDD_DIALOG_INPUT_PINGSITE };
	CEdit	m_pingSiteEdit2;
	CEdit	m_pingSiteEdit;
	CString	m_pingSiteURL;
	CString	m_pingSiteName;
	//}}AFX_DATA

    bool    m_mode; // true: �ҏW�Afalse: �ǉ�
    int     m_pingType; // weblogUpdates.ping / weblogUpdates.extendedPing

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CInputPingSiteURL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CInputPingSiteURL)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnRadioPingtypeNormal();
	afx_msg void OnRadioPingtypeExtended();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_INPUTPINGSITEURL_H__8BDC2069_1F72_4034_9479_8A06B5FD5B45__INCLUDED_)
