#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	// �V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_pShotNormal)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotBound)
	{
		shot = nullptr;
	}
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& shot : m_pShot)
	{
		if (!pShot) continue;
		delete pShot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot = nullptr;
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_pShot)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->draw();
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot->draw();
	}

	// ���ݑ��݂��Ă���e�̐���\��
	int shotNum = 0;
	for (auto& shot : m_pShot)
	{
		if (!Shot) continue;
		if (pShot->isExist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Normal:%d", shotNum);
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_pShot)
	{
		if (Shot) continue;

		pShot = new ShotNormal;
		pShot->setHandle(m_hPlayerGraphic);
		pShot->start(pos);
		return true;
	}
#if false
	for (auto& shot : m_shotNormal)
	{
		if (shot.isExist()) continue;

		shot.start(pos);
		return true;
	}
#endif
	return false;
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_pShotBound)
	{
		if (shot) continue;

		shot = new ShotNormal;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;

		delete;
	}
	return false;
}