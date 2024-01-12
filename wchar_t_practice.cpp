#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

using namespace std;

int main() {
    // これによりPC環境のデフォルトの言語設定として各処理がされるようになる。
    // wchar_t（ワイド文字列　2バイト固定長）を扱う使用準備。
    if (setlocale(LC_CTYPE, "") == NULL) {
        fputs("ロケールの設定に失敗しました。\n", stderr);
        return EXIT_FAILURE;
    }

    // charでは全角文字列を完全に扱うことができない。
    // charでは"あいう"ではstrlenは6を返すなどなっていまう。
    // その場合はwchar_t型を使用した文字列操作を行う。デメリットはサイズが単純に大きくなる。

    // ２バイト固定長（ワイド文字列）の表示
    wchar_t str[] = L"日本語サンプルA";        // 文字列リテラルはLをプレフィックスとしてつける
    wprintf(L"%s\n", str);                      // ワイド文字列専用の関数を利用する
    wprintf(L"1文字目: %c\n", str[0]);
    wprintf(L"文字の長さ: %d\n", (unsigned int)wcslen(str));

    ////// ２バイト固定長での入力を試す。
    cout << "日本語・英単語入力せよ！" << endl;
    wchar_t iStr[128];
    wcin >> iStr;
    wcout << iStr << endl;
    cout << wcslen(iStr);


    //char <--> wchar_t 変換
    //mbstowcs関数 や wcstombs関数を駆使する。
    //stringもwstringがあるのです。
}
