#include "kletka.h"

kletka::kletka() //�����������
{
	klet = PUST;
};

void kletka::setklet(sostoyanie k) //������������� ��������� ������
{
	klet = k;
};

sostoyanie kletka::getklet() //������� ��������� ������
{
	return klet;
};