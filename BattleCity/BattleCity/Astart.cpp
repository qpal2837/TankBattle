#include "Astart.h"
#include <iostream>
#include "Draw.h"
using namespace std;
int Astart::getH(COORD pos) {
	int x = pos.X - this->endPos.X;
	x = x > 0 ? x : -x;
	int y = pos.Y - this->endPos.Y;
	y = y > 0 ? y : -y;
	return x + y;
}

void Astart::setInfo(COORD start, COORD end) {
	this->startPos = start;
	this->endPos = end;
}

void Astart::getPath(Map& map, vector<COORD>& path) {
	//������һ���ڵ�
	PNode firstNode = new Node;
	firstNode->pos = this->startPos;
	firstNode->pFather = nullptr;
	firstNode->h = getH(firstNode->pos);
	firstNode->f = 0;
	firstNode->g = 0;
	this->vecOpen.push_back(firstNode);
	while (vecOpen.size() != 0) {
		//Ѱ�ҵ�open������f��С�ڵ�
		int minFIndex = 0;
		for (int i = 0; i < vecOpen.size(); i++) {
			if (vecOpen[minFIndex]->f > vecOpen[i]->f) {
				minFIndex = i;
			}
		}
		//�ж������С�ڵ��Ƿ�Ϊ���սڵ�
		if (vecOpen[minFIndex]->pos.X == this->endPos.X &&
			vecOpen[minFIndex]->pos.Y == this->endPos.Y) {
			//������ڵ����·д�������·����
			PNode pTemp = vecOpen[minFIndex];
			do {
				path.push_back(pTemp->pos);
				pTemp = pTemp->pFather;
			} while (pTemp->pFather != nullptr);
			return;
		}
		PNode newNode[4] = { 0 };
		for (int i = 0; i < 4; i++) {
			//�������������ĸ��ڵ�
			newNode[i] = new Node;
			newNode[i]->pos.X = vecOpen[minFIndex]->pos.X;
			newNode[i]->pos.Y = vecOpen[minFIndex]->pos.Y;
			newNode[i]->pFather = vecOpen[minFIndex];
			newNode[i]->g = vecOpen[minFIndex]->g + 1;
			switch (i) {
			case 0:
				newNode[i]->pos.Y--;
				break;
			case 1:
				newNode[i]->pos.Y++;
				break;
			case 2:
				newNode[i]->pos.X--;
				break;;
			case 3:
				newNode[i]->pos.X++;
				break;;
			}
			newNode[i]->h = getH(newNode[i]->pos);
			newNode[i]->f = newNode[i]->g + newNode[i]->h;
			//����Ƿ�����Ч�ڵ�
			bool saveFlag = true;
			//·�����ϰ����ж�
			int x = newNode[i]->pos.X;
			int y = newNode[i]->pos.Y;
			vector<COORD>coordArr;
			for (int i = y - 1; i <= y + 1; i++) {
				for (int j = x - 1; j <= x + 1; j++) {
					COORD coord = { j,i };
					coordArr.push_back(coord);
				}
			}
			for (int j = 0; j < coordArr.size(); j++) {
				switch (map.mapData[coordArr[j].Y][coordArr[j].X][0]) {
				case MAP_IRONWALL:
					saveFlag = false;
					break;
				case MAP_SOILWALL:
					saveFlag = false;
					break;
				case MAP_RIVER:
					saveFlag = false;
					break;
				}
				//·�����ڼ���̹���ж�
			/*	if (map.mapData[coordArr[j].Y][coordArr[j].X][1] == ENEMYTANK_ELEMENT_HEAD
					|| map.mapData[coordArr[j].Y][coordArr[j].X][1] == ENEMYTANK_ELEMENT_BODY) {
					saveFlag = false;
				}*/
			}
			//�����Ƿ��Ѿ���open����
			for (int j = 0; j < vecOpen.size(); j++) {
				if (vecOpen[j]->pos.X == newNode[i]->pos.X
					&& vecOpen[j]->pos.Y == newNode[i]->pos.Y
					) {
					saveFlag = false;
					break;
				}
			}
			if (saveFlag == true) {
				vecOpen.push_back(newNode[i]);
			}
		}
		vectClose.push_back(vecOpen[minFIndex]);
		vecOpen.erase(vecOpen.begin() + minFIndex);
	}
	path.erase(path.begin() + path.size() - 1);
}

Astart::~Astart() {
	for (int i = 0; i < this->vecOpen.size() - 1; i++) {
		delete	vecOpen[i];
	}
	for (int i = 0; i < this->vectClose.size() - 1; i++) {
		delete vectClose[i];
	}
}
