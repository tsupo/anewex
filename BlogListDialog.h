/*
 * BlogListDialog.h
 *      blog�ꗗ�\���_�C�A���O �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/BlogListDialog.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */
#if !defined(AFX_BLOGLISTDIALOG_H__47206742_967D_42C1_AA8D_AB0D5CD4D7A8__INCLUDED_)
#define AFX_BLOGLISTDIALOG_H__47206742_967D_42C1_AA8D_AB0D5CD4D7A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "anewexStruct.h"

/////////////////////////////////////////////////////////////////////////////
// CBlogListDialog �_�C�A���O

class CBlogListDialog : public CDialog
{
// �R���X�g���N�V����
public:
	CBlogListDialog(CWnd* pParent = NULL);  // �W���̃R���X�g���N�^
    void    CopyBlogInfo( BLOGLIST *dst, const BLOGLIST *src );
                                            // BLOGLIST 1���R�s�[
    void    CopyBlogList( BLOGLIST **dst, int &numOfDstList,
                          const BLOGLIST *src, int numOfList );
                                            // BLOGLIST �̃R�s�[
    void    DeleteBlogList( BLOGLIST **dst, int &numOfDstList );
                                            // BLOGLIST �̉��

    BLOGLIST    *m_blogListing;     // ping �𑗐M������ blog �̃��X�g
    int         m_numberOfBlog;     // ping �𑗐M������ blog �̐�
    BLOGLIST    *m_safe_blogListing;// ping �𑗐M������ blog �̃��X�g (�ޔ�p)
    int         m_safe_numberOfBlog;// ping �𑗐M������ blog �̐�     (�ޔ�p)
    bool        changed;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CBlogListDialog)
	enum { IDD = IDD_DIALOG_BLOGLIST };
	CListBox	m_blogList;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CBlogListDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CBlogListDialog)
	afx_msg void OnAppendBlog();
	afx_msg void OnDeleteBlog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkListBlogs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_BLOGLISTDIALOG_H__47206742_967D_42C1_AA8D_AB0D5CD4D7A8__INCLUDED_)
