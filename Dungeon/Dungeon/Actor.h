/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Object.h"

class CTask;
///	�A�N�^�[�N���X
class CActor :public Object
{
private:

	std::vector<std::shared_ptr<CActor>> actor;

protected:

	bool isDelete;							///	�������邩���ׂ�
	std::shared_ptr<CTask> task;		///	 �^�X�N

public:
	
	CActor() : isDelete(false){}
	CActor(std::shared_ptr<CTask> task, Transform transform, State state) :
		task(task), Object(transform, state), isDelete(false){}

	virtual ~CActor() = default;

	// ------------------------------
	//	�I�u�W�F�N�g������
	// ------------------------------
	void Append(std::shared_ptr<CActor> obj);

	// ------------------------------
	//	�I�u�W�F�N�g����ɂ���
	// ------------------------------
	void Clear(){ actor.clear(); }

	// ------------------------------
	//	�폜����
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

	// ------------------------------
	//	�I�u�W�F�N�g���擾����
	// ------------------------------
	std::shared_ptr<Object> GetComponent(const int id)const;

	// ------------------------------
	//	�������g���擾����
	// ------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor()const{ return actor; }

	// ------------------------------
	//	�I�u�W�F�N�g�̐����擾����
	// ------------------------------
	int GetSize()const{ return actor.size(); }

	// ---------------------------------------------------------------
	//	�_�C�i�~�b�N�L���X�g
	//	for(auto&)�͊�{���N���XCActor�̗v�f�ł����擾�ł��Ȃ����A
	//	������g�p����Ɣh���N���X�̗v�f�܂Ŏ擾�ł���
	// ---------------------------------------------------------------
	template<class CLASS, typename OBJ>
	inline std::shared_ptr<CLASS> DynamicCast(OBJ *obj)
	{
		return std::dynamic_pointer_cast<CLASS>(obj);
	}
};

