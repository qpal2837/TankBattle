#pragma once
#include "Map.h"
#include <windows.h>
#include <vector>
using namespace std;
class BaseTank {
public:
	//方向
	int direction;
	//类型
	int type;
	//生命值
	int health;
	//中心坐标
	COORD coord;
	//坐标集合
	vector<COORD>coordArr;
	//颜色
	int color;
	//标记阵营
	int camp;
	//标记是否死亡
	int dead;
	//标记存在状态
	int status;
	//攻击力
	int atk;
	//分数
	int score;
	//坦克头部内存表示
	char tankElementHead;
	//坦克身体内存表示
	char tankElementBody;

	/**
	  *	敌方坦克控制指令生成 
	  *
	  *	@param  BaseTank & tank
	  *	@param  Map & map
	  * @return void
	  */
	virtual	void randomInstruction(BaseTank& tank, Map& map);

	/**
	  * 寻找最短路径
	  *
	  *	@param  BaseTank & baseTank
	  *	@param  Map & map
	  * @return void
	  */
	virtual	void findWay(BaseTank& baseTank, Map& map);

	/**
	  * 判断坐标是否有效
	  *
	  *	@param  Map & map
	  * @return bool
	  */
	virtual	bool checkRandomCoordArr(Map& map);
	/**
	  *	通过生成路径坐标获得方向 
	  *
	  *	@param  COORD & coord
	  *	@param  COORD & tempCoord
	  * @return int
	  */
	virtual	int getDrcByCoord(COORD& coord, COORD& tempCoord);
	/**
	  * 获取随机坐标
	  *
	  *	@param  Map & map
	  * @return void
	  */
	virtual void getRandomCoord(Map& map) = 0;
	/**
	  * 初始化坦克
	  *
	  *	@param  Map & map
	  * @return void
	  */
	virtual	void initTank(Map& map) = 0;
	/**
	  * 坦克移动
	  *
	  *	@param  int lastDirection
	  *	@param  Map & map
	  * @return int
	  */
	int moveTank(int lastDirection, Map& map);
	/**
	  * 判断地形碰撞
	  *
	  *	@param  int x
	  *	@param  int y
	  *	@param  Map & map
	  * @return int
	  */
	int checkTerrainCrash(int x, int y, Map& map);
	/**
	  * 清空坐标
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void clearCoord(Map& map);
	/**
	  * 判断坦克碰撞
	  *
	  *	@param  int x
	  *	@param  int y
	  *	@param  Map & map
	  * @return int
	  */
	int checkTankCrash(int x, int y, Map& map);
	/**
	  * 判断道具获取效果
	  *
	  *	@param  int x
	  *	@param  int y
	  *	@param  Map & map
	  * @return int
	  */
	virtual	int checkStageProperty(int x, int y, Map& map);
};

