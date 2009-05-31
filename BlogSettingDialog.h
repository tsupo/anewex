/*
 * BlogSettingDialog.h
 *      blog���ݒ�_�C�A���O �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/BlogSettingDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 3     06/10/20 2:07 Tsujimura543
 * �u�t�B�[�hURL�v����ǉ�
 * 
 * 2     04/07/07 12:04 Tsujimura543
 */

#if !defined(AFX_BLOGSETTINGDIALOG_H__33D77E4A_63FD_45B6_8013_94A6DC2DA547__INCLUDED_)
#define AFX_BLOGSETTINGDIALOG_H__33D77E4A_63FD_45B6_8013_94A6DC2DA547__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBlogSettingDialog �_�C�A���O

class CBlogSettingDialog : public CDialog
{
// �R���X�g���N�V����
public:
	CBlogSettingDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    bool        disableListingButton;   // �_�C�A���O�̓��샂�[�h #1
                                        // (�u�ꗗ�v�t�� enable �ɂ��邩�ۂ�)
    bool        editMode;               // �_�C�A���O�̓��샂�[�h #2
    bool        changed;            // �ݒ�ɕύX�����邩�ۂ�
    BLOGLIST    *m_blogListing;     // ping �𑗐M������ blog �̃��X�g
    int         m_numberOfBlog;     // ping �𑗐M������ blog �̐�

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CBlogSettingDialog)
	enum { IDD = IDD_DIALOG_BLOGSETING };
	CEdit	m_feedUrlEdit;
	CButton	m_listing;
	CEdit	m_blogUrlEdit;
	CEdit	m_blogNameEdit;
	CString	m_blogName;
	CString	m_blogURL;
	CString	m_feedURL;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CBlogSettingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CBlogSettingDialog)
	afx_msg void OnButtonBloglist();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnKillfocusEditBlogname();
	afx_msg void OnKillfocusEditBlogurl();
	afx_msg void OnKillfocusEditFeedurl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_BLOGSETTINGDIALOG_H__33D77E4A_63FD_45B6_8013_94A6DC2DA547__INCLUDED_)
