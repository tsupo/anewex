/*
 * anewex.h 
 *      �A�v���P�[�V���� ���C�� �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewex.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     07/07/23 14:17 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 3     07/01/05 22:37 Tsujimura543
 * ���{��ȊO��Windows�œ��������Ƃ����ꍇ�́A�p�ꃂ�[�h�œ���
 * ����悤�ɂ���
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */

#if !defined(AFX_ANEWEX_H__DC3492C2_77A2_4B61_B8B2_C31634861EDC__INCLUDED_)
#define AFX_ANEWEX_H__DC3492C2_77A2_4B61_B8B2_C31634861EDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows �w�b�_�[����w�ǎg�p����Ȃ��X�^�b�t�����O���܂��B

#include <afxwin.h>         // MFC �̃R�A����ѕW���R���|�[�l���g
#include <afxext.h>         // MFC �̊g������
#include <afxdisp.h>        // MFC �̃I�[�g���[�V���� �N���X
#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �R���� �R���g���[�� �T�|�[�g
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �R���� �R���g���[�� �T�|�[�g
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"		// ���C�� �V���{��
#include "anewexStruct.h"

/////////////////////////////////////////////////////////////////////////////
// CAnewexApp:

class CAnewexApp : public CWinApp
{
public:
	CAnewexApp();

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CAnewexApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
    LCID    m_langCode;

	//{{AFX_MSG(CAnewexApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_ANEWEX_H__DC3492C2_77A2_4B61_B8B2_C31634861EDC__INCLUDED_)
