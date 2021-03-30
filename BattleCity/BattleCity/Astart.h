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
	  *	�������� 
	  *
	  *	@param  COORD start ��ʼ�ڵ�
	  *	@param  COORD end	�����ڵ�
	  * @return void
	  */
	void setInfo(COORD start, COORD end);

	/**
	  * Ѱ��·��
	  *
	  *	@param  Map & map	��ͼ�����
	  *	@param  vector<COORD> & path ·��vector
 	  * @return void
	  */
	void getPath(Map& map,  vector<COORD>& path);

	~Astart();
};