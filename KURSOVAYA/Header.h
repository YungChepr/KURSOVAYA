#pragma once
#include <iostream>
#include "string"
using namespace std;


const int N = 10; //����������� ���� ��� ������ � 1
const int ZAD = 10;//�������� - 500 ����������

const int kolodno = 4; //���������� ��������������
const int koldvy = 3; //���������� �������������
const int koltre = 2; //���������� ��������������
const int kolchetire = 1; //���������� �����������������
const int M = kolodno + koldvy + koltre + kolchetire; //���������� �������� � ������

enum sostoyanie //��������� ����
{
	PUST,		//������
	PUSTPOD,	//������ �� ���� ��� ��������
	KOR,		//�� ���� ���� ����� �������
	KORPOD		//�� ���� ���� ����� ������� �� �������� ��������
};

enum sost //��������� ������ � �������
{
	PODBIT,     //������ �������, ����� � �������
	NEPODBIT,   //������ �� �������, ���� �������
	UBIT,	  //������� ����
	NEUKAZANO   //��������� �� �������
};

