#include "pole.h"

pole::pole()
{
	imyapolya = "";
};

void pole::chistka() //������ ����
{
	int i, j;//���������� ��������
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			pol[i][j].setklet(PUST);
		}
	}
};