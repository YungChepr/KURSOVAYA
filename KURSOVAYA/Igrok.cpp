#include "Igrok.h"


Igrok::Igrok(string imya)
{
	fdobit = var1; //��� ������� ������� ����� ��������
	napr = 0;  //��� ����������� �� �������� ��������
	ch = 0;
	xnach = -1; 
	ynach = -1;
	xpre = -1;
	ypre = -1;
	naprmimo[0] = 0;
	naprmimo[1] = 0;
	naprmimo[2] = 0;
	naprmimo[3] = 0;
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

void Igrok::vystrel(int* x, int* y, pole* doska) //��������� ���� � ������� ����� ��������
{   
	
	if ((doska->resposlxoda == "�����") && (fdobit == var1)) //������ ���������
	{
		fdobit = var2;
	}

	if ((doska->resposlxoda == "�����") && (fdobit == var2)) //������ ���������
	{
		fdobit = var3;
	}

	if ((doska->resposlxoda == "�����") && (fdobit == var3)) //
	{
		fdobit = var3;
	}

	if ((doska->resposlxoda == "�����") && ( fdobit == var3A)) //
	{
		fdobit = var3;
	}

	if (((doska->resposlxoda == "����") || (doska->resposlxoda == "���� ����")) && (fdobit == var2)) //������ ����� ������� ���������
	{
		fdobit = var3A;
	}

	if (((doska->resposlxoda == "����") || (doska->resposlxoda == "���� ����")) && (fdobit == var3)) //������ ����� ����� ���������
	{
		fdobit = var4;
	}

	if (doska->resposlxoda == "����") //���� ����� �������
	{
		fdobit = var5;
	}
	
	if (fdobit == var5)
	{
		//������ �������������� ����������
		fdobit = var1; //��� ������� ������� ����� ��������
		napr = 0;  //��� ����������� �� �������� ��������
		ch = 0;
		xnach = -1;
		ynach = -1;
		xpre = -1;
		ypre = -1;
		naprmimo[0] = 0;
		naprmimo[1] = 0;
		naprmimo[2] = 0;
		naprmimo[3] = 0;

		//��������� �������� �������� 1
		do
		{
			*(x) = (int)((rand() / 32767.0) * (N));
			*(y) = (int)((rand() / 32767.0) * (N));
		} while (masproverky[*(x)][*(y)] == PUSTPOD);

		masproverky[*(x)][*(y)] = PUSTPOD;
		//������ ���������� ���������� ����
		xnach = *(x);
		ynach = *(y);
	}

	if (fdobit == var4)
	{
		if (napr == 1)
		{
			napr = 2;
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			napr = 1;
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			napr = 4;
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			napr = 3;
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	if (fdobit == var3A)
	{
		//�������� �����������
		do {
			napr = (int)((rand() / 32767.0) * (3)) + 1; //�������� ���� �� 4-� �����������

			if ((napr == naprmimo[0]) || (napr == naprmimo[1]) || (napr == naprmimo[2]))
			{
				continue;
			}
			else
			{
				ch = ch + 1;
				naprmimo[ch] = napr;
				break;
			}
		}
		while (1);

		if (napr == 1)
		{
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	if (fdobit == var3)
	{
		if (napr == 1)
		{
			xpre = xpre + 1;
		}
		if (napr == 2)
		{
			xpre = xpre - 1;
		}
		if (napr == 3)
		{
			ypre = ypre + 1;
		}
		if (napr == 4)
		{
			ypre = ypre - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	if (fdobit == var2) 
	{
		//�������� �����������
		napr = (int)((rand() / 32767.0) * (3)) + 1; //�������� ���� �� 4-� �����������
		naprmimo[ch] = napr;

		if (napr == 1)
		{
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	
	if (fdobit == var1)
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