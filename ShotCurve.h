#pragma once

#include "ShotBase.h"

class ShotCurve : public ShotBase
{
public:
	ShotCurve()
	{

	}

	virtual ~ShotCurve()
	{

	}
	// �V���b�g�J�n
	virtual void start(Vec2 pos);

	// �X�V
	virtual void update();
};