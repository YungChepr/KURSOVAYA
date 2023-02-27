#pragma once
#include <iostream>
#include "string"
#include <windows.h>

using namespace std;

const int NMAX = 20; //������������ ����������� ����
const int NMIN = 3; //����������� ����������� ����
const int NFIX = 3; //������� ����������� ���� ��� ������ � 1


const int KOLPOP = 500; //������������ ���������� ������� ��������� ������ �������
const int KOLRAZ = 100; //������������ ���������� ������� ����������� ���� ��������


const int MMAX = 400; //������������ ���������� ��������
const int kolodnoFIX = 0; //������� ���������� ��������������
const int koldvyFIX = 2; //������� ���������� �������������
const int koltreFIX = 0; //������� ���������� ��������������
const int kolchetireFIX = 0; //������� ���������� �����������������
const int MFIX = kolodnoFIX + koldvyFIX + koltreFIX + kolchetireFIX; //������� ���������� �������� � ������

const int ZAD = 10;//�������� - 500 ����������
const int KOLPOPITOK = 1000;

extern int N; //����������� ����������� ���� ��� ������ � 1

extern int kolodno;//����������� ���������� ��������������
extern int koldvy; //����������� ���������� �������������
extern int koltre; //����������� ���������� ��������������
extern int kolchetire; //����������� ���������� �����������������
extern int M; //����������� ���������� �������� � ������

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

enum varianti //�������� ��������
{
	var1, // ������������ �������
	var2, // ������ ��������� � �������
	var3, // ��������� ��������� � �������
	var3A,// ������ ����� ������� ��������
	var4, // ������ ����� �����
	var5
};

