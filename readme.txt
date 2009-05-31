anewex -- weblogUpdates.ping(更新ping)をpingサイトに送信するプログラム
  作者: tsupo (H.Tsujimura,  mailto: tsupo@na.rim.or.jp)
  パッケージ作成日: 2009年3月31日
  パッケージ版数:   1.50

  このパッケージの説明:

    このパッケージには、以下のファイルが含まれています。

      readme.txt      いま、あなたが読んでいるファイル
      anewex.exe      更新pingをpingサイトに送信するプログラム
      xmlRPC.dll      上記のプログラムを動かすのに必要なモジュール (サーバとの通信用)
      iconv.dll       同上 (文字コードの変換用) [このファイルの配布は GNU LGPL に従います]

      anewex.exe.manifest
                      anewex.exe を Windows XP 以降で動かす場合に参照するファイル
                      (ただし、Windows をクラシック設定にしている場合は、Windows XP 以降の
                       場合でも参照されません)

      iconv-1.9.1.win32 以下のファイル
        Windows 用 の GNU iconv ライブラリ のバイナリパッケージ
        (GNU LIBRARY GENERAL PUBLIC LICENSE に基づく配布です)

      src 以下のファイル
        anewex.exe のソースファイル
        (xmlRPC.dll のソースファイルは今回の配布対象には入れていません)

  配布条件:
    iconv.dll および iconv-1.9.1.win32 以下のファイル は、GNU LIBRARY GENERAL PUBLIC LICENSE にしたがいます。
    それ以外のファイル(anewex.exe, xmlRPC.dll, および ドキュメント)は、tsupo の著作物です。
    配布は自由としますが、プログラムの動作および動作に伴い発生する諸々の事象に関しては無保証とします。

    なお、https 対応にあたり、xmlRPC.dll に OpenSSL のスタティックライブラリを組み込んでいます。
    OpenSSL については http://www.openssl.org/ を参照してください。また、OpenSSL のライセンスに関しては
    http://www.openssl.org/contrib/ を参照してください。

    書籍、雑誌等で本ツールの紹介を行なったり、本パッケージを収録したりする場合は、事前に連絡してください。

  動作環境:
    Windows 95,98,98SE,ME (Windows 95A 以降、できれば Windows 95 OSR2.0 以降推奨)
    Windows NT4.0SP6a, 2000, XP
    Windows Server 2000, Windows 2003 Server
    (proxy 経由で使う場合は、IE4.0 以降がインストール済みであることを推奨)
   ※ パーソナルファイアウォールを使用している場合は、別途、ファイアウォールの調整が
      必要な場合があります

  インストール:
    本アーカイブに収録されている anewex.exe, xmlRPC.dll, iconv.dll を同一のディレクトリ
    (フォルダ)に解凍し、ご利用ください。特に、必要な作業はありません。

  アンインストール:
    anewex.exe, xmlRPC.dll, iconv.dll を削除するだけです。レジストリはいじっていません。

  使い方:
    anewex.exe
      アイコンをダブルクリック、または、DOSプロンプトから anewex [Enter] で起動します。
      まず、「設定」ボタンを押して、blog を登録してください。
      登録が終わったら、ping 対象の blog と、ping 送信先をそれぞれ選択し、「PING送信」ボタンを押せば、
      更新pingが送信されます。
      ただし、短時間に連続して ping を送信すると ping サーバに迷惑をかけるため、一定時間経過するまで
      次の ping は送信しないようになっています。

      なお、本ツールによる各種設定内容は anewex.inf という名前のファイルに保存されます。いったん設定
      を完全にクリアしたい場合は、anewex.inf を削除した後、本ツールを起動してください。

  バグ報告:
    このパッケージに含まれるプログラムの動作異常等、不具合を発見された方は、できるだけ詳細な報告を
      tsupo@na.rim.or.jp
    まで、電子メイルにて送付していただけると幸いです。

  サポート情報、1次配布元:
    本パッケージは、以下の URL にて配布しています。
        http://watcher.moe-nifty.com/memo/files/anewex148.lzh
    以下の Webページに関連情報があります。
        http://watcher.moe-nifty.com/memo/2004/09/anewex.html

  関連情報:
     Tsuporone's Program Library
        http://www.na.rim.or.jp/~tsupo/program/
     send an update ping to the ping-site (using HTTP POST method; source code only)
        http://www.na.rim.or.jp/~tsupo/program/blogTool/httpPost.c

  更新情報:
    Ver 1.50  2009年 3月23日  同梱の xmlRPC.dll に込みこんでいる OpenSSL を 0.9.8k 版に入れ替えた
    Ver 1.49  2009年 3月23日  同梱の xmlRPC.dll に込みこんでいる OpenSSL を 0.9.8j 版に入れ替えた
    Ver 1.48  2008年 8月21日  下5つ(上から数えて18番目～22番目)の ping サイトのラジオボタンをクリッ
                              クしても on/off 状態が変化しない不具合を修正 (1.40版以降で発生して
                              いる不具合)
   (Ver 1.47) 2008年 2月27日  同梱している xmlRPC.dll を新しい版に入れ替えた。anewex.exe 自体は特
                              にいじっていない
   (Ver 1.47) 2008年 2月12日  同梱している xmlRPC.dll を新しい版に入れ替えた。anewex.exe 自体は特
                              にいじっていない
    Ver 1.47  2008年 2月 7日  「インターネット利用形態確認」ダイアログに対して no と答えても、再
                              度、「インターネット利用形態確認」ダイアログが表示されてしまう現象
                              に対処 (proxy の設定状況により、この現象が発生することがあった)
    Ver 1.46  2007年12月25日  (1) 初回起動時に proxy 関連の設定のみ行なって終了したとき、次回起動
                                  時に proxy の設定が消えてしまう(初期状態に戻ってしまう)不具合に
                                  対処した
                              (2) 起動時の proxy 使用有無確認方法を、「proxy設定」ボタン押下時の
                                  処理と同じやり方に統一した
   (Ver 1.45) 2007年12月 6日  同梱している xmlRPC.dll を新しい版に入れ替えた。anewex.exe 自体は特
                              にいじっていない
   (Ver 1.45) 2007年11月30日  新たに anewex.exe.manifest を同梱することにした
    Ver 1.45  2007年11月21日  同梱の xmlRPC.dll に込みこんでいる OpenSSL を 0.9.8g 版に入れ替えた
    Ver 1.44  2007年11月16日  メインダイアログに最小化ボタンをつけた (+ 同梱の xmlRPC.dll を新しい
                              版に入れ替えた)
    Ver 1.43  2007年 7月23日  利用するにあたって、ユーザ名とパスワードの指定が必要なプロキシサーバ
                              経由での ping 送信にも対応した (ユーザ名とパスワードは「proxy設定」ボ
                              タンを押したときに表示されるダイアログにて設定可能)
    Ver 1.42  2007年 1月11日  (1) 2006年11月21日午前10時をもって運用を終了したココログpingサーバの
                                  代わりに、新たに technorati の ping サーバを初期設定済み ping サー
                                  バにした
                              (2) 日本語版以外の Windows 上で起動した場合は、英語モードで動作するよ
                                  うにした
    Ver 1.41a 2007年 1月 4日  (1) 同梱の xmlRPC.dll に組み込んでいる OpenSSL を 0.9.8d に入れ替えた
                              (2) バージョン情報表示ダイアログから、サポート用Webページに飛べるよう
                                  にした
   (Ver 1.41) 2006年12月12日  同梱の xmlRPC.dll を新しい版に入れ替えたのに伴い、リビルドし直した。
                              ソースの変更は行なっていない
    Ver 1.41  2006年10月25日  (1) 追加登録する(した)pingサイトに関して、更新pingの種類(従来通り
                                  weblogUpdates.pingを使うか、あるいは Google ブログ検索と同様に
                                  weblogUpdates.extendedPing を使うか)を指定できるようにした
                              (2) メインダイアログでは、pingサイトのURLではなく、pingサイト名称
                                  を表示するようにした
    Ver 1.40  2006年10月20日  (1) 「Google ブログ検索」への ping 送信(weblogUpdates.extendedPing)
                                  に対応した
                              (2) ping サイトの登録可能最大数を5個増やした(最初から登録済みの8個、
                                  ユーザの方で追加登録可能なもの14個の合計22個のpingサイトに対応可
                                  能になった)
    Ver 1.31  2006年10月10日  (1) goo の ping サイトがメンテナンス中の場合に anewex.exe が異常終了
                                  することがある不具合に対処した
                              (2) xmlRPC.dll に組み込む OpenSSL の版を 0.9.8c にアップデートした
    Ver 1.30  2005年12月13日  (1) 「MyBlog」が「ドリコムRSS」に移行したのに伴い、初期設定済み ping 
                                  サイト情報を更新した
                              (2) 上記に伴い、初期設定ファイル中の「MyBlog」関連情報を「ドリコムRSS」
                                  のものに書き換えるようにした
                              (3) ping サイトを登録可能最大数(16サイト)まで登録すると、次回起動時に
                                  登録したはずの ping サイトが表示されない(設定ファイルには情報が残っ
                                  ている)現象に対処した
                              (4) ping サイト情報編集用のダイアログで、ping サイトの URL 欄を空のま
                                  ま OK ボタンを押したとき、当該 ping サイトを登録抹消するようにした
                                  (登録抹消機能を実装した)
    Ver 1.22  2005年11月15日  (1) ping 送信中に表示するダイアログのタイトルに、ping送信先を表示する
                                  ようにした。
                              (2) xmlRPC.dll に組み込む OpenSSL の版を 0.9.8a にアップデートした。
    Ver 1.21  2005年 9月 3日  同梱の xmlRPC.dll を新しい版に入れ替えたのに伴い、リビルドし直した。
                              ソースの変更は行なっていない
    Ver 1.20  2005年 6月21日  ping 送信中は砂時計カーソルを表示するようにした
   (Ver 1.10) 2005年 2月18日  同梱の xmlRPC.dll を新しい版に入れ替えたのに伴い、リビルドし直した。
                              ソースの変更は行なっていない
    Ver 1.10  2005年 1月 7日  (1) 「ping 送信中」であることを表示するダイアログ、ping 送信結果を表示
                                  するダイアログの2つを追加
                              (2) https:// で始まる URL の ping サイトへの ping 送信にも対応
    Ver 1.00  2004年 9月 1日  最初の版 「観測気球」にて公開

$Header: /comm/anewex/readme.txt 1     09/05/14 3:29 tsupo $
