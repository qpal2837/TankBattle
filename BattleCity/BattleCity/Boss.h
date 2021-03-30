#pragma once
#include <windows.h>
#include <vector>
#include "Map.h"
#include "Draw.h"
#include "Element.h"
using namespace std;
class Boss {
public:
	//������
	int atk;
	//̹������
	vector<COORD>coordArr;
	//̹������ֵ
	int headlth;
	Draw& draw = Draw::getDraw();
	//����
	int direction;
	//�ӵ�����
	int bulletDirection;
	//״̬
	int status;
	//��ɫ
	int color;
	//��Ӫ
	int camp;
	//̹����Ͳ��ѭλ��
	int barnnelCount = 0;
	//̹����Ͳ����
	COORD barnnelCoord;

	/**
	  * ��ʼ��̹��
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void init(Map& map);
	/**
	  * ̹���ƶ�
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void move(Map& map);
	/**
	  * ����̹��
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void wipe(Map& map);
	Boss();

};

