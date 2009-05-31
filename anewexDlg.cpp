/*
 * anewexDlg.cpp
 *      ���C���_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jul 2004
 *
 * History:
 * $Log: /comm/anewex/anewexDlg.cpp $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 24    08/08/21 14:21 Tsujimura543
 * OnRadioPingsite010() �` OnRadioPingsite014() ���C��
 * (��5�̃{�^���̋�����������������)
 * 
 * 23    08/02/07 19:07 Tsujimura543
 * isUsedProxy() �� onButtonproxy() �̗�������uproxy���ݒ�v��
 * ���Ȃ����_�C�A���O���o�Ă��܂����Ƃ����錻�ۂɑΏ�
 * (���{�I�Ȍ����Ɋւ��ẮAxmlRPC.dll �̉��C�ɂđΏ�)
 * 
 * 22    07/12/25 16:57 Tsujimura543
 * proxy�ݒ菈���� OnButtonproxy() �Ɉ�{��
 * 
 * 21    07/12/25 14:08 Tsujimura543
 * �u����N������proxy�ݒ�̂ݍς܂���ping�̐ݒ�͍s�Ȃ킸�ɏI������
 * �ꍇ�A����N������proxy�̐ݒ肪���������v�s��ɑΏ�����
 * 
 * 20    07/11/16 19:17 Tsujimura543
 * CAboutDlg �𕪗��Ɨ�������
 * 
 * 19    07/07/23 14:26 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 18    07/07/23 13:26 Tsujimura543
 * ���[�U���ƃp�X���[�h�̎w�肪�K�v��proxy�T�[�o�o�R�ł�
 * �ʐM�ɂ��Ή�����
 * 
 * 17    07/07/03 10:33 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 16    07/01/11 20:40 Tsujimura543
 * �p�ꃂ�[�h�Ή���ƁA����Ђ낢
 * 
 * 15    07/01/09 17:14 Tsujimura543
 * �p��őΉ���ƁA����
 * 
 * 14    07/01/05 23:34 Tsujimura543
 * �p�ꃂ�[�h�Ή���ƁA�����I��
 * 
 * 13    07/01/05 22:35 Tsujimura543
 * �R�R���O��ping�T�[�o�T�[�r�X�I���̂��߁A����� technorati ��
 * �V����ping�T�[�o�Ƃ��Ďg�p����悤�ɕύX����
 * 
 * 12    07/01/04 21:09 Tsujimura543
 * �o�[�W�������\���_�C�A���O����A�T�|�[�g�pWeb�y�[�W�ɔ�ׂ�
 * �悤�ɂ���
 * 
 * 11    06/10/25 20:49 Tsujimura543
 * (1) ping��ʂ��w��ł���悤�ɂ���
 * (2) ping �T�C�g��URL�ł͂Ȃ��Aping
 * �T�C�g���̂�D��I�ɕ\������悤�ɂ���
 * 
 * 10    06/10/20 2:08 Tsujimura543
 * (1) �uGoogle �u���O�����v�ɑΉ�����
 * (2) ping�T�[�o�̓o�^�������5���₵��
 * 
 * 9     05/12/13 21:53 Tsujimura543
 * MyBlog �� URL ���h���R��RSS�� URL �ɏ��������鏈�����C��
 * 
 * 8     05/12/13 21:16 Tsujimura543
 * �ݒ�t�@�C�����́uMyBlog�v���u�h���R��RSS�v�ɏ���������悤�ɂ���
 * (URL �������ɏ���������)
 * 
 * 7     05/12/13 20:56 Tsujimura543
 * (1) MyBlog �� �h���R��RSS �ɕύX
 * (2) ping �T�C�g��o�^�\�ő吔�܂œo�^������A�ċN������Ɠo�^���e��
 *      �����Ă��܂��s��ɑΏ�
 * (3) ping �T�C�g���ҏW�_�C�A���O�� ping �T�C�g URL ���󕶎���ɂ��邱
 *     �ƂŁA���Y ping �T�C�g�̓o�^�𖕏��ł���悤�ɂ���
 * 
 * 6     05/11/11 18:19 Tsujimura543
 * �uping ���M���v�\���_�C�A���O�̎g������ς��Ă݂�
 * 
 * 5     05/04/28 11:53 Tsujimura543
 * ping ���M���̓}�E�X�J�[�\���������v�`��ɂ���悤�ɂ���
 * 
 * 4     05/01/07 13:59 Tsujimura543
 * ping ���M���s���O�Ɂu���M���_�C�A���O�v���o���悤�ɂ��Ă݂�
 * 
 * 3     05/01/06 19:48 Tsujimura543
 * ping ���M����/���s���|�b�v�A�b�v�\������悤�ɂ����B
 * 
 * 2     04/07/07 12:10 Tsujimura543
 */

#include "anewex.h"
#include "anewexDlg.h"
#include "AboutDlg.h"
#include "BlogSettingDialog.h"
#include "ProxySettingDialog.h"
#include "InputPingSiteURL.h"
#include "SendingPingDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/anewex/anewexDlg.cpp 1     09/05/14 3:29 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnewexDlg �_�C�A���O

CAnewexDlg::CAnewexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnewexDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnewexDlg)
	m_blogName = _T("");
	m_useProxy = FALSE;
	//}}AFX_DATA_INIT

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    m_blogListing      = NULL;  // ping �𑗐M������ blog �̃��X�g
    m_targetBlog       = NULL;  // �J�����gblog
    m_pingSiteListing  = NULL;  // ping ���M��T�C�g�̃��X�g
    m_numberOfBlog     = 0;     // ping �𑗐M������ blog �̐�
    m_numberOfPingSite = 0;     // ping ���M��T�C�g�̐�
    m_proxyPort        = 0;     // proxy �|�[�g�ԍ�
    m_proxyURL[0]      = NUL;   // proxy URL
    m_proxyUsername[0] = NUL;   // proxy ���[�U��
    m_proxyPassword[0] = NUL;   // proxy �p�X���[�h
    m_changed          = false;

    // �����ݒ� (�o�^�ς�ping�T�C�g�̐ݒ�A�ݒ�t�@�C���̓ǎ��)
    Init();
}

void CAnewexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnewexDlg)
	DDX_Control(pDX, IDC_COMBO, m_blogList);
	DDX_CBString(pDX, IDC_COMBO, m_blogName);
	DDV_MaxChars(pDX, m_blogName, 80);
	DDX_Check(pDX, IDC_CHECKPROXY, m_useProxy);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnewexDlg, CDialog)
	//{{AFX_MSG_MAP(CAnewexDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_SETTING, OnSetting)
	ON_BN_CLICKED(IDC_VERSION, OnVersion)
	ON_BN_CLICKED(IDC_ADD_PINGSITE, OnAddPingsite)
	ON_BN_CLICKED(IDC_PING, OnPing)
	ON_BN_CLICKED(IDC_CHECKPROXY, OnCheckproxy)
	ON_BN_CLICKED(IDC_BUTTONPROXY, OnButtonproxy)
	ON_BN_CLICKED(IDC_RADIO_WEBLOGSCOM, OnRadioWeblogscom)
	ON_BN_CLICKED(IDC_RADIO_BLOGGERSJP, OnRadioBloggersjp)
	ON_BN_CLICKED(IDC_RADIO_BLOGPEOPLE, OnRadioBlogpeople)
	ON_BN_CLICKED(IDC_RADIO_MYBLOG, OnRadioMyblog)
	ON_BN_CLICKED(IDC_RADIO_BULKFEEDS, OnRadioBulkfeeds)
	ON_BN_CLICKED(IDC_RADIO_GOO, OnRadioGoo)
	ON_BN_CLICKED(IDC_RADIO_GOOGLE, OnRadioGoogle)
	ON_BN_CLICKED(IDC_RADIO_TECHNORATI, OnRadioTechnorati)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_001, OnRadioPingsite001)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_002, OnRadioPingsite002)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_003, OnRadioPingsite003)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_004, OnRadioPingsite004)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_005, OnRadioPingsite005)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_006, OnRadioPingsite006)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_007, OnRadioPingsite007)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_008, OnRadioPingsite008)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_009, OnRadioPingsite009)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_010, OnRadioPingsite010)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_011, OnRadioPingsite011)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_012, OnRadioPingsite012)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_013, OnRadioPingsite013)
	ON_BN_CLICKED(IDC_RADIO_PINGSITE_014, OnRadioPingsite014)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_001, OnDoubleclickedRadioPingsite001)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_002, OnDoubleclickedRadioPingsite002)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_003, OnDoubleclickedRadioPingsite003)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_004, OnDoubleclickedRadioPingsite004)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_005, OnDoubleclickedRadioPingsite005)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_006, OnDoubleclickedRadioPingsite006)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_007, OnDoubleclickedRadioPingsite007)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_008, OnDoubleclickedRadioPingsite008)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_009, OnDoubleclickedRadioPingsite009)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_010, OnDoubleclickedRadioPingsite010)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_011, OnDoubleclickedRadioPingsite011)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_012, OnDoubleclickedRadioPingsite012)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_013, OnDoubleclickedRadioPingsite013)
	ON_BN_DOUBLECLICKED(IDC_RADIO_PINGSITE_014, OnDoubleclickedRadioPingsite014)
	ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnewexDlg �ǉ����\�b�h

// �f�X�g���N�^
CAnewexDlg::~CAnewexDlg()
{
    if ( m_blogListing ) {
        int i;
        for ( i = 0; i < m_numberOfBlog; i++ ) {
            if ( m_blogListing[i].pingSiteList ) {
                delete [] m_blogListing[i].pingSiteList;
                m_blogListing[i].pingSiteList = NULL;
            }
        }
        delete [] m_blogListing;
        m_blogListing = NULL;
    }
    if ( m_pingSiteListing ) {
        delete [] m_pingSiteListing;
        m_pingSiteListing = NULL;
    }
}

// �����ݒ�
void
CAnewexDlg::Init()
{
    int id[] = {
        IDC_RADIO_WEBLOGSCOM,
        IDC_RADIO_BLOGGERSJP,
        IDC_RADIO_BLOGPEOPLE,
        IDC_RADIO_MYBLOG,
        IDC_RADIO_TECHNORATI,
        IDC_RADIO_BULKFEEDS,
        IDC_RADIO_GOO,
        IDC_RADIO_GOOGLE,
        IDC_RADIO_PINGSITE_001,
        IDC_RADIO_PINGSITE_002,
        IDC_RADIO_PINGSITE_003,
        IDC_RADIO_PINGSITE_004,
        IDC_RADIO_PINGSITE_005,
        IDC_RADIO_PINGSITE_006,
        IDC_RADIO_PINGSITE_007,
        IDC_RADIO_PINGSITE_008,
        IDC_RADIO_PINGSITE_009,
        IDC_RADIO_PINGSITE_010,
        IDC_RADIO_PINGSITE_011,
        IDC_RADIO_PINGSITE_012,
        IDC_RADIO_PINGSITE_013,
        IDC_RADIO_PINGSITE_014
    };
	CString siteName;
	CString siteURL;

    // �o�^�ς� ping �T�C�g�̐ݒ�
    m_numberOfPingSite = 0;
    m_pingSiteListing  = new PINGSITELIST[MAX_NUM_OF_PINGSITE];

    int i;
    for ( i = 0; i < NUM_OF_INITIAL_PINGSITE; i++ ) {
        m_pingSiteListing[i].ctrlID   = id[i];
        m_pingSiteListing[i].isTarget = false;
        m_pingSiteListing[i].sendTime = 0;
        m_pingSiteListing[i].pingType = PING_TYPE_NORMAL;
        switch ( i ) {
        case PINGSITE_ID_WEBLOGSCOM:
            siteName.LoadString( IDS_SITENAME_001 );
            siteURL.LoadString(  IDS_SITEURL_001 );
            break;
        case PINGSITE_ID_BLOGGERSJP:
            siteName.LoadString( IDS_SITENAME_002 );
            siteURL.LoadString(  IDS_SITEURL_002 );
            break;
        case PINGSITE_ID_BLOGPEOPLE:
            siteName.LoadString( IDS_SITENAME_003 );
            siteURL.LoadString(  IDS_SITEURL_003 );
            break;
        case PINGSITE_ID_MYBLOG:
            siteName.LoadString( IDS_SITENAME_004 );
            siteURL.LoadString(  IDS_SITEURL_004 );
            break;
        case PINGSITE_ID_TECHNORATI:
            siteName.LoadString( IDS_SITENAME_005 );
            siteURL.LoadString(  IDS_SITEURL_005 );
            break;
        case PINGSITE_ID_BULKFEEDS:
            siteName.LoadString( IDS_SITENAME_006 );
            siteURL.LoadString(  IDS_SITEURL_006 );
            break;
        case PINGSITE_ID_GOOBLOG:
            siteName.LoadString( IDS_SITENAME_007 );
            siteURL.LoadString(  IDS_SITEURL_007 );
            break;
        case PINGSITE_ID_GOOGLE:
            siteName.LoadString( IDS_SITENAME_008 );
            siteURL.LoadString(  IDS_SITEURL_008 );
            m_pingSiteListing[i].pingType = PING_TYPE_EXTENDED; /* {@@} */
            break;
        }
        strcpy( m_pingSiteListing[i].siteName, siteName );
        strcpy( m_pingSiteListing[i].siteURL,  siteURL );
        m_numberOfPingSite++;
    }
    for ( ; i < MAX_NUM_OF_PINGSITE; i++ ) {
        m_pingSiteListing[i].ctrlID      = id[i];
        m_pingSiteListing[i].isTarget    = false;
        m_pingSiteListing[i].sendTime    = 0;
        m_pingSiteListing[i].siteName[0] = NUL;
        m_pingSiteListing[i].siteURL[0]  = NUL;
        m_pingSiteListing[i].pingType    = PING_TYPE_NORMAL;
    }

    // �����ݒ�t�@�C���̓ǎ��
    ReadSetting();
}

// �����ݒ�t�@�C���ǎ��
void
CAnewexDlg::ReadSetting()
{
    char            buf[BUFSIZ];
    char            *p, *q;
    long            l;
    long            blogCnt = 0;
    long            siteCnt = 0;
    FILE            *fp;
    BLOGLIST        *bp;
    PINGSITELIST    *plp, *pp;
    bool            changed = false;

    if ( ( fp = fopen( INIT_FILENAME, "r" ) ) == NULL ) {
        if ( isUsedProxy() ) {
	        CString title;
	        CString text;

            title.LoadString( IDS_QUERY_PROXY );
            text.LoadString(  IDS_USE_PROXY );
            int r = ::MessageBox( NULL,
                                  text,     // proxy ���g�p���܂��� ?
                                  title,    // proxy �ݒ�₢���킹
                                  MB_YESNO|MB_ICONEXCLAMATION );
            if ( r == IDYES ) {
                m_useProxy = TRUE;
                OnButtonproxy();
                if ( m_proxyURL[0] && (m_proxyPort > 0) )
                    m_changed  = true;
            }
            else
                m_useProxy = FALSE;
        }

        return;
    }

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
        while ( (*p == ' ') || (*p == '\t') )
            p++;
        if ( (*p == '#') || (*p == '\n') || (*p == '\r') || (*p == NUL) )
            continue;

        // numOfBlogs: ping ���΂����� blog �̐�
        if ( (m_numberOfBlog == 0) && !m_blogListing ) {
            if ( !strncmp( p, "numOfBlogs: ", 12 ) ) {
                l = atol( p + 12 );
                if ( l > 0 ) {
                    BLOGLIST    *blp;
                    m_numberOfBlog = l;
                    m_blogListing  = new BLOGLIST[m_numberOfBlog];

                    int i;
                    for ( i = 0; i < m_numberOfBlog; i++ ) {
                        blp = &(m_blogListing[i]);
                        blp->blogName[0]   = NUL;
                        blp->blogURL[0]    = NUL;
                        blp->feedURL[0]    = NUL;
                        blp->numOfPingSite = 0;
                        blp->pingSiteList  = NULL;
                    }
                }
            }
            continue;
        }

        q = &(p[strlen(p) - 1]);
        while ( *q == '\n' ) {
            *q = NUL;
            q--;
            if ( q <= p )
                break;
        }

        bp  = &(m_blogListing[blogCnt]); 

        // blogName: ping ���΂����� blog �̖��O (ping���M��)
        if ( !strncmp( p, "blogName: ", 10 ) ) {
            p += 10;
            while ( (*p == ' ') || (*p == '\t') )
                p++;
            strcpy( bp->blogName, p );
        }
        // blogURL:  ping ���΂����� blog ��URL  (ping���M��)
        else if ( !strncmp( p, "blogURL: ", 9 ) ) {
            p += 9;
            while ( (*p == ' ') || (*p == '\t') )
                p++;
            strcpy( bp->blogURL, p );
        }
        // feedURL:  ping ���΂����� blog �� RSS �܂��� Atom �t�B�[�h��URL
        else if ( !strncmp( p, "feedURL: ", 9 ) ) {
            p += 9;
            while ( (*p == ' ') || (*p == '\t') )
                p++;
            strcpy( bp->feedURL, p );
        }

        if ( (bp->blogName[0] == NUL) ||
             (bp->blogURL[0]  == NUL)    ) {
            continue;
        }

        // numOfPingSites: ping ���΂����� ping �T�C�g�̐�
        if ( (blogCnt == 0) && (bp->numOfPingSite == 0) ) {
            if ( !strncmp( p, "numOfPingSites: ", 16 ) ) {
                l = atol( p + 16 );
                if ( (l > 0) && (l <= MAX_NUM_OF_PINGSITE) )
                    m_numberOfPingSite = l;
                else
                    m_numberOfPingSite = NUM_OF_INITIAL_PINGSITE;
                bp->numOfPingSite = m_numberOfPingSite;
            }
            continue;
        }

        if ( !(bp->pingSiteList) )
            InitPingSiteList( bp, true );

        pp  = &(bp->pingSiteList[siteCnt]);
        plp = &(m_pingSiteListing[siteCnt]);

        // pingSiteName: ping ���΂����� ping �T�C�g�̖��O (ping���M��)
        if ( !strncmp( p, "pingSiteName: ", 14 ) ) {
            p += 14;
            while ( (*p == ' ') || (*p == '\t') )
                p++;

            if ( !strcmp( p, "MyBlog" ) ) {
                q = "�h���R��RSS";
                changed = true;
            }
            else if ( !strcmp( p, "�R�R���O" ) ) {
                q = "technorati";
                changed = true;
            }
            else
                q = p;

            strcpy( pp->siteName, q );
            if ( blogCnt == 0 )
                strcpy( plp->siteName, q );
        }
        // pingSiteURL:  ping ���΂����� ping �T�C�g��URL  (ping���M��)
        else if ( !strncmp( p, "pingSiteURL: ", 13 ) ) {
            p += 13;
            while ( (*p == ' ') || (*p == '\t') )
                p++;

            if ( !strcmp( p, "http://ping.myblog.jp"  ) ||
                 !strcmp( p, "http://ping.myblog.jp/" )    ) {
                q = "http://ping.rss.drecom.jp/";
                changed = true;
            }
            else if ( !strcmp( p, "http://ping.cocolog-nifty.com/xmlrpc" ) ) {
                q = "http://rpc.technorati.com/rpc/ping";
                changed = true;
            }
            else
                q = p;

            strcpy( pp->siteURL, q );
            if ( blogCnt == 0 )
                strcpy( plp->siteURL, q );
        }
        // pingType:  ping ���
        else if ( !strncmp( p, "pingType: ", 10 ) ) {
            p += 10;
            while ( (*p == ' ') || (*p == '\t') )
                p++;

            if ( !strcmp( p, "weblogUpdates.extendedPing" ) )
                pp->pingType = PING_TYPE_EXTENDED;
            else
                pp->pingType = PING_TYPE_NORMAL;
            if ( blogCnt == 0 )
                plp->pingType = pp->pingType;
        }
        // isTarget:     ���Y ping �T�C�g�Ɏ��ۂ� ping ���΂����ۂ�
        else if ( !strncmp( p, "isTarget: ", 10 ) ) {
            l = atol( p + 10 );
            if ( l == 0 )
                pp->isTarget  = false;
            else
                pp->isTarget  = true;
            if ( blogCnt == 0 )
                plp->isTarget = false;
            continue;
        }
        // lastUpdated:  ���Y ping �T�C�g�ɍŌ�� ping ���΂�������
        else if ( !strncmp( p, "lastUpdated: ", 13 ) ) {
            l = atol( p + 13 );
            if ( l >= 0 ) {
                pp->sendTime = l;
                if ( blogCnt == 0 )
                    plp->sendTime = 0;
            }
            else
                pp->sendTime = 0;
        }

        if ( (pp->siteName[0] == NUL) ||
             (pp->siteURL[0]  == NUL) ||
             (pp->sendTime    == -1)     ) {
            continue;
        }

        siteCnt++;
        if ( siteCnt >= m_numberOfPingSite ) {
            siteCnt = 0;
            blogCnt++;
            if ( blogCnt >= m_numberOfBlog )
                break;
        }
    }

    if ( p || (m_numberOfBlog == 0) ) {
        if ( m_numberOfBlog == 0 )
            rewind( fp );
        while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
            while ( (*p == ' ') || (*p == '\t') )
                p++;
            if ( (*p == '#') || (*p == '\n') || (*p == '\r') || (*p == NUL) )
                continue;
            q = &(p[strlen(p) - 1]);
            while ( *q == '\n' ) {
                *q = NUL;
                q--;
                if ( q <= p )
                    break;
            }

            if ( !strncmp( p, "useProxy: " , 10 ) ) {
                p += 10;
                l = atol( p );
                if ( l == 0 )
                    m_useProxy = FALSE;
                else
                    m_useProxy = TRUE;
            }
            else if ( !strncmp( p, "proxyPort: ", 11 ) ) {
                p += 11;
                l = atol( p );
                if ( (l > 0) && (l < 65536) )
                    m_proxyPort = l;
            }
            else if ( !strncmp( p, "proxyURL: ", 10 ) ) {
                p += 10;
                while ( (*p == ' ') || (*p == '\t') )
                    p++;
                strcpy( m_proxyURL, p );
            }
            else if ( !strncmp( p, "proxyUsername: ", 15 ) ) {
                p += 15;
                while ( (*p == ' ') || (*p == '\t') )
                    p++;
                strcpy( m_proxyUsername, p );
            }
            else if ( !strncmp( p, "proxyPassword: ", 15 ) ) {
                p += 15;
                while ( (*p == ' ') || (*p == '\t') )
                    p++;
                strcpy( m_proxyPassword, p );
            }
        }
    }

    if ( m_useProxy && ((m_proxyPort == 0) || (m_proxyURL[0] == NUL)) ) {
        m_changed  = true;   /* bool �^ */
        m_useProxy = FALSE;  /* BOOL �^ */
    }
    if ( !m_useProxy ) {
        m_proxyPort        = 0;
        m_proxyURL[0]      = NUL;
        m_proxyUsername[0] = NUL;
        m_proxyPassword[0] = NUL;
        DeleteProxyTxt();
        changed = true;
    }

    fclose( fp );

    if ( strcmp( m_pingSiteListing[PINGSITE_ID_GOOGLE].siteURL,
                 "http://blogsearch.google.com/ping/RPC2" ) ) {
        /* Ver 1.31 �ȑO�̐ݒ�t�@�C������̈ڍs���� */
        int i;
        for ( i = MAX_NUM_OF_PINGSITE - 1; i > PINGSITE_ID_GOOGLE; i-- ) {
         // m_pingSiteListing[i].ctrlID   = m_pingSiteListing[i - 1].ctrlID;
            m_pingSiteListing[i].isTarget = m_pingSiteListing[i - 1].isTarget;
            m_pingSiteListing[i].sendTime = m_pingSiteListing[i - 1].sendTime;
            strcpy( m_pingSiteListing[i].siteName,
                    m_pingSiteListing[i - 1].siteName );
            strcpy( m_pingSiteListing[i].siteURL,
                    m_pingSiteListing[i - 1].siteURL );
            m_pingSiteListing[i].pingType = m_pingSiteListing[i - 1].pingType;

            int j;
            for ( j = 0; j < m_numberOfBlog; j++ ) {
                BLOGLIST        *bp;
                PINGSITELIST    *plp, *pp;

                bp  = &(m_blogListing[j]);
                plp = &(bp->pingSiteList[i - 1]);
                pp  = &(bp->pingSiteList[i]);

                bp->numOfPingSite = m_numberOfPingSite + 1;
             // pp->ctrlID   = plp->ctrlID;
                pp->isTarget = plp->isTarget;
                pp->sendTime = plp->sendTime;
                strcpy( pp->siteName, plp->siteName );
                strcpy( pp->siteURL,  plp->siteURL );
                pp->pingType = plp->pingType;
            }
        }

        CString siteName;
        CString siteURL;

        siteName.LoadString( IDS_SITENAME_008 );
        siteURL.LoadString(  IDS_SITEURL_008 );
     // m_pingSiteListing[PINGSITE_ID_GOOGLE].ctrlID   = IDC_RADIO_GOOGLE;
        m_pingSiteListing[PINGSITE_ID_GOOGLE].isTarget = false;
        m_pingSiteListing[PINGSITE_ID_GOOGLE].sendTime = 0;
        strcpy( m_pingSiteListing[PINGSITE_ID_GOOGLE].siteName,
                siteName ); // Google �u���O����
        strcpy( m_pingSiteListing[PINGSITE_ID_GOOGLE].siteURL,
                siteURL );  // http://blogsearch.google.com/ping/RPC2
        m_pingSiteListing[PINGSITE_ID_GOOGLE].pingType = PING_TYPE_EXTENDED;

        m_numberOfPingSite++;

        int j;
        for ( j = 0; j < m_numberOfBlog; j++ ) {
            BLOGLIST        *bp;
            PINGSITELIST    *pp;

            bp  = &(m_blogListing[j]);
            pp  = &(bp->pingSiteList[PINGSITE_ID_GOOGLE]);

         // pp->ctrlID   = IDC_RADIO_GOOGLE;
            pp->isTarget = false;
            pp->sendTime = 0;
            strcpy( pp->siteName, siteName );   // Google �u���O����
            strcpy( pp->siteURL,  siteURL  );   // http://blogsearch.google.com/ping/RPC2
            pp->pingType = PING_TYPE_EXTENDED;
        }

        changed = true;
    }

    if ( changed )
        WriteSetting();
}
// �����ݒ�t�@�C���t�H�[�}�b�g
/*
 * numOfBlogs: ping ���΂����� blog �̐�
 * [-- ������ ping ���΂����� blog �̐� �̕�����       ������ --]
 *   blogName: ping ���΂����� blog �̖��O (ping���M��)
 *   blogURL:  ping ���΂����� blog ��URL  (ping���M��)
 * 
 *   numOfPingSites: ping ���΂����� ping �T�C�g�̐�
 *   [---- �� ping ���΂����� ping �T�C�g�̐� �̕����� �� ----]
 *     pingSiteName: ping ���΂����� ping �T�C�g�̖��O (ping���M��)
 *     pingSiteURL:  ping ���΂����� ping �T�C�g��URL  (ping���M��)
 *     pingType:     ping ���
 *     isTarget:     ���Y ping �T�C�g�Ɏ��ۂ� ping ���΂����ۂ�
 *     lastUpdated:  ���Y ping �T�C�g�ɍŌ�� ping ���΂�������
 *   [---- �� ping ���΂����� ping �T�C�g�̐� �̕����� �� ----]
 * 
 * [-- ������ ping ���΂����� blog �̐� �̕�����       ������ --]
 */

// �����ݒ�t�@�C�����o��
void
CAnewexDlg::WriteSetting()
{
    FILE            *fp;
    BLOGLIST        *bp;
    PINGSITELIST    *pp;

    if ( ( fp = fopen( INIT_FILENAME, "w" ) ) == NULL ) {
	    CString title;
	    CString text;

        title.LoadString( IDS_WRITE_FAILURE );
        if ( ( fp = fopen( INIT_FILENAME, "r" ) ) == NULL ) {
	        text.LoadString(  IDS_CREATE_FAILURE );
            ::MessageBox( NULL,
                          text,     // �����ݒ�t�@�C���̍쐬�Ɏ��s���܂���
                          title,    // �����ݒ�t�@�C�����o�����s
                          MB_OK|MB_ICONEXCLAMATION );
        }
        else {
            fclose( fp );

	        text.LoadString(  IDS_UPDATE_FAILURE );
            ::MessageBox( NULL,
                          text,     // �����ݒ�t�@�C���̍X�V�Ɏ��s���܂���
                          title,    // �����ݒ�t�@�C�����o�����s
                          MB_OK|MB_ICONEXCLAMATION );
        }
        return;
    }

    fprintf( fp, "numOfBlogs: %d\n", m_numberOfBlog );

    int i;
    for ( i = 0; i < m_numberOfBlog; i++ ) {
        bp = &(m_blogListing[i]);
        fprintf( fp, "#\n# blog #%03d\n#\n", i + 1 );
        fprintf( fp, "blogName: %s\n", bp->blogName );
        fprintf( fp, "blogURL:  %s\n", bp->blogURL );
        if ( bp->feedURL[0] )
            fprintf( fp, "feedURL:  %s\n", bp->feedURL );

        fprintf( fp, "numOfPingSites: %d\n", bp->numOfPingSite );

        int j;
        for ( j = 0; j < bp->numOfPingSite; j++ ) {
            pp = &(bp->pingSiteList[j]);
            fprintf( fp, "#\n#   ping site #%03d-%03d\n#\n", i + 1, j + 1 );
            fprintf( fp, "pingSiteName: %s\n", pp->siteName );
            fprintf( fp, "pingSiteURL:  %s\n", pp->siteURL );
            fprintf( fp, "pingType:     %s\n",
                     pp->pingType == PING_TYPE_EXTENDED
                        ? "weblogUpdates.extendedPing"
                        : "weblogUpdates.ping" );
            fprintf( fp, "isTarget:     %c\n", pp->isTarget ? '1' : '0' );
            fprintf( fp, "lastUpdated:  %d\n", pp->sendTime );
        }
    }
    if ( m_useProxy ) {
        fputs( "#####\n", fp );
        fprintf( fp, "useProxy:  1\n" );
        fprintf( fp, "proxyPort: %d\n", m_proxyPort );
        fprintf( fp, "proxyURL:  %s\n", m_proxyURL );
        if ( m_proxyUsername[0] ) {
            fprintf( fp, "proxyUsername: %s\n", m_proxyUsername );
            if ( m_proxyPassword[0] )
                fprintf( fp, "proxyPassword: %s\n", m_proxyPassword );
        }
    }

    fclose( fp );

    m_changed = false;
}


// ���W�I�{�^�� ON/OFF �ؑ�
void
CAnewexDlg::ToggleTarget(CButton *cp, int pingSiteID )
{
    PINGSITELIST    *lp = &(m_targetBlog->pingSiteList[pingSiteID]);

    lp->isTarget = !(lp->isTarget);
    if ( !(lp->isTarget) )
        cp->SetCheck( 0 );
    m_changed = true;
}

// ���W�I�{�^�� ON/OFF �ݒ�
void
CAnewexDlg::SetCheck( int ctrlID, int pingSiteID )
{
    CButton *p = (CButton *)GetDlgItem( ctrlID );
    if ( !m_targetBlog                               ||
         !(m_targetBlog->pingSiteList)               ||
         (m_targetBlog->numOfPingSite <= pingSiteID)    ) {
        p->SetCheck( 0 );
        return;
    }

    ToggleTarget( p, pingSiteID );
}


// ping �T�C�g��񏉊���
void
CAnewexDlg::InitPingSiteList( BLOGLIST *p, bool initialSetting /* = false */ )
{
    PINGSITELIST    *pp, *mp;

    p->numOfPingSite = m_numberOfPingSite;
    p->pingSiteList  = new PINGSITELIST[MAX_NUM_OF_PINGSITE];

    int i;
    for ( i = 0; i < m_numberOfPingSite; i++ ) {
        pp = &(p->pingSiteList[i]);
        mp = &(m_pingSiteListing[i]);
        pp->ctrlID       = mp->ctrlID;
        if ( initialSetting ) {
            pp->isTarget = false;
            pp->sendTime = -1;
        }
        else {
            pp->isTarget = mp->isTarget;
            pp->sendTime = mp->sendTime;
        }
        strcpy( pp->siteName, mp->siteName );
        strcpy( pp->siteURL,  mp->siteURL );
        pp->pingType = mp->pingType;
    }
    for ( ; i < MAX_NUM_OF_PINGSITE; i++ ) {
        pp = &(p->pingSiteList[i]);
        mp = &(m_pingSiteListing[i]);
        pp->ctrlID       = mp->ctrlID;
        pp->isTarget     = false;
        if ( initialSetting )
            pp->sendTime = -1;
        else
            pp->sendTime = 0;
        pp->siteName[0]  = NUL;
        pp->siteURL[0]   = NUL;
        pp->pingType     = PING_TYPE_NORMAL;
    }
}


// ping �T�C�gURL�ҏW
void
CAnewexDlg::EditPingSite( int pingSiteID )
{
    if ( (m_numberOfPingSite <= pingSiteID)                ||
         (m_pingSiteListing[pingSiteID].siteURL[0] == NUL)    )
        return;

    bool                changed = false;
    int                 ret;
    PINGSITELIST        *mp = &(m_pingSiteListing[pingSiteID]);
	CInputPingSiteURL   dlgInputPingSite;

    dlgInputPingSite.m_pingSiteURL  = mp->siteURL;
    dlgInputPingSite.m_pingSiteName = mp->siteName;
    dlgInputPingSite.m_pingType     = mp->pingType;
    dlgInputPingSite.m_mode         = true;  // �ҏW
	ret = dlgInputPingSite.DoModal();

    if ( ret == IDOK ) {
        int length = dlgInputPingSite.m_pingSiteURL.GetLength();

        if ((length >= 8)                                                 &&
            ((strcmp(dlgInputPingSite.m_pingSiteURL, mp->siteURL) != 0)||
             (strcmp(dlgInputPingSite.m_pingSiteName,mp->siteName)!= 0)||
             (dlgInputPingSite.m_pingType != mp->pingType)               )  ){
            strcpy( mp->siteURL,  dlgInputPingSite.m_pingSiteURL );
            if ( dlgInputPingSite.m_pingSiteName.GetLength() > 0 )
                strcpy( mp->siteName, dlgInputPingSite.m_pingSiteName );
            else
                strcpy( mp->siteName, dlgInputPingSite.m_pingSiteURL );
            mp->pingType = dlgInputPingSite.m_pingType;

            CButton *p = (CButton *)GetDlgItem( mp->ctrlID );
         // p->SetWindowText( mp->siteURL );
            p->SetWindowText( mp->siteName );

            int i;
            for ( i = 0; i < m_numberOfBlog; i++ ) {
                mp = &(m_blogListing[i].pingSiteList[pingSiteID]);
                strcpy( mp->siteURL,  dlgInputPingSite.m_pingSiteURL );
                if ( dlgInputPingSite.m_pingSiteName.GetLength() > 0 )
                    strcpy( mp->siteName, dlgInputPingSite.m_pingSiteName );
                else
                    strcpy( mp->siteName, dlgInputPingSite.m_pingSiteURL );
                mp->pingType = dlgInputPingSite.m_pingType;
            }

            changed = true;
        }
        else if ( length == 0 ) {
            // ���Y ping �T�C�g���폜
            PINGSITELIST    *mp2;
            CButton         *bp;

            int j;
            for ( j = pingSiteID; j < m_numberOfPingSite - 1; j++ ) {
                mp  = &(m_pingSiteListing[j]);
                mp2 = &(m_pingSiteListing[j + 1]);
                strcpy( mp->siteURL,  mp2->siteURL );
                strcpy( mp->siteName, mp2->siteName );
                mp->pingType = mp2->pingType;
                mp->sendTime = mp2->sendTime;
                mp->isTarget = mp2->isTarget;

                bp = (CButton *)GetDlgItem( mp->ctrlID );
             // bp->SetWindowText( mp->siteURL );
                bp->SetWindowText( mp->siteName );
            }

            mp = &(m_pingSiteListing[j]);
            mp->siteURL[0]  = NUL;
            mp->siteName[0] = NUL;
            mp->pingType    = PING_TYPE_NORMAL;
            mp->sendTime    = -1;
            mp->isTarget    = false;

            bp = (CButton *)GetDlgItem( mp->ctrlID );
            bp->SetWindowText( "(���ݒ�)" );
            bp->EnableWindow( FALSE );

            int i;
            for ( i = 0; i < m_numberOfBlog; i++ ) {
                for ( j = pingSiteID; j < m_numberOfPingSite - 1; j++ ) {
                    mp  = &(m_blogListing[i].pingSiteList[j]);
                    mp2 = &(m_blogListing[i].pingSiteList[j + 1]);
                    *mp = *mp2;
                }

                mp = &(m_blogListing[i].pingSiteList[j]);
                mp->siteURL[0]  = NUL;
                mp->siteName[0] = NUL;
                mp->pingType    = PING_TYPE_NORMAL;
                mp->sendTime    = -1;
                mp->isTarget    = false;
                (m_blogListing[i].numOfPingSite)--;
            }

            m_numberOfPingSite--;
            changed = true;
        }

        if ( changed ) {
            CButton *cbp = (CButton *)GetDlgItem( IDC_ADD_PINGSITE );
            if ( m_numberOfPingSite >= MAX_NUM_OF_PINGSITE )
                cbp->EnableWindow( FALSE );
            else
                cbp->EnableWindow( TRUE );

            WriteSetting();
        }
    }
}


// proxy ���擾
void
CAnewexDlg::GetProxyInfo( char *url, int &port, char *username, char *password )
{
    BOOL            useProxy  = FALSE;
    unsigned short  proxyPort = 0;
    char            proxyUserName[MAX_USERIDLEN];
    char            proxyPassword[MAX_USERIDLEN];

    proxyUserName[0] = NUL;
    proxyPassword[0] = NUL;
    getProxyInfo( &useProxy, url, &proxyPort, proxyUserName, proxyPassword );
    if ( useProxy ) {       // �� IE �ȊO�� Firefox �� Opera �ɂ��Ή�
        port = proxyPort;
        strcpy( username, proxyUserName );
        strcpy( password, proxyPassword );
    }
}

// proxy ��񏑏o��
void
CAnewexDlg::WriteProxyTxt()
{
    int                 proxyPort = 0;
    char                proxyURL[MAX_PATH];
    char                proxyUsername[MAX_USERIDLEN];
    char                proxyPassword[MAX_USERIDLEN];

    // proxy ���擾
    GetProxyInfo( proxyURL, proxyPort, proxyUsername, proxyPassword );
    if ( (m_proxyPort > 0)                                   &&
         ((proxyPort != m_proxyPort)                    ||
          (strcmp(proxyURL, m_proxyURL) != 0)           ||
          (strcmp(proxyUsername, m_proxyUsername) != 0) ||
          (strcmp(proxyPassword, m_proxyPassword) != 0)    )    ) {
        // ���W�X�g���� proxy ���ƈႤ�ꍇ�A�܂��̓��W�X�g���� proxy ���
        // ���݂��Ȃ��ꍇ�Aproxy �����t�@�C���ɏ����o��
        FILE    *fp;
        if ( ( fp = fopen( PROXY_FILENAME, "w" ) ) != NULL ) {
            fprintf( fp, "%s\n%d\n", m_proxyURL, m_proxyPort );
            if ( proxyUsername[0] ) {
                fprintf( fp, "%s\n", proxyUsername );
                if ( proxyPassword[0] )
                    fprintf( fp, "%s\n", proxyPassword );
            }
            fclose( fp );
        }
    }
}

// proxy ���폜
void
CAnewexDlg::DeleteProxyTxt()
{
    unlink( PROXY_FILENAME );
}


/////////////////////////////////////////////////////////////////////////////
// CAnewexDlg ���b�Z�[�W �n���h��

BOOL CAnewexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
    if ( m_numberOfPingSite < MAX_NUM_OF_PINGSITE ) {
        int i;
        for ( i = m_numberOfPingSite; i < MAX_NUM_OF_PINGSITE; i++ ) {
            CButton *p = (CButton *)GetDlgItem( m_pingSiteListing[i].ctrlID );
            p->EnableWindow( FALSE );
        }
    }
	
	return TRUE;
}

void CAnewexDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CAnewexDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width()  - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CAnewexDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAnewexDlg::OnSetting() 
{
	// Blog �ݒ�_�C�A���O��\��
    int                 ret;
    BLOGLIST            *bp;
	CBlogSettingDialog  dlgBlogSetting;

    dlgBlogSetting.m_blogListing  = m_blogListing;
    dlgBlogSetting.m_numberOfBlog = m_numberOfBlog;
	ret = dlgBlogSetting.DoModal();
    if ( dlgBlogSetting.changed ) {
        m_targetBlog = NULL;

        int i;
        for ( i = m_numberOfBlog - 1; i >= 0; i-- )
            m_blogList.DeleteString( i );

        m_blogListing  = dlgBlogSetting.m_blogListing;
        m_numberOfBlog = dlgBlogSetting.m_numberOfBlog;

        for ( i = 0; i < m_numberOfBlog; i++ ) {
            bp = &(m_blogListing[i]);
            m_blogList.AddString( bp->blogName );
            if ( bp->numOfPingSite == 0 )
                InitPingSiteList( bp );
        }
        WriteSetting();
        return;
    }

    if ( (ret == IDOK) && (dlgBlogSetting.m_blogName.GetLength() > 0) ) {
        if ( !m_blogListing ) {
            m_blogListing = new BLOGLIST[1];
        }
        else {
            BLOGLIST *np = new BLOGLIST[m_numberOfBlog + 1];

            int i;
            for ( i = 0; i < m_numberOfBlog; i++ ) {
                bp = &(m_blogListing[i]);
                strcpy( np[i].blogName, bp->blogName );
                strcpy( np[i].blogURL,  bp->blogURL );
                strcpy( np[i].feedURL,  bp->feedURL );
                np[i].numOfPingSite = bp->numOfPingSite;
                np[i].pingSiteList  = bp->pingSiteList;
            }
            delete [] m_blogListing;
            m_blogListing = np;
        }

        bp = &(m_blogListing[m_numberOfBlog]);
        strcpy( bp->blogName, dlgBlogSetting.m_blogName );
        strcpy( bp->blogURL,  dlgBlogSetting.m_blogURL  );
        strcpy( bp->feedURL,  dlgBlogSetting.m_feedURL  );
        InitPingSiteList( bp );

        m_blogList.AddString( dlgBlogSetting.m_blogName );

        m_numberOfBlog++;
        WriteSetting();
    }
}

void CAnewexDlg::OnVersion() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CAnewexDlg::OnAddPingsite() 
{
    if ( m_numberOfPingSite > MAX_NUM_OF_PINGSITE )
        return;

    int                 ret;
    BLOGLIST            *bp;
    PINGSITELIST        *pp, *plp;
	CInputPingSiteURL   dlgInputPingSite;

    dlgInputPingSite.m_pingSiteURL  = "http://";
    dlgInputPingSite.m_pingSiteName = "";
    dlgInputPingSite.m_pingType     = PING_TYPE_NORMAL;
    dlgInputPingSite.m_mode         = false; // �ǉ�
	ret = dlgInputPingSite.DoModal();

    if ( ret == IDOK ) {
        int length = dlgInputPingSite.m_pingSiteURL.GetLength();

        if ( length >= 8 ) {
            plp = &(m_pingSiteListing[m_numberOfPingSite]);
            strcpy( plp->siteURL,  dlgInputPingSite.m_pingSiteURL );
            if ( dlgInputPingSite.m_pingSiteName.GetLength() > 0 )
                strcpy( plp->siteName, dlgInputPingSite.m_pingSiteName );
            else
                strcpy( plp->siteName, dlgInputPingSite.m_pingSiteURL );
            plp->pingType = dlgInputPingSite.m_pingType;

            CButton *p = (CButton *)GetDlgItem( plp->ctrlID );
         // p->SetWindowText( plp->siteURL );
            p->SetWindowText( plp->siteName );
            p->EnableWindow( TRUE );

            int i;
            for ( i = 0; i < m_numberOfBlog; i++ ) {
                bp = &(m_blogListing[i]);
                pp = &(bp->pingSiteList[m_numberOfPingSite]);
                bp->numOfPingSite = m_numberOfPingSite + 1;
                pp->ctrlID   = m_pingSiteListing[m_numberOfPingSite].ctrlID;
                pp->isTarget = false;
                pp->sendTime = 0;
                strcpy( pp->siteURL,  dlgInputPingSite.m_pingSiteURL );
                if ( dlgInputPingSite.m_pingSiteName.GetLength() > 0 )
                    strcpy( pp->siteName, dlgInputPingSite.m_pingSiteName );
                else
                    strcpy( pp->siteName, dlgInputPingSite.m_pingSiteURL );
                pp->pingType = dlgInputPingSite.m_pingType;
            }

            m_numberOfPingSite++;

            CButton *cbp = (CButton *)GetDlgItem( IDC_ADD_PINGSITE );
            if ( m_numberOfPingSite >= MAX_NUM_OF_PINGSITE )
                cbp->EnableWindow( FALSE );

            WriteSetting();
        }
    }
}

void CAnewexDlg::OnRadioWeblogscom() 
{
    SetCheck( IDC_RADIO_WEBLOGSCOM, PINGSITE_ID_WEBLOGSCOM );
}

void CAnewexDlg::OnRadioBloggersjp() 
{
    SetCheck( IDC_RADIO_BLOGGERSJP, PINGSITE_ID_BLOGGERSJP );
}

void CAnewexDlg::OnRadioBlogpeople() 
{
    SetCheck( IDC_RADIO_BLOGPEOPLE, PINGSITE_ID_BLOGPEOPLE );
}

void CAnewexDlg::OnRadioMyblog() 
{
    SetCheck( IDC_RADIO_MYBLOG, PINGSITE_ID_MYBLOG );
}

void CAnewexDlg::OnRadioTechnorati() 
{
    SetCheck( IDC_RADIO_TECHNORATI, PINGSITE_ID_TECHNORATI );
}

void CAnewexDlg::OnRadioBulkfeeds() 
{
    SetCheck( IDC_RADIO_BULKFEEDS, PINGSITE_ID_BULKFEEDS );
}

void CAnewexDlg::OnRadioGoo() 
{
    SetCheck( IDC_RADIO_GOO, PINGSITE_ID_GOOBLOG );
}

void CAnewexDlg::OnRadioGoogle() 
{
    SetCheck( IDC_RADIO_GOOGLE, PINGSITE_ID_GOOGLE );
}

void CAnewexDlg::OnRadioPingsite001() 
{
    SetCheck( IDC_RADIO_PINGSITE_001, PINGSITE_ID_A001 );
}

void CAnewexDlg::OnRadioPingsite002() 
{
    SetCheck( IDC_RADIO_PINGSITE_002, PINGSITE_ID_A002 );
}

void CAnewexDlg::OnRadioPingsite003() 
{
    SetCheck( IDC_RADIO_PINGSITE_003, PINGSITE_ID_A003 );
}

void CAnewexDlg::OnRadioPingsite004() 
{
    SetCheck( IDC_RADIO_PINGSITE_004, PINGSITE_ID_A004 );
}

void CAnewexDlg::OnRadioPingsite005() 
{
    SetCheck( IDC_RADIO_PINGSITE_005, PINGSITE_ID_A005 );
}

void CAnewexDlg::OnRadioPingsite006() 
{
    SetCheck( IDC_RADIO_PINGSITE_006, PINGSITE_ID_A006 );
}

void CAnewexDlg::OnRadioPingsite007() 
{
    SetCheck( IDC_RADIO_PINGSITE_007, PINGSITE_ID_A007 );
}

void CAnewexDlg::OnRadioPingsite008() 
{
    SetCheck( IDC_RADIO_PINGSITE_008, PINGSITE_ID_A008 );
}

void CAnewexDlg::OnRadioPingsite009() 
{
    SetCheck( IDC_RADIO_PINGSITE_009, PINGSITE_ID_A009 );
}

void CAnewexDlg::OnRadioPingsite010() 
{
    SetCheck( IDC_RADIO_PINGSITE_010, PINGSITE_ID_A010 );
}

void CAnewexDlg::OnRadioPingsite011() 
{
    SetCheck( IDC_RADIO_PINGSITE_011, PINGSITE_ID_A011 );
}

void CAnewexDlg::OnRadioPingsite012() 
{
    SetCheck( IDC_RADIO_PINGSITE_012, PINGSITE_ID_A012 );
}

void CAnewexDlg::OnRadioPingsite013() 
{
    SetCheck( IDC_RADIO_PINGSITE_013, PINGSITE_ID_A013 );
}

void CAnewexDlg::OnRadioPingsite014() 
{
    SetCheck( IDC_RADIO_PINGSITE_014, PINGSITE_ID_A014 );
}

void CAnewexDlg::OnPing() 
{
    if ( !m_targetBlog )
        return;

    CButton *cbp = (CButton *)GetDlgItem( IDC_PING );
    cbp->EnableWindow( FALSE );

    CString             msg = _T( "" );
    time_t              t = time( NULL );
    BOOL                ret;
    SendingPingDialog   *dialog;
    dialog = new SendingPingDialog();
    dialog->Create( IDD_DIALOG_SENDING );

    if ( m_useProxy ) {
        setProxyInfo( m_proxyURL,
                      (unsigned short)m_proxyPort,
                      m_proxyUsername,
                      m_proxyPassword );
    }
    setUseProxy( m_useProxy );

    int i;
    for ( i = 0; i < m_targetBlog->numOfPingSite; i++ ) {
        if ( m_targetBlog->pingSiteList[i].isTarget ) {
            if ( t - m_targetBlog->pingSiteList[i].sendTime >= 30 * 60 ) {
                // �O��� ping ���M���� 30���ȏ�o�߂��Ă���ꍇ
                //   ���Y ping �T�C�g�ɍX�V ping �𑗐M
	            CString text;
	            text.LoadString( IDS_SENDING_PING );
                dialog->ChangeDialogText(
                            m_targetBlog->pingSiteList[i].siteName,
                            text ); // ping ���M�� �c�c

                CWaitCursor cur;    // �}�E�X�J�[�\���������v�\��
                setTargetURL( m_targetBlog->pingSiteList[i].siteURL );
             // if ( !strncmp( m_targetBlog->pingSiteList[i].siteURL,
             //                "http://blogsearch.google.com/", 29 ) ) {
                if ( m_targetBlog->pingSiteList[i].pingType ==
                                                    PING_TYPE_EXTENDED ) {
                    if ( m_targetBlog->feedURL[0] == NUL ) {
                        char    *p;

                        p = getRssUrlOnBulkfeeds( m_targetBlog->blogURL, NULL );
                        if ( p && *p )
                            strcpy( m_targetBlog->feedURL, p );
                    }
                    ret = sendUpdateExtendedPing( m_targetBlog->blogName,
                                                  m_targetBlog->blogURL,
                                                  m_targetBlog->blogURL,
                                                  m_targetBlog->feedURL );
                }
                else
                    ret = sendUpdatePing( m_targetBlog->blogName,
                                          m_targetBlog->blogURL );

                CAnewexApp  *pp = (CAnewexApp *)AfxGetApp();
                if ( pp->m_langCode == 0x0411 ) {
                    // ���{�ꃂ�[�h�̏ꍇ
                    msg += m_targetBlog->pingSiteList[i].siteName;
                    msg += " �ւ� ping �̑��M";
                    if ( ret == TRUE )
                        msg += "����  \r\n";
                    else
                        msg += "���s  \r\n";
                }
                else {
                    // �p�ꃂ�[�h�̏ꍇ
                    if ( ret == TRUE )
                        msg += "Transmission success in";
                    else
                        msg += "Transmission failure of";
                    msg += " ping message in ";
                    msg += m_targetBlog->pingSiteList[i].siteName;
                    msg += "  \r\n";
                }

                if ( ret == TRUE )  // ���������Ƃ������X�V
                    m_targetBlog->pingSiteList[i].sendTime = t;
            }
        }
    }

	CString title;
	CString text;
	title.LoadString( IDS_SENT_PING );
	text.LoadString(  IDS_RECORDING_RESULT );
    dialog->ChangeDialogText( title,    // ping ���M
                              text   ); // ���M���ʔ��f�� �c�c
    WriteSetting();

    dialog->DestroyWindow();
    delete dialog;

	title.LoadString( IDS_RESULT );
    if ( msg != _T( "" ) )
        ::MessageBox( NULL,
                      (const char *)msg,
                      title,    // ping ���M����
                      MB_OK|MB_ICONINFORMATION );
    else {
    	text.LoadString( IDS_NO_PINGSITE );
        ::MessageBox( NULL,
                      text,     // ping ���M����K�v�̂���T�C�g�͌�����܂���ł����B
                      title,    // ping ���M����
                      MB_OK|MB_ICONINFORMATION );
    }

    cbp->EnableWindow( TRUE );
}

void CAnewexDlg::OnSelchangeCombo() 
{
    CString         blogName;
    CButton         *p;
    int             id;
    PINGSITELIST    *pp;

    id = m_blogList.GetCurSel();
    m_blogList.GetLBText( id, blogName );

    int i;
    for ( i = 0; i < m_numberOfBlog; i++ ) {
        if ( !strcmp( m_blogListing[i].blogName, blogName ) ) {
            m_targetBlog = &(m_blogListing[i]);

            int j;
            for ( j = 0; j < m_numberOfPingSite; j++ ) {
                pp = &(m_targetBlog->pingSiteList[j]);
                p = (CButton *)GetDlgItem( pp->ctrlID );
                if ( p ) {
                    p->EnableWindow( TRUE );
                    p->SetCheck( pp->isTarget );
                }
            }
            for ( ; j < MAX_NUM_OF_PINGSITE; j++ ) {
                pp = &(m_targetBlog->pingSiteList[j]);
                p = (CButton *)GetDlgItem( pp->ctrlID );
                if ( p ) {
                    p->EnableWindow( FALSE );
                    p->SetCheck( FALSE );
                }
            }
            break;
        }
    }
}


void CAnewexDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    static bool initialized = false;
    if ( bShow ) {
        CButton *p;
        int     i;
        for ( i = 0; i < m_numberOfBlog; i++ )
            m_blogList.AddString( m_blogListing[i].blogName );
        for ( i = 0 /* NUM_OF_INITIAL_PINGSITE */; i < m_numberOfPingSite; i++ ) {
            p = (CButton *)GetDlgItem( m_pingSiteListing[i].ctrlID );
         // p->SetWindowText( m_pingSiteListing[i].siteURL );
            p->SetWindowText( m_pingSiteListing[i].siteName );
        }

        p = (CButton *)GetDlgItem( IDC_BUTTONPROXY );
        if ( !m_useProxy ) {
            p->EnableWindow( FALSE );
        }
        else {
            p->EnableWindow( TRUE );
            p = (CButton *)GetDlgItem( IDC_CHECKPROXY );
            p->SetCheck( 1 );
        }

        if ( m_numberOfPingSite >= MAX_NUM_OF_PINGSITE ) {
            CButton *cbp = (CButton *)GetDlgItem( IDC_ADD_PINGSITE );
            cbp->EnableWindow( FALSE );
        }

        initialized = true;
    }
}

void CAnewexDlg::OnOK() 
{
	if ( m_changed )
        WriteSetting();

	CDialog::OnOK();
}

void CAnewexDlg::OnDoubleclickedRadioPingsite001() 
{
    EditPingSite( PINGSITE_ID_A001 );
}

void CAnewexDlg::OnDoubleclickedRadioPingsite002() 
{
    EditPingSite( PINGSITE_ID_A002 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite003() 
{
    EditPingSite( PINGSITE_ID_A003 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite004() 
{
    EditPingSite( PINGSITE_ID_A004 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite005() 
{
    EditPingSite( PINGSITE_ID_A005 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite006() 
{
    EditPingSite( PINGSITE_ID_A006 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite007() 
{
    EditPingSite( PINGSITE_ID_A007 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite008() 
{
    EditPingSite( PINGSITE_ID_A008 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite009() 
{
    EditPingSite( PINGSITE_ID_A009 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite010() 
{
    EditPingSite( PINGSITE_ID_A010 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite011() 
{
    EditPingSite( PINGSITE_ID_A011 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite012() 
{
    EditPingSite( PINGSITE_ID_A012 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite013() 
{
    EditPingSite( PINGSITE_ID_A013 );	
}

void CAnewexDlg::OnDoubleclickedRadioPingsite014() 
{
    EditPingSite( PINGSITE_ID_A014 );	
}

void CAnewexDlg::OnCheckproxy() 
{
    CButton *p = (CButton *)GetDlgItem( IDC_BUTTONPROXY );
    switch ( m_useProxy ) {
    case FALSE:
        m_useProxy = TRUE;
        p->EnableWindow( TRUE );
        WriteProxyTxt();
        break;
    default:
        m_useProxy = FALSE;
        p->EnableWindow( FALSE );
        DeleteProxyTxt();
        break;
    }
}

void CAnewexDlg::OnButtonproxy() 
{
    if ( !m_useProxy )
        return;

    int                 ret;
    int                 proxyPort = 0;
    char                proxyURL[MAX_PATH];
    char                proxyUsername[MAX_USERIDLEN];
    char                proxyPassword[MAX_USERIDLEN];
	CProxySettingDialog dlgProxySetting;

    proxyUsername[0] = NUL;
    proxyPassword[0] = NUL;

    // proxy ���擾
    GetProxyInfo( proxyURL, proxyPort, proxyUsername, proxyPassword );
    if ( (m_proxyPort == 0) && (m_proxyURL[0] == NUL) ) {
        if ( proxyPort > 0 ) {
            m_proxyPort = proxyPort;
            strcpy( m_proxyURL, proxyURL );
            if ( proxyUsername[0] ) {
                strcpy( m_proxyUsername, proxyUsername );
                if ( proxyPassword[0] )
                    strcpy( m_proxyPassword, proxyPassword );
            }
        }
    }

    dlgProxySetting.m_proxyPort     = m_proxyPort;
    dlgProxySetting.m_proxyURL      = m_proxyURL;
    dlgProxySetting.m_proxyUsername = m_proxyUsername;
    dlgProxySetting.m_proxyPassword = m_proxyPassword;

	ret = dlgProxySetting.DoModal();
    if ( (ret == IDOK)                      &&
         (dlgProxySetting.m_proxyPort > 0)  &&
         (dlgProxySetting.m_proxyURL != "")    ) {
        m_proxyPort = dlgProxySetting.m_proxyPort;
        strcpy( m_proxyURL, dlgProxySetting.m_proxyURL );
        if ( dlgProxySetting.m_proxyUsername != "" ) {
            strcpy( m_proxyUsername, dlgProxySetting.m_proxyUsername );
            if ( dlgProxySetting.m_proxyPassword != "" )
                strcpy( m_proxyPassword, dlgProxySetting.m_proxyPassword );
        }
        if ( (proxyPort != m_proxyPort)                    ||
             (strcmp(proxyURL, m_proxyURL) != 0)           ||
             (strcmp(proxyUsername, m_proxyUsername) != 0) ||
             (strcmp(proxyPassword, m_proxyPassword) != 0)    )
            WriteProxyTxt();
        else
            DeleteProxyTxt();
        WriteSetting();
    }
}
