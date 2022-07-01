//=================================================
//
//オンライン利用技術～スレッド～[main.cpp]
//Author:KishimotoEiji
//
//=================================================
//*******************************
//インクルード
//*******************************
#include <stdio.h>
#include <thread>

//*******************************
//定数の定義
//*******************************
namespace
{
const int MAX_COUNT = 5;	//カウントの最大数
}//namespaceはここまで

//=================================================
//スレッドプロシージャ
//=================================================
void ThreadProc(const int &nMaxCnt, const int &nWaitMillSec)
{
	for (int i = 0; i < nMaxCnt; i++)
	{
		printf("\n [ カウント : %d ]", i);	//表示
		std::this_thread::sleep_for(std::chrono::milliseconds(nWaitMillSec));
	}
}

//=================================================
//メイン関数
//=================================================
int main()
{
	//スレッドの作成
	std::thread th(ThreadProc,MAX_COUNT,1000);

	//スレッドを切り離す
	th.detach();

	//スレッドの終了を待つ
	//th.join();

	//Enter入力待ち
	rewind(stdin);
	getchar();

	return 0;
}