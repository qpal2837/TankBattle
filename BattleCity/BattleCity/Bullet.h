#pragma once
#include <windows.h>
#include "Map.h"
#include "Draw.h"
#include "BaseTank.h"
#include "Element.h"
#include "Boss.h"
class Bullet {
public:
	//�ӵ���Դ
	int beFromFire;
	//�ӵ���ɫ
	int color;
	//�ӵ�����
	int direction;
	//�ӵ��˶��Ƿ����
	int over;
	//�ӵ��Ƿ����̹��
	int hitTank;
	//�ӵ�����������ɫ
	int crossColor;
	//�ӵ���������
	COORD hitCoord;
	//�ӵ�������
	int atk;
	//�ӵ�������Ӫ
	int hitCamp;
	Draw draw = Draw::getDraw();
	//�ӵ�����
	COORD coord;
	
	
	/**
	  * �ӵ��ƶ�����
	  *
	  *	@param  Map & map
	  *	@param  vector<Bullet> * bulletArr
	  * @return int
	  */
	int moveBullet(Map& map, vector<Bullet>* bulletArr);
	Bullet(BaseTank& tank, Map& map, int atk);
	Bullet(Boss& boss, COORD& coord, Map& map, int atk);
	/**
	  * 
	  *
	  *	@param  Map & map
	  *	@param  COORD & coord
	  * @return int
	  */
	int checkCrash(Map& map, COORD& coord);
	/**
	  * 
	  *
	  * @return void
	  */
	void drawBullet();
	/**
	  * ̹����ײ�ж�
	  *
	  *	@param  Map & map
	  *	@param  COORD & coord
	  * @return int
	  */
	int checkTankCrash(Map& map, COORD& coord);
	/**
	  * �ӵ����ӵ�֮����ײ�ж�
	  *
	  *	@param  Map & map
	  *	@param  COORD & coord
	  *	@param  vector<Bullet> * bulletArr
	  * @return int
	  */
	int checkBulletCrash(Map& map, COORD& coord, vector<Bullet>* bulletArr);
	int checkBulletCrash(Map& map, COORD& coord);
	Bullet();

};

