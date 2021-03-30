#pragma once
#include <windows.h>
#include <vector>
#include "Map.h"
#include "Draw.h"
#include "Element.h"
using namespace std;
class Boss {
public:
	//攻击力
	int atk;
	//坦克坐标
	vector<COORD>coordArr;
	//坦克生命值
	int headlth;
	Draw& draw = Draw::getDraw();
	//方向
	int direction;
	//子弹方向
	int bulletDirection;
	//状态
	int status;
	//颜色
	int color;
	//阵营
	int camp;
	//坦克炮筒轮循位置
	int barnnelCount = 0;
	//坦克炮筒坐标
	COORD barnnelCoord;

	/**
	  * 初始化坦克
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void init(Map& map);
	/**
	  * 坦克移动
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void move(Map& map);
	/**
	  * 擦除坦克
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void wipe(Map& map);
	Boss();

};

