#pragma once
#include <iostream>
#include "string"
using namespace std;


const int N = 10; //����������� ���� ��� ������ � 1
const int ZAD = 10;//�������� - 500 ����������


const int kolodno = 0; //���������� ��������������
const int koldvy = 0; //���������� �������������
const int koltre = 1; //���������� ��������������
const int kolchetire = 1; //���������� �����������������
const int M = kolodno + koldvy + koltre + kolchetire; //���������� �������� � ������
const int KOLPOPITOK = 1000;

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

