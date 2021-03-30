#pragma once
#include "Map.h"
#include <windows.h>
#include <vector>
using namespace std;
class BaseTank {
public:
	//����
	int direction;
	//����
	int type;
	//����ֵ
	int health;
	//��������
	COORD coord;
	//���꼯��
	vector<COORD>coordArr;
	//��ɫ
	int color;
	//�����Ӫ
	int camp;
	//����Ƿ�����
	int dead;
	//��Ǵ���״̬
	int status;
	//������
	int atk;
	//����
	int score;
	//̹��ͷ���ڴ��ʾ
	char tankElementHead;
	//̹�������ڴ��ʾ
	char tankElementBody;

	/**
	  *	�з�̹�˿���ָ������ 
	  *
	  *	@param  BaseTank & tank
	  *	@param  Map & map
	  * @return void
	  */
	virtual	void randomInstruction(BaseTank& tank, Map& map);

	/**
	  * Ѱ�����·��
	  *
	  *	@param  BaseTank & baseTank
	  *	@param  Map & map
	  * @return void
	  */
	virtual	void findWay(BaseTank& baseTank, Map& map);

	/**
	  * �ж������Ƿ���Ч
	  *
	  *	@param  Map & map
	  * @return bool
	  */
	virtual	bool checkRandomCoordArr(Map& map);
	/**
	  *	ͨ������·�������÷��� 
	  *
	  *	@param  COORD & coord
	  *	@param  COORD & tempCoord
	  * @return int
	  */
	virtual	int getDrcByCoord(COORD& coord, COORD& tempCoord);
	/**
	  * ��ȡ�������
	  *
	  *	@param  Map & map
	  * @return void
	  */
	virtual void getRandomCoord(Map& map) = 0;
	/**
	  * ��ʼ��̹��
	  *
	  *	@param  Map & map
	  * @return void
	  */
	virtual	void initTank(Map& map) = 0;
	/**
	  * ̹���ƶ�
	  *
	  *	@param  int lastDirection
	  *	@param  Map & map
	  * @return int
	  */
	int moveTank(int lastDirection, Map& map);
	/**
	  * �жϵ�����ײ
	  *
	  *	@param  int x
	  *	@param  int y
	  *	@param  Map & map
	  * @return int
	  */
	int checkTerrainCrash(int x, int y, Map& map);
	/**
	  * �������
	  *
	  *	@param  Map & map
	  * @return void
	  */
	void clearCoord(Map& map);
	/**
	  * �ж�̹����ײ
	  *
	  *	@param  int x
	  *	@param  int y
	  *	@param  Map & map
	  * @return int
	  */
	int checkTankCrash(int x, int y, Map& map);
	/**
	  * �жϵ��߻�ȡЧ��
	  *
	  *	@param  int x
	  *	@param  int y
	  *	@param  Map & map
	  * @return int
	  */
	virtual	int checkStageProperty(int x, int y, Map& map);
};

