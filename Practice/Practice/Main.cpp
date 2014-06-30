
/*
		�V���[�e�B���O�Q�[���T���v��
		�n�Ӑ搶�ɏ��߂Ă�������R�[�h
*/
//	Siv3D���g�p���邽�߂̃C���N���[�h
# include <Siv3D.hpp>
//	------------------------------------------------------------------------------------------------------------------------
//	��`
//	------------------------------------------------------------------------------------------------------------------------
const int SCREEN_WIDTH = 640;				//		�E�C���h�E�̉���
const int SCREEN_HEIGHT = 480;				//		�E�C���h�E�̏c��

enum ID	//		�I�u�W�F�N�g��ID
{
	PLAYER = 1,		//		�v���C���[
	ENEMY,			//		�G
};

enum STATE		//		�I�u�W�F�N�g�̏��
{
	NONE,			//		���S�m�F
	LIVE,				//		�����Ă���
	HIT,				//		����������
};

//		�v���C���[���p�f�[�^
const int PLAYER_WIDTH = 32;																//		�v���C���[�̉���
const int PLAYER_HEIGHT = 32;															//		�v���C���[�̏c��
const int PLAYER_START_X	= (SCREEN_WIDTH / 2);								//		�����ʒu
const int PLAYER_START_Y = (SCREEN_HEIGHT - PLAYER_HEIGHT);		//		�����ʒu
const Color PLAYER_COLOR = Color(255, 255, 255);								//		�v���C���[�̐F
const int PLAYER_SHOT_WIDTH = 16;													//		�v���C���[�̒e�̉���
const int PLAYER_SHOT_HEIGHT = 16;													//		�v���C���[�̒e�̏c��
const int PLAYER_SHOT_SPEED = 8;														//		�v���C���[�̒e�̑���
const int PLAYER_MOVESPEED = 4;														//		�v���C���[�̑���

//		�G���p�̃f�[�^
const int ENEMY_START_X = 0;								//		�����ʒu
const int ENEMY_START_Y = 0;								//		�����ʒu
const int ENEMY_WIDTH = 32;									//		�G�̉���
const int ENEMY_HEIGHT = 32;									//		�G�̏c��
const Color ENEMY_COLOR = Color(0, 255, 0);			//		�G�̐F
const int ENEMY_SHOT_WIDTH = 16;							//		�G�̒e�̉���
const int ENEMY_SHOT_HEIGHT = 16;						//		�G�̒e�̏c��
const int ENEMY_SHOT_SPEED = 8;							//		�G�̒e�̑���
const int ENEMY_MOVESPEED = 4;							//		�G�̑���
const int ENEMY_SHOT_MIN_TIME = 100;					//		�G���V���b�g��ł܂ł̍Œ�Ԋu
const int ENEMY_SHOT_MAX_TIME = 400;					//		�G���V���b�g��ł܂ł̍ő�Ԋu

//		�w�i���
const Color BG_COLOR = Color(0, 0, 0);
//	------------------------------------------------------------------------------------------------------------------------
//	�\���̒�`
//	------------------------------------------------------------------------------------------------------------------------
class OBJECT
{
public:
	OBJECT(){}
	~OBJECT(){}
public:
	int x;				//		X���W
	int y;				//		Y���W
	int width;		//		����
	int height;		//		�c��
	Color color;	//		�F
	int state;		//		��Ԃ�\���ϐ�

private:
};

//	------------------------------------------------------------------------------------------------------------------------
//	�O���[�o���ϐ���`
//	------------------------------------------------------------------------------------------------------------------------

OBJECT Player;				//	�v���C���[���
OBJECT Enemy;				//	�G���
OBJECT PlayerShot;		//	�v���C���[�̃V���b�g���
OBJECT EnemyShot;		//	�G�̃V���b�g���

int enemyMoveDirc = 1;	//	�G�̈ړ�����
int enemyShotTime = 0;	//	�G���e�����^�C�~���O

//	--------------------------------------------------------------------
//	�v���C���[���̏������֐�
//	--------------------------------------------------------------------
void InitPlayer()
{
	//	�v���C���[�f�[�^�ɏ����l������
	Player.x = PLAYER_START_X;
	Player.y = PLAYER_START_Y;
	Player.width = PLAYER_WIDTH;
	Player.height = PLAYER_HEIGHT;
	Player.color = PLAYER_COLOR;
	Player.state = STATE::LIVE;

	//	�v���C���[�V���b�g�f�[�^�ɏ����l������
	//	�V���b�g�͑��݂��Ȃ���Ԃ���Q�[�����J�n�����̂�-1�ŏ���������
	//	���W�f�[�^�̓V���b�g��ł܂ł킩��Ȃ��̂ł܂�����Ȃ�
	PlayerShot.width = PLAYER_SHOT_WIDTH;
	PlayerShot.height = PLAYER_SHOT_HEIGHT;
	PlayerShot.color = PLAYER_COLOR;
	PlayerShot.state = STATE::NONE;
}
//	--------------------------------------------------------------------
//	�G���V���b�g�����܂ł̃^�C�~���O���v�Z����
//	--------------------------------------------------------------------
void CalcEnemyShotTiming()
{
	//	�V���b�g��ł܂ł̊Ԋu�����߂�
	//	ENEMY_SHOT_MIN_TIME����ENEMY_SHOT_MAX_TIME�܂ł̊Ԃ̗���������
	enemyShotTime = Random(ENEMY_SHOT_MIN_TIME, ENEMY_SHOT_MAX_TIME);
}
//	--------------------------------------------------------------------
//	�G���̏������֐�
//	--------------------------------------------------------------------
void InitEnemy()
{
	//	�G�f�[�^�̏����l������
	Enemy.x = Random(SCREEN_WIDTH - ENEMY_WIDTH);	//	���񃉃��_���ȏꏊ�ɏo��������
	Enemy.y = ENEMY_START_Y;
	Enemy.width = ENEMY_WIDTH;
	Enemy.height = ENEMY_HEIGHT;
	Enemy.color = ENEMY_COLOR;
	Enemy.state = STATE::LIVE;

	//	�G�V���b�g�f�[�^�ɏ����l������
	//	�V���b�g�͑��݂��Ȃ���Ԃ���Q�[�����J�n�����̂�-1�ŏ���������
	//	���W�f�[�^�̓V���b�g��ł܂ł킩��Ȃ��̂ł܂�����Ȃ�
	EnemyShot.width = ENEMY_SHOT_WIDTH;
	EnemyShot.height = ENEMY_SHOT_HEIGHT;
	EnemyShot.color = ENEMY_COLOR;
	EnemyShot.state = STATE::NONE;

	//	�G�̏����ړ��������v�Z
	//	���L�������Ă�������ֈړ�����
	if (Enemy.x < SCREEN_WIDTH / 2)
	{
		enemyMoveDirc = 1;
	}
	else
	{
		enemyMoveDirc = -1;
	}

	CalcEnemyShotTiming();

	return;
}
//	--------------------------------------------------------------------
//	�Q�[����������������֐�
//	--------------------------------------------------------------------
void InitGame()
{
	//	�v���C���[���̏�����
	InitPlayer();
	//	�G���̏�����
	InitEnemy();

	return;
}
//	--------------------------------------------------------------------
//	�I�u�W�F�N�g�`����s���֐�
//	--------------------------------------------------------------------
void DrawObject(OBJECT target)
{
	//	�I�u�W�F�N�g�����݂��Ȃ��Ƃ��͕`�悵�Ȃ��Ă悢
	if (target.state == STATE::NONE) return;

	//	�I�u�W�F�N�g�`��
	Rect(target.x,			//	X1���W
			target.y,			//	Y1���W
			target.width,	//	X2���W�@
			target.height)	//	Y2���W�@
			.draw(target.color);//	�F

	return;
}
//	--------------------------------------------------------------------
//	�w�i��h��Ԃ��֐�
//	--------------------------------------------------------------------
void DrawBG()
{
	Graphics::SetBackground(BG_COLOR);

	return;
}
//	--------------------------------------------------------------------
//	objA��objB���Փ˂��Ă��邩�𒲂ׂ�
//	�����FOBJECT objA,objB...�Փ˔��肵�����I�u�W�F�N�g
//	�߂�l�F1...�Փ˂��Ă��� 0...�Փ˂��Ă��Ȃ�
//	--------------------------------------------------------------------
bool IsHit(OBJECT objA, OBJECT objB)
{
	int x0 = objA.x;
	int y0 = objA.y;
	int x1 = objA.x + objA.width - 1;
	int y1 = objA.y + objA.height - 1;

	int x2 = objB.x;
	int y2 = objB.y;
	int x3 = objB.x + objB.width - 1;
	int y3 = objB.y + objB.height - 1;

	//	��̋�`����������̌`�ŏd�Ȃ��Ă��邩�H
	if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
	{
		//	�d�Ȃ��Ă���
		return true;
	}

	//	�d�Ȃ��ĂȂ�����
	return false;
}
//	--------------------------------------------------------------------
//	�e�𐶐�����֐�
//	�����Fint shooterID...�e�����̂̓v���C���[���G�Ȃ̂��̏��
//	�����FOBJECT shooter...�e���������I�u�W�F�N�g���
//	--------------------------------------------------------------------
void CreateShot(int shooterID, OBJECT shooter)
{
	//	�����̒e���G�̒e�Ȃ̂��ŏ�����ύX
	switch (shooterID)
	{
	case ID::PLAYER:
		PlayerShot.state = STATE::LIVE;
		PlayerShot.x = shooter.x + shooter.width / 2 - PlayerShot.width / 2;	//	�v���C���[�̐^�񒆂��甭��
		PlayerShot.y = shooter.y - PlayerShot.height;
		break;
	case ID::ENEMY:
		EnemyShot.state = STATE::LIVE;
		EnemyShot.x = shooter.x + shooter.width / 2 - EnemyShot.width / 2;	//	�G�̐^�񒆂��甭��
		EnemyShot.y = shooter.y + shooter.height;
		break;
	}
}
//	--------------------------------------------------------------------
//	�v���C���[�̈ړ��E�V���b�g�̔��ˏ������s��
//	--------------------------------------------------------------------
void ControllPlayer()
{
	//	���J�[�\����������Ă��邩�ǂ������`�F�b�N
	if (Input::KeyRight.pressed)
	{
		Player.x += PLAYER_MOVESPEED;
	}
	//	���J�[�\����������Ă��邩�ǂ������`�F�b�N
	if (Input::KeyLeft.pressed)
	{
		Player.x -= PLAYER_MOVESPEED;
	}

	//	�V���b�g���˃`�F�b�N
	if (Input::KeySpace.clicked && PlayerShot.state == STATE::NONE)
	{
		//	�e�𐶐�
		CreateShot(ID::PLAYER, Player);
	}
}
//*/
//	--------------------------------------------------------------------
//	�v���C���[�̃V���b�g�̈ړ��֐�
//	--------------------------------------------------------------------
void ControllPlayerShot()
{
	//	�e���������G�Ƀq�b�g���Ă���Ȃ�ړ������͂����ɏI��
	if (PlayerShot.state != STATE::LIVE) return;

	//	�e�̈ړ�
	PlayerShot.y -= PLAYER_SHOT_SPEED;

	//	�e�͓G�Ƀq�b�g���Ă���H
	if (IsHit(PlayerShot, Enemy) == true)
	{
		//	�e������
		PlayerShot.state = STATE::NONE;
		//	�G���܂��o��
		InitEnemy();
		return;
	}

	//	�e�͉�ʊO�ɏ������H
	if (PlayerShot.y < 0)
	{
		PlayerShot.state = STATE::NONE;
	}

	return;
}
//	--------------------------------------------------------------------
//	�G�̃V���b�g�̈ړ��֐�
//	--------------------------------------------------------------------
void ControllEnemyShot()
{
	//	�e���������v���C���[�Ƀq�b�g���Ă���Ȃ�ړ������͂����ɏI��
	if (EnemyShot.state != STATE::LIVE) return;

	//	�e�̈ړ�
	EnemyShot.y += ENEMY_SHOT_SPEED;

	//	�e�̓v���C���[�Ƀq�b�g���Ă���H
	if (IsHit(EnemyShot, Player) == true)
	{
		//	�e������
		EnemyShot.state = STATE::NONE;
		//	�v���C���[�����S��Ԃɂ���
		Player.state = STATE::HIT;
		return;
	}

	//	�e�͉�ʊO�ɏ������H
	if (EnemyShot.y > SCREEN_HEIGHT)
	{
		EnemyShot.state = STATE::NONE;
	}

	return;
}


//	--------------------------------------------------------------------
//	�G�̈ړ��E�V���b�g�̔��ˏ������s��
//	--------------------------------------------------------------------
void ControllEnemy()
{
	//	�[�����܂ŗ��Ă�����ړ������𔽓]
	switch (enemyMoveDirc)
	{
	case -1:
		if (Enemy.x <= 0)
		{
			enemyMoveDirc = 1;
		}
		break;
	case 1:
		if (Enemy.x >= SCREEN_WIDTH - ENEMY_WIDTH)
		{
			enemyMoveDirc = -1;
		}
		break;
	}

	//	�ړ�
	Enemy.x += ENEMY_MOVESPEED * enemyMoveDirc;

	//	�V���b�g���˃`�F�b�N
	enemyShotTime--;
	if (enemyShotTime == 0)
	{
		//	�e�����ݏo���Ă��Ȃ��̂Ȃ�e���o��
		if (EnemyShot.state == STATE::NONE)
		{
			//	�e�𐶐�
			CreateShot(ID::ENEMY, Enemy);
		}
		//	���ɒe�����Ԋu�����߂�
		CalcEnemyShotTiming();
	}
}
//	--------------------------------------------------------------------
//	�v���C���[�A�G�A�e�̈ړ��A�����蔻�菈�����Ă�
//	--------------------------------------------------------------------
void ControllGame()
{
	//	�v���C���[�̈ړ�����
	ControllPlayer();

	//	�v���C���[�̃V���b�g�̈ړ�
	ControllPlayerShot();

	//	�G�̈ړ�����
	ControllEnemy();

	//	�G�̒e�̈ړ�����
	ControllEnemyShot();

	return;
}
//	--------------------------------------------------------------------
//	�v���C���[�A�G�A�e�A�w�i�̕`�揈�����Ă�
//	--------------------------------------------------------------------
void DrawGame()
{
	// ��ʂ�������
	//ClearDrawScreen();

	// �`����ʂ𗠂ɂ���
	//SetDrawScreen(DX_SCREEN_BACK);

	//	�w�i�`��
	//DrawBG();

	//	�v���C���[�̕`�揈��
	DrawObject(Player);
	//	�v���C���[�̒e�`��
	DrawObject(PlayerShot);

	//	�G�̕`��
	DrawObject(Enemy);
	//	�G�̒e�`��
	DrawObject(EnemyShot);

	//	����ʂɕ`�������̂�\��ʂɔ��f����
	//ScreenFlip();

	return;
}
//	--------------------------------------------------------------------
//	�l�X�ȃQ�[�����������ĂԊ֐�
//	--------------------------------------------------------------------
void GameMain()
{
	//	�R���g���[��
	ControllGame();
	//	�`��
	DrawGame();

	return;
}
//	������
void init()
{
	DrawBG();

	Window::Resize(SCREEN_WIDTH, SCREEN_HEIGHT);
}
//	���C���֐�
void Main()
{
	//	������
	init();

	//	�Q�[��������
	InitGame();

	while (System::Update())
	{
		GameMain();
	}
}
