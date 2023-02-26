#include "Mnogopalybnik.h"

Mnogopalybnik::Mnogopalybnik() //�� ��������� ������� ������������ �������
{
	kolpalyb = 2;
	int i;
	for (i = 0; i < kolpalyb; i++)
	{
		bolkorabl[i] = new Odnopalybnik();
	}
};

Mnogopalybnik::Mnogopalybnik(int k)
{
	if (1 < k <= 4)
	{
		kolpalyb = k;
		int i;
		for (i = 0; i < kolpalyb; i++)
		{
			bolkorabl[i] = new Odnopalybnik();
		}
	}
	else
	{
		kolpalyb = 2;
		int i;
		for (i = 0; i < kolpalyb; i++)
		{
			bolkorabl[i] = new Odnopalybnik();
		}
		cout << endl << "�� ������ �������� ��������� k, ������ ������������ �������!!!" << endl;
	}
};

//���������� ������ �������������
/*sost Mnogopalybnik::getpalyba()
{
	return Odnopalybnik::getpalyba();
};

void Mnogopalybnik::setpalyba(sost p)
{
	Odnopalybnik::setpalyba(p);
};
*/
sost Mnogopalybnik::getkorabl()
{
	int i;
	for (i = 0; i < kolpalyb; i++)
	{
		if (bolkorabl[i]->getpalyba() == NEPODBIT)
		{
			return NEPODBIT;
		}
	}
 	return UBIT;
};

/*void Mnogopalybnik::setkorabl(sost k)
{
	Odnopalybnik::setkorabl(k);
}; */

int Mnogopalybnik::ustanovkakorablya(pole* doska)
{
	int x,y, xk[4], yk[4], napr, kolpopytok,i; //� ������� ����� �������� 4 ���������� ��� 4�-���������
	
	kolpopytok = 0;
	do
	{
	//�������� �� ����� KOLPOP ������� ����������� �������
	kolpopytok = kolpopytok + 1;
	if (kolpopytok > KOLPOP)
	{
		//���� ������� KOLPOP ������� ������� ��������� ������
		//cout << endl << "���������� ����������� ���������� ������� ����������� �������. ������� ��������� �� �������!!!" << endl;
		//break;
		return 1; //������ ������� ��������� �� �������
	}

	x = (int)((rand() / 32767.0) * (N));
	y = (int)((rand() / 32767.0) * (N));
	napr = (int)((rand() / 32767.0) * (3)) + 1; //�������� ���� �� 4-� �����������

	for (i = 0; i < kolpalyb; i++)
	{
		//��������� ���� ����� � ��� �� ���� ������� �������
		if (doska->pol[x][y].getklet() == KOR)
		{
			break;
		}

		//��������� �������� ���� �� ������� � ��� �������, �� �� ����� ����� ��� �� �������� �� ����� �������
		if ((x + 1) < N)
		{
			if (doska->pol[x + 1][y].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x + 1) < N) && ((y + 1) < N))
		{
			if (doska->pol[x + 1][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if ((y + 1) < N)
		{
			if (doska->pol[x][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x - 1) >= 0) && ((y + 1) < N))
		{
			if (doska->pol[x - 1][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x - 1) >= 0))
		{
			if (doska->pol[x - 1][y].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x - 1) >= 0) && ((y - 1) >= 0))
		{
			if (doska->pol[x - 1][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((y - 1) >= 0))
		{
			if (doska->pol[x][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x + 1) < N) && ((y - 1) >= 0))
		{
			if (doska->pol[x + 1][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}
		//��������� ���������� ���������� �������������� � ������
		xk[i] = x; 
		yk[i] = y;

		if ((napr == 1) && ((x + 1) < N))
		{
			x = x + 1;
		}
		else
		{
			if ((napr == 2) && ((x - 1) >= 0))
			{
				x = x - 1;
			}
			else
			{
				if ((napr == 3) && ((y + 1) < N))
				{
					y = y + 1;
				}
				else
				{
					if ((napr == 4) && ((y - 1) >= 0))
					{
						y = y - 1;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	if (i == kolpalyb)
	{
		//���� ����� �� kolpalyb �������� ����� �� ������� ��������� �������
		break;
	}
	} while (1);

	for (i = 0; i < kolpalyb; i++)
	{
		bolkorabl[i]->setkoordinata(xk[i], yk[i]); 
		bolkorabl[i]->setpalyba(NEPODBIT);
		doska->pol[xk[i]][yk[i]].setklet(KOR);
	}
	//setkorabl(NEPODBIT);
	return 0; //��������� ������ �������
};

sost Mnogopalybnik::proverkakorablya(int x, int y)//���������� ������� ������ �� � ����
{
	int i;
	sost res = NEPODBIT;
	for (i = 0; i < kolpalyb; i++)
	{
		if ((x == bolkorabl[i]->getkoordinataX()) && (y == bolkorabl[i]->getkoordinataY()))
		{
			bolkorabl[i]->setpalyba(PODBIT);
			res = PODBIT;

			if (this->getkorabl() == UBIT)
			{
				res = UBIT;
			}

			break;
		}
	}
	return res;
}; 