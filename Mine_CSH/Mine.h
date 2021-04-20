#pragma once
class Mine
{
public:
	Mine();
	~Mine();
	void SetIsMine(int);
	int GetIsMine();
	void MineDetect();
	int GetMineCnt();
private:
	int isMine;
	int mineCnt;

};



