#include "Igrok.h"
#include "pole.h"
Igrok::Igrok(string imya)
{
	this->imya = imya;
	int i,j;
	for (i = 0; i < N; i++) //������������� ������� ��������� ���������
	{
		for (j = 0; j < N; j++)
		{
			masproverky[i][j] = PUST;
		}
	}
};

void Igrok::vystrel(int*x, int*y, pole* doska) //��������� ���� � ������� ����� ��������
{   //�� ��������� ����� ������� ��������� ���������� � �����
	int xnach, ynach, xk[4], yk[4], napr,fdobit;
	sost resposxoda;

	if (doska->resposlxoda == "�����")
	{
		fdobit = 1;
		
	}
	
	if (fdobit == 1) //���� ������ ����� ���� ���-�� ������
	{
		/*//�������� �����������
		napr = (int)((rand() / 32767.0) * (3)) + 1; //�������� ���� �� 4-� �����������
		//������ ���� �������
		if (napr == 1)
		{
			xk = xnach + 1;
		}
		if (napr == 2)
		{
			xk = xnach - 1;
		}
		if (napr == 3)
		{
			yk = ynach + 1;
		}
		if (napr == 4)
		{
			yk = ynach - 1;
		}
		*/
	}
	else
	{
		do 
		{
			*(x) = (int)((rand() / 32767.0) * (N));
			*(y) = (int)((rand() / 32767.0) * (N));
		} 
		while (masproverky[*(x)][*(y)] == PUSTPOD);

		masproverky[*(x)][*(y)] = PUSTPOD;
		//������ ���������� ���������� ����
		xnach = *(x);
		ynach = *(y);

	}
};

string Igrok::getimya()
{
	return imya;
};