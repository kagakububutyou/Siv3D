/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "Noncopyable.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//�y�^�X�N�̎g�p���@�z
//
//		�E�܂��^�X�N�̃C���X�^����錾����
//	
//		�E�C���X�^���X�̏�����
//
//	�ETask��Start(),Update,Draw(),Remove()�̏����ꏊ
//	�Q�[���Ǘ��N���X�̃R���X�g���N�^�̈�ԉ���Task->Start();������
//	�Q�[���Ǘ��N���X��Update�֐��̒���
//	Task->Update();
//	Task->Draw();
//	Task->Remove();
//	���̏��ŏ����Ă�������
//	����œo�^�����I�u�W�F�N�g�͂��ׂď��������悤�ɂȂ�
//
//	�E�^�X�N�ɓo�^����܂ł̎菇

//	�@�X�}�[�g�|�C���^�ŃC���X�^���X��錾�A������
//	Player = std::make_shared(new CActor());
//
//	�A�A�N�^�[�ɃI�u�W�F�N�g�̏�����ꍞ��
//	Player->Append(new CPlayer());
//
// �B�I�u�W�F�N�g���^�X�N�ɓ����
//	Task->Append("�o�^��",�o�^����I�u�W�F�N�g(�C���X�^���X));
// ��)Task->Append("Player",Player);
//	
//	�E���ӓ_
//	�o�^���ĂȂ����O�͕K���G���[���o��I
//		�K���o�^�����Ȃ߂͊o���Ă����I
//	�o�^�������ȏ�̂��̎擾���Ȃ��悤�ɂ���
//	
//	�o�^�����I�u�W�F�N�g�𑼂̏��Ŏ擾�������ꍇ
//	Task->GetComponent<�擾�������N���X��>(�o�^�������O�A�o�^�����ԍ�);
//	��)Task->GetComponent<CPlayer>("Player",0)
//	
//	�E�o�^�����v�f�����ׂĎ擾����ꍇ
//	Task->GetComponents<�擾�������N���X��>(�o�^�������O�A�o�^�����ԍ�);
//	��)Task->GetComponents<CEnemy>("Enemy");
//	
//	�E�o�^�����v�f�̐����擾����
//	TAsk->GetSize(�o�^�������O);
//	��) Task->GetSize("Enemy");
//	
//	�Efor(auto&)�Ń^�X�N�̗[�\���g�����@
//	��{�I�Ɋ��N���X��Object�̃N���X�ɓ����Ă�v�f�����擾�ł��Ȃ�
//	��)
//	for(auto &obj : Task->GetActor(�o�^��))
//	{
//		obj->���\�b�h(�֐�) or �ϐ�;
//	}
//	
//		�h���N���X�̗v�f���擾�������ꍇ
//	DynamicCast<�擾�������N���X��>(�v�f)
//	��)
//	for(auto &obj : Task->GetActor(�o�^��))
//	{
//		DynamicCast<�N���X��>
//	}
//
//	�E�^�X�N�ɓo�^�����I�u�W�F�N�g�̓������̊J���͂��Ȃ�����
//	�E�o�^�����I�u�W�F�N�g��r���ō폜�������ꍇ�́AisDelete��true�ɂ���Ύ��̃t���[���ō폜�����
//	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CActor;

class CTask
{
private:
	std::unordered_map < std::string, std::shared_ptr<CActor>> object;

public:

	// ------------------------------
	//	Actor������
	// ------------------------------
	void Append(std::string name, std::shared_ptr<CActor> actor);

	// ------------------------------
	//	Actor����ɂ���
	// ------------------------------
	void Clear();

	// ------------------------------
	//	�^�X�N����폜����
	// ------------------------------
	void Remove();

	// ------------------------------
	//	�A�b�v�f�[�g�̑O�ɌĂ΂�鏈��
	// ------------------------------
	void Start();

	// ------------------------------
	//	�A�b�v�f�[�g
	// ------------------------------
	void Update();

	// ------------------------------
	//	�`��
	// ------------------------------
	void Draw();

	// ------------------------------------------------------
	//	�I�u�W�F�N�g���擾����(ID�܂Ŏ擾����)
	// ------------------------------------------------------
	template<typename OBJ>
	std::shared_ptr<OBJ> GetComponet(const std::string &name, const int Id)
	{
		auto it = object.begin();
		it = object.find(name);
		assert(it != object.end());

		return std::dynamic_pointer_cast<OBJ>(it->second->Getcomponent(Id));
	}

	// ------------------------------------------------------
	//	�I�u�W�F�N�g���擾����(Actor�̒��ɂ���N���X�̑S�̂��擾)
	// ------------------------------------------------------
	std::shared_ptr<CActor> GetComponents(const std::string &name);

	// ------------------------------------------------------
	//	�A�N�^�[���̂��擾����
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor(const std::stringbuf &name);

	// ------------------------------------------------------
	//	�I�u�W�F�N�g�̐����擾����
	// ------------------------------------------------------
	void GetSize(const std::string &name);

};
