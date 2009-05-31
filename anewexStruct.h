/*
 *  anewexStruct.h
 *
 * History:
 * $Log: /comm/anewex/anewexStruct.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 7     07/01/09 17:14 Tsujimura543
 * �p��őΉ���ƁA����
 * 
 * 6     07/01/05 22:34 Tsujimura543
 * �R�R���O��ping�T�[�o�T�[�r�X�I���̂��߁A����� technorati ��
 * �V����ping�T�[�o�Ƃ��Ďg�p����悤�ɕύX����
 * 
 * 5     06/10/25 20:49 Tsujimura543
 * (1) ping��ʂ��w��ł���悤�ɂ���
 * (2) ping �T�C�g��URL�ł͂Ȃ��Aping
 * �T�C�g���̂�D��I�ɕ\������悤�ɂ���
 * 
 * 4     06/10/20 2:08 Tsujimura543
 * (1) �uGoogle �u���O�����v�ɑΉ�����
 * (2) ping�T�[�o�̓o�^�������5���₵��
 * 
 * 3     04/09/01 10:26 Tsujimura543
 * technorati �� blo.gs �Ɋւ�������R�����g�̌`�Ōf��
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */

#ifndef __ANEWEX_STRUCT_H__
#define __ANEWEX_STRUCT_H__

#include <time.h>

#define MAX_BLOGNAME    80
#define MAX_SITENAME    128

// ping ���
#define PING_TYPE_NORMAL    1   // weblogUpdates.ping
#define PING_TYPE_EXTENDED  2   // weblogUpdates.extendedPing

// ping �T�C�g�ꗗ
typedef struct pingSiteList {
    int     ctrlID;                 // �R���g���[��ID
    char    siteName[MAX_SITENAME]; // ping �T�C�g��
    char    siteURL[MAX_PATH];      // ping ���M�� URL
    bool    isTarget;               // ping ���M��Ƃ��č̗p���邩�ۂ�
    int     pingType;               // ping ��� (ping / extendedPing)
    time_t  sendTime;               // �O��� ping ���M����
}   PINGSITELIST;


// ping ���΂����� blog �̈ꗗ
typedef struct blogList {
    char            blogName[MAX_BLOGNAME]; // blog ��
    char            blogURL[MAX_PATH];      // blog URL
    char            feedURL[MAX_PATH];      // feed URL
    PINGSITELIST    *pingSiteList;          // ping ���΂������T�C�g�ꗗ
    int             numOfPingSite;          // ping ���΂������T�C�g�̐�
}   BLOGLIST;


#define NUM_OF_INITIAL_PINGSITE     8       // �o�^�ς� ping �T�C�g��
#define MAX_NUM_OF_ADDED_PINGSITE   14      // �o�^�\ ping �T�C�g��
#define MAX_NUM_OF_PINGSITE         \
            (NUM_OF_INITIAL_PINGSITE + MAX_NUM_OF_ADDED_PINGSITE)
                                            // ��舵�� ping �T�C�g�ő吔

// �o�^�ς� ping �T�C�g
#define PINGSITE_ID_WEBLOGSCOM      0       // rpc.weblogs.com
#define PINGSITE_ID_BLOGGERSJP      1       // ping.bloggers.jp
#define PINGSITE_ID_BLOGPEOPLE      2       // BlogPeople
#define PINGSITE_ID_MYBLOG          3       // MyBlog
#define PINGSITE_ID_TECHNORATI      4       // technorati
#define PINGSITE_ID_BULKFEEDS       5       // bulkfeeds
#define PINGSITE_ID_GOOBLOG         6       // goo BLOG
#define PINGSITE_ID_GOOGLE          7       // Google Blog Search

// �o�^�\ ping �T�C�g
#define PINGSITE_ID_A001            8       // �ǉ� ping �T�C�g #001
#define PINGSITE_ID_A002            9       // �ǉ� ping �T�C�g #002
#define PINGSITE_ID_A003            10      // �ǉ� ping �T�C�g #003
#define PINGSITE_ID_A004            11      // �ǉ� ping �T�C�g #004
#define PINGSITE_ID_A005            12      // �ǉ� ping �T�C�g #005
#define PINGSITE_ID_A006            13      // �ǉ� ping �T�C�g #006
#define PINGSITE_ID_A007            14      // �ǉ� ping �T�C�g #007
#define PINGSITE_ID_A008            15      // �ǉ� ping �T�C�g #008
#define PINGSITE_ID_A009            16      // �ǉ� ping �T�C�g #009
#define PINGSITE_ID_A010            17      // �ǉ� ping �T�C�g #010
#define PINGSITE_ID_A011            18      // �ǉ� ping �T�C�g #011
#define PINGSITE_ID_A012            19      // �ǉ� ping �T�C�g #012
#define PINGSITE_ID_A013            20      // �ǉ� ping �T�C�g #013
#define PINGSITE_ID_A014            21      // �ǉ� ping �T�C�g #014

// �ǉ� ping �T�C�g�̌��
//  blo.gs
//      http://ping.blo.gs/     (UTF-8 ���g�p�\�ȊC�Oping�T�C�g)
//          �ڍׂ� http://blo.gs/ping-example.php �Q��


// �����ݒ�t�@�C���֘A
#define INIT_FILENAME       "anewex.inf"    // �����ݒ�t�@�C����
#define PROXY_FILENAME      "proxy.txt"     // proxy ���t�@�C��

// �����ݒ�t�@�C���t�H�[�}�b�g
/*
 * ping ���΂����� blog �̐�
 * [-- ������ ping ���΂����� blog �̐� �̕�����       ������ --]
 *   ping ���΂����� blog �̖��O (ping���M��)
 *   ping ���΂����� blog ��URL  (ping���M��)
 * 
 *   ping ���΂����� ping �T�C�g�̐�
 *   [---- �� ping ���΂����� ping �T�C�g�̐� �̕����� �� ----]
 *     ping ���΂����� ping �T�C�g�̖��O (ping���M��)
 *     ping ���΂����� ping �T�C�g��URL  (ping���M��)
 *     ���Y ping �T�C�g�Ɏ��ۂ� ping ���΂����ۂ�
 *     ���Y ping �T�C�g�ɍŌ�� ping ���΂�������
 *   [---- �� ping ���΂����� ping �T�C�g�̐� �̕����� �� ----]
 * 
 * [-- ������ ping ���΂����� blog �̐� �̕�����       ������ --]
 */

#endif  /* __ANEWEX_STRUCT_H__ */
