//=================================================
//
//�I�����C�����p�Z�p�`�X���b�h�`[main.cpp]
//Author:KishimotoEiji
//
//=================================================
//*******************************
//�C���N���[�h
//*******************************
#include <stdio.h>
#include <thread>

//*******************************
//�萔�̒�`
//*******************************
namespace
{
const int MAX_COUNT = 5;	//�J�E���g�̍ő吔
}//namespace�͂����܂�

//=================================================
//�X���b�h�v���V�[�W��
//=================================================
void ThreadProc(const int &nMaxCnt, const int &nWaitMillSec)
{
	for (int i = 0; i < nMaxCnt; i++)
	{
		printf("\n [ �J�E���g : %d ]", i);	//�\��
		std::this_thread::sleep_for(std::chrono::milliseconds(nWaitMillSec));
	}
}

//=================================================
//���C���֐�
//=================================================
int main()
{
	//�X���b�h�̍쐬
	std::thread th(ThreadProc,MAX_COUNT,1000);

	//�X���b�h��؂藣��
	th.detach();

	//�X���b�h�̏I����҂�
	//th.join();

	//Enter���͑҂�
	rewind(stdin);
	getchar();

	return 0;
}