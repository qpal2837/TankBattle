#pragma once
#include <windows.h>
#include "Map.h"
#include "Draw.h"
#include "BaseTank.h"
#include "Element.h"
#include "Boss.h"
class Bullet {
public:
	//子弹来源
	int beFromFire;
	//子弹颜色
	int color;
	//子弹方向
	int direction;
	//子弹运动是否结束
	int over;
	//子弹是否击中坦克
	int hitTank;
	//子弹穿过物体颜色
	int crossColor;
	//子弹击中坐标
	COORD hitCoord;
	//子弹攻击力
	int atk;
	//子弹击中阵营
	int hitCamp;
	Draw draw = Draw::getDraw();
	//子弹坐标
	COORD coord;
	
	
	/**
	  * 子弹移动方法
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
	  * 坦克碰撞判断
	  *
	  *	@param  Map & map
	  *	@param  COORD & coord
	  * @return int
	  */
	int checkTankCrash(Map& map, COORD& coord);
	/**
	  * 子弹与子弹之间碰撞判断
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

