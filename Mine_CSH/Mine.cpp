#include "pch.h"
#include "Mine.h"

Mine::Mine()
	:isMine(false), mineCnt(0)
{

}

Mine::~Mine()
{
}

void Mine::SetIsMine(int num)
{
	isMine = num;
}
int Mine::GetIsMine()
{
	return isMine;
}
void Mine::MineDetect()//Áö·ÚÅ½Áö½Ã Ä«¿îÆ® Áõ°¡
{
	++mineCnt;
}
int Mine::GetMineCnt()
{
	return mineCnt;
}