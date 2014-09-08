#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class COBJECT;
class CTitle;

struct Item
{
	Float3 Pos;
	Float3 Size;
	Color color;
};

class Stage
{
private:
	
	enum StageFlag
	{
		TITLE,
		MAIN,
		CLEAR,
	};

	StageFlag Flag;

public:
	enum OBJECT
	{
		FLOOR,			//	��
		LADDER,		//	��
		BARREL,		//	�M
		DRUM,			//	�h������(�A���p)

		ALL,
	};


	Stage();
	~Stage();

	void Map();
	void Update();

	void Transition();	//�J��

	void Draw();
	void GameMain();
	//		�X�}�[�g�|�C���^
	//		����������̓I��
	std::vector<std::unique_ptr<COBJECT>> obj[OBJECT::ALL];
	std::unique_ptr<COBJECT> player;
	std::unique_ptr<COBJECT> enemy;
	std::unique_ptr<COBJECT> hammer;

	std::unique_ptr<CTitle> Title;

	const static int Width = 512;		//	��
	const static int Height = 448;		//	����

};

extern Stage *stage;