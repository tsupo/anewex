/*
 *  anewexStruct.h
 *
 * History:
 * $Log: /comm/anewex/anewexStruct.h $
 * 
 * 1     09/05/14 3:29 tsupo
 * (1) ビルド環境のディレクトリ構造を整理
 * (2) VSSサーバ拠点を変更
 * 
 * 7     07/01/09 17:14 Tsujimura543
 * 英語版対応作業、完了
 * 
 * 6     07/01/05 22:34 Tsujimura543
 * ココログのpingサーバサービス終了のため、代わりに technorati を
 * 新たなpingサーバとして使用するように変更した
 * 
 * 5     06/10/25 20:49 Tsujimura543
 * (1) ping種別を指定できるようにした
 * (2) ping サイトのURLではなく、ping
 * サイト名称を優先的に表示するようにした
 * 
 * 4     06/10/20 2:08 Tsujimura543
 * (1) 「Google ブログ検索」に対応した
 * (2) pingサーバの登録数上限を5個増やした
 * 
 * 3     04/09/01 10:26 Tsujimura543
 * technorati と blo.gs に関する情報をコメントの形で掲載
 * 
 * 2     04/07/07 12:05 Tsujimura543
 */

#ifndef __ANEWEX_STRUCT_H__
#define __ANEWEX_STRUCT_H__

#include <time.h>

#define MAX_BLOGNAME    80
#define MAX_SITENAME    128

// ping 種別
#define PING_TYPE_NORMAL    1   // weblogUpdates.ping
#define PING_TYPE_EXTENDED  2   // weblogUpdates.extendedPing

// ping サイト一覧
typedef struct pingSiteList {
    int     ctrlID;                 // コントロールID
    char    siteName[MAX_SITENAME]; // ping サイト名
    char    siteURL[MAX_PATH];      // ping 送信先 URL
    bool    isTarget;               // ping 送信先として採用するか否か
    int     pingType;               // ping 種別 (ping / extendedPing)
    time_t  sendTime;               // 前回の ping 送信時刻
}   PINGSITELIST;


// ping を飛ばしたい blog の一覧
typedef struct blogList {
    char            blogName[MAX_BLOGNAME]; // blog 名
    char            blogURL[MAX_PATH];      // blog URL
    char            feedURL[MAX_PATH];      // feed URL
    PINGSITELIST    *pingSiteList;          // ping を飛ばしたいサイト一覧
    int             numOfPingSite;          // ping を飛ばしたいサイトの数
}   BLOGLIST;


#define NUM_OF_INITIAL_PINGSITE     8       // 登録済み ping サイト数
#define MAX_NUM_OF_ADDED_PINGSITE   14      // 登録可能 ping サイト数
#define MAX_NUM_OF_PINGSITE         \
            (NUM_OF_INITIAL_PINGSITE + MAX_NUM_OF_ADDED_PINGSITE)
                                            // 取り扱い ping サイト最大数

// 登録済み ping サイト
#define PINGSITE_ID_WEBLOGSCOM      0       // rpc.weblogs.com
#define PINGSITE_ID_BLOGGERSJP      1       // ping.bloggers.jp
#define PINGSITE_ID_BLOGPEOPLE      2       // BlogPeople
#define PINGSITE_ID_MYBLOG          3       // MyBlog
#define PINGSITE_ID_TECHNORATI      4       // technorati
#define PINGSITE_ID_BULKFEEDS       5       // bulkfeeds
#define PINGSITE_ID_GOOBLOG         6       // goo BLOG
#define PINGSITE_ID_GOOGLE          7       // Google Blog Search

// 登録可能 ping サイト
#define PINGSITE_ID_A001            8       // 追加 ping サイト #001
#define PINGSITE_ID_A002            9       // 追加 ping サイト #002
#define PINGSITE_ID_A003            10      // 追加 ping サイト #003
#define PINGSITE_ID_A004            11      // 追加 ping サイト #004
#define PINGSITE_ID_A005            12      // 追加 ping サイト #005
#define PINGSITE_ID_A006            13      // 追加 ping サイト #006
#define PINGSITE_ID_A007            14      // 追加 ping サイト #007
#define PINGSITE_ID_A008            15      // 追加 ping サイト #008
#define PINGSITE_ID_A009            16      // 追加 ping サイト #009
#define PINGSITE_ID_A010            17      // 追加 ping サイト #010
#define PINGSITE_ID_A011            18      // 追加 ping サイト #011
#define PINGSITE_ID_A012            19      // 追加 ping サイト #012
#define PINGSITE_ID_A013            20      // 追加 ping サイト #013
#define PINGSITE_ID_A014            21      // 追加 ping サイト #014

// 追加 ping サイトの候補
//  blo.gs
//      http://ping.blo.gs/     (UTF-8 が使用可能な海外pingサイト)
//          詳細は http://blo.gs/ping-example.php 参照


// 初期設定ファイル関連
#define INIT_FILENAME       "anewex.inf"    // 初期設定ファイル名
#define PROXY_FILENAME      "proxy.txt"     // proxy 情報ファイル

// 初期設定ファイルフォーマット
/*
 * ping を飛ばしたい blog の数
 * [-- ↓↓↓ ping を飛ばしたい blog の数 の分だけ       ↓↓↓ --]
 *   ping を飛ばしたい blog の名前 (ping発信元)
 *   ping を飛ばしたい blog のURL  (ping発信元)
 * 
 *   ping を飛ばしたい ping サイトの数
 *   [---- ↓ ping を飛ばしたい ping サイトの数 の分だけ ↓ ----]
 *     ping を飛ばしたい ping サイトの名前 (ping発信先)
 *     ping を飛ばしたい ping サイトのURL  (ping発信先)
 *     当該 ping サイトに実際に ping を飛ばすか否か
 *     当該 ping サイトに最後に ping を飛ばした時刻
 *   [---- ↑ ping を飛ばしたい ping サイトの数 の分だけ ↑ ----]
 * 
 * [-- ↑↑↑ ping を飛ばしたい blog の数 の分だけ       ↑↑↑ --]
 */

#endif  /* __ANEWEX_STRUCT_H__ */
