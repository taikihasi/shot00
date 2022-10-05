#include "ShotCurve.h"
#include "game.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
	constexpr float kShotGravity = 8.0f;
}


void ShotCurve::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed;
	m_vec.y = kShotGravity;
}

void ShotCurve::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}  