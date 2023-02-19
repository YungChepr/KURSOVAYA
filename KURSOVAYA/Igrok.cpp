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
	else
	{
		if ((doska->resposlxoda == "�����") && (fdobit == var2)) //������ ���������
		{
			fdobit = var3;
		}
		else
		{
			if ((doska->resposlxoda == "�����") && (fdobit == var3)) //
			{
				fdobit = var3;
			}
			else
			{
				if ((doska->resposlxoda == "�����") && (fdobit == var3A)) //
				{
					fdobit = var3;
				}
				else
				{
					if (((doska->resposlxoda == "����") || (doska->resposlxoda == "���� ����")) && (fdobit == var2)) //������ ����� ������� ���������
					{
						fdobit = var3A;
					}
					else
					{
						if (((doska->resposlxoda == "����") || (doska->resposlxoda == "���� ����")) && (fdobit == var3)) //������ ����� ����� ���������
						{
							fdobit = var4;
						}
						else
						{
							if (doska->resposlxoda == "����") //���� ����� �������
							{
								fdobit = var5;
							}
						}
					}
				}
			}
		}
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
			*(x) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
			*(y) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
		} while (masproverky[*(x)][*(y)] == PUSTPOD);
		masproverky[*(x)][*(y)] = PUSTPOD;

		//������ ���������� ���������� ����
		xnach = *(x);
		ynach = *(y); 
		xpre = xnach;
		ypre = ynach;

		return;
	}

	if (fdobit == var3A)
	{
		//�������� �����������
		do {
			napr = round(((double) rand() / 32767) * (4-1) + 1); //�������� ���� �� 4-� �����������

			if ((napr == naprmimo[0]) || (napr == naprmimo[1]) || (napr == naprmimo[2]))
			{
				continue;
			}
			else
			{
				if ((napr == 1) && (!((xnach + 1) < N)))
				{
					continue;
				}
				if ((napr == 2) && (!((xnach - 1) >= 0)))
				{
					continue;
				}
				if ((napr == 3) && (!((ynach + 1) < N)))
				{
					continue;
				}
				if ((napr == 4) && (!((ynach - 1) >= 0)))
				{
					continue;
				}

				ch = ch + 1;
				naprmimo[ch] = napr;
				break;
			}
		}
		while (1);

		if (napr == 1)
		{
			xpre = xnach + 1;
			ypre = ynach;
		}
		else
		{
			if (napr == 2)
			{
				xpre = xnach - 1;
				ypre = ynach;
			}
			else
			{
				if (napr == 3)
				{
					ypre = ynach + 1;
					xpre = xnach;
				}
				else
				{
					if (napr == 4)
					{
						ypre = ynach - 1;
						xpre = xnach;
					}
				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	if (fdobit == var3)
	{
		if ((napr == 1) && ((xpre + 1) < N))
		{
			xpre = xpre + 1;
		}
		else
		{
			if ((napr == 2) && ((xpre - 1) >= 0))
			{
				xpre = xpre - 1;
			}
			else {
				if ((napr == 3) && ((ypre + 1) < N))
				{
					ypre = ypre + 1;
				}
				else {
					if ((napr == 4) && ((ypre - 1) >= 0))
					{
						ypre = ypre - 1;
					}
					else
					{
						//����� ������� 4
						if (napr == 1)
						{
							napr = 2;
							xpre = xnach - 1;
						}
						else
						{
							if (napr == 2)
							{
								napr = 1;
								xpre = xnach + 1;
							}
							else
							{
								if (napr == 3)
								{
									napr = 4;
									ypre = ynach - 1;
								}
								else
								{
									if (napr == 4)
									{
										napr = 3;
										ypre = ynach + 1;
									}
								}
							}
						}
					}
				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	//������ ����������� �� �����������������
	if (fdobit == var4)
	{
		if (napr == 1)
		{
			napr = 2;
			xpre = xnach - 1;
		}
		else
		{
			if (napr == 2)
			{
				napr = 1;
				xpre = xnach + 1;
			}
			else
			{
				if (napr == 3)
				{
					napr = 4;
					ypre = ynach - 1;
				}
				else
				{
					if (napr == 4)
					{
						napr = 3;
						ypre = ynach + 1;
					}


				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		fdobit = var3;
		return;
	}

	if (fdobit == var2) 
	{
		//�������� �����������
		do {
			napr = round(((double) rand() / 32767) * (4 - 1) + 1); //�������� ���� �� 4-� �����������
			if ((napr == 1) && ((xnach + 1) < N))
			{
				break;
			}
			if ((napr == 2) && ((xnach - 1) >= 0))
			{
				break;
			}
			if ((napr == 3) && ((ynach + 1) < N))
			{
				break;
			}
			if ((napr == 4) && ((ynach - 1) >= 0))
			{
				break;
			}
		} while (1);

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
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	if (fdobit == var1)
	{
		do 
		{
			*(x) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
			*(y) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
		} 
		while (masproverky[*(x)][*(y)] == PUSTPOD);
		masproverky[*(x)][*(y)] = PUSTPOD;

		//������ ���������� ���������� ����
		xnach = *(x);
		ynach = *(y);
		xpre = xnach;
		ypre = ynach;
		return;
	}
};

string Igrok::getimya()
{
	return imya;
};