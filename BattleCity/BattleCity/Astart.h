#pragma once
#include<windows.h>
#include <vector>
#include "BaseTank.h"
#include "Map.h"
using namespace std;
typedef struct _Node {
	COORD pos;
	_Node* pFather;
	int g;
	int h;
	int f;
}Node, * PNode;

class Astart {
private:
	COORD startPos;
	COORD endPos;
	vector<PNode>vecOpen;
	vector<PNode>vectClose;
	int getH(COORD pos);
public:
	
	/**
	  *	设置坐标 
	  *
	  *	@param  COORD start 开始节点
	  *	@param  COORD end	结束节点
	  * @return void
	  */
	void setInfo(COORD start, COORD end);

	/**
	  * 寻找路径
	  *
	  *	@param  Map & map	地图类对象
	  *	@param  vector<COORD> & path 路径vector
 	  * @return void
	  */
	void getPath(Map& map,  vector<COORD>& path);

	~Astart();
};