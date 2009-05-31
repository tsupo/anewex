/*
 * anewexDlg.h
 *      ���C���_�C�A���O �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewexDlg.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 5     07/07/23 13:26 Tsujimura543
 * ���[�U���ƃp�X���[�h�̎w�肪�K�v��proxy�T�[�o�o�R�ł�
 * �ʐM�ɂ��Ή�����
 * 
 * 4     07/01/05 22:37 Tsujimura543
 * ���{��ȊO��Windows�œ��������Ƃ����ꍇ�́A�p�ꃂ�[�h�œ���
 * ����悤�ɂ���
 * 
 * 3     06/10/20 2:08 Tsujimura543
 * (1) �uGoogle �u���O�����v�ɑΉ�����
 * (2) ping�T�[�o�̓o�^�������5���₵��
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */

#if !defined(AFX_ANEWEXDLG_H__397426FA_F366_43A4_913D_3C6E8C8EA9A1__INCLUDED_)
#define AFX_ANEWEXDLG_H__397426FA_F366_43A4_913D_3C6E8C8EA9A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern "C" {
#include "xmlRPC.h"
}
#include "anewexStruct.h"

/////////////////////////////////////////////////////////////////////////////
// CAnewexDlg �_�C�A���O

class CAnewexDlg : public CDialog
{
// �\�z
public:
	CAnewexDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^
    ~CAnewexDlg();                      // �f�X�g���N�^
    void    Init();                     // �����ݒ�
    void    ReadSetting();              // �����ݒ�t�@�C���ǎ��
    void    WriteSetting();             // �����ݒ�t�@�C�����o��
    void    SetCheck( int ctrlID, int pingSiteID );
                                        // ���W�I�{�^�� ON/OFF �ݒ�
    void    ToggleTarget( CButton *cp, int pingSiteID );
                                        // ���W�I�{�^�� ON/OFF �ؑ�
    void    InitPingSiteList( BLOGLIST *p, bool initialSetting = false );
                                        // ping ���M��T�C�g���X�g������
    void    EditPingSite( int pingSiteID );
                                        // ping �T�C�gURL�ҏW
    void    GetProxyInfo( char *url,
                          int  &port,
                          char *username,
                          char *password ); // proxy ���擾
    void    WriteProxyTxt();                // proxy ��񏑏o��
    void    DeleteProxyTxt();               // proxy ���폜

    BLOGLIST        *m_blogListing;     // ping �𑗐M������ blog �̃��X�g
    BLOGLIST        *m_targetBlog;      // ���ݑI������Ă��� blog
    PINGSITELIST    *m_pingSiteListing; // ping ���M��T�C�g�̃��X�g
    int             m_numberOfBlog;     // ping �𑗐M������ blog �̐�
    int             m_numberOfPingSite; // ping ���M��T�C�g�̐�
    int             m_proxyPort;                    // proxy �|�[�g�ԍ�
    char            m_proxyURL[MAX_PATH];           // proxy URL
    char            m_proxyUsername[MAX_USERIDLEN]; // proxy ���[�U��
    char            m_proxyPassword[MAX_USERIDLEN]; // proxy �p�X���[�h

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAnewexDlg)
	enum { IDD = IDD_ANEWEX_DIALOG };
	CComboBox	m_blogList;
	CString	m_blogName;
	BOOL	m_useProxy;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAnewexDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;
    bool  m_changed;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAnewexDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetting();
	afx_msg void OnVersion();
	afx_msg void OnAddPingsite();
	afx_msg void OnRadioWeblogscom();
	afx_msg void OnRadioBloggersjp();
	afx_msg void OnRadioBlogpeople();
	afx_msg void OnRadioMyblog();
	afx_msg void OnRadioBulkfeeds();
	afx_msg void OnRadioGoo();
	afx_msg void OnRadioPingsite001();
	afx_msg void OnRadioPingsite002();
	afx_msg void OnRadioPingsite003();
	afx_msg void OnRadioPingsite004();
	afx_msg void OnRadioPingsite005();
	afx_msg void OnRadioPingsite006();
	afx_msg void OnRadioPingsite007();
	afx_msg void OnRadioPingsite008();
	afx_msg void OnRadioPingsite009();
	afx_msg void OnRadioPingsite010();
	afx_msg void OnRadioPingsite011();
	afx_msg void OnRadioPingsite012();
	afx_msg void OnRadioPingsite013();
	afx_msg void OnRadioPingsite014();
	afx_msg void OnPing();
	afx_msg void OnSelchangeCombo();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	afx_msg void OnDoubleclickedRadioPingsite001();
	afx_msg void OnDoubleclickedRadioPingsite002();
	afx_msg void OnDoubleclickedRadioPingsite003();
	afx_msg void OnDoubleclickedRadioPingsite004();
	afx_msg void OnDoubleclickedRadioPingsite005();
	afx_msg void OnDoubleclickedRadioPingsite006();
	afx_msg void OnDoubleclickedRadioPingsite007();
	afx_msg void OnDoubleclickedRadioPingsite008();
	afx_msg void OnDoubleclickedRadioPingsite009();
	afx_msg void OnDoubleclickedRadioPingsite010();
	afx_msg void OnDoubleclickedRadioPingsite011();
	afx_msg void OnDoubleclickedRadioPingsite012();
	afx_msg void OnDoubleclickedRadioPingsite013();
	afx_msg void OnDoubleclickedRadioPingsite014();
	afx_msg void OnCheckproxy();
	afx_msg void OnButtonproxy();
	afx_msg void OnRadioGoogle();
	afx_msg void OnRadioTechnorati();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_ANEWEXDLG_H__397426FA_F366_43A4_913D_3C6E8C8EA9A1__INCLUDED_)
