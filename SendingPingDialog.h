/*
 * SendingPingDialog.h
 *      ping���M�_�C�A���O �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/SendingPingDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 3     05/11/11 18:19 Tsujimura543
 * �uping ���M���v�\���_�C�A���O�̎g������ς��Ă݂�
 * 
 * 2     05/01/07 13:58 Tsujimura543
 * OnTimer() ��ǉ�
 */

#if !defined(AFX_SENDINGPINGDIALOG_H__623F8CF8_BCF8_405D_BEF9_4F7F014971B9__INCLUDED_)
#define AFX_SENDINGPINGDIALOG_H__623F8CF8_BCF8_405D_BEF9_4F7F014971B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// SendingPingDialog �_�C�A���O

class SendingPingDialog : public CDialog
{
// �R���X�g���N�V����
public:
	SendingPingDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    void    ChangeDialogText( const char *title, const char *message );

// �_�C�A���O �f�[�^
	//{{AFX_DATA(SendingPingDialog)
	enum { IDD = IDD_DIALOG_SENDING };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(SendingPingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(SendingPingDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SENDINGPINGDIALOG_H__623F8CF8_BCF8_405D_BEF9_4F7F014971B9__INCLUDED_)
