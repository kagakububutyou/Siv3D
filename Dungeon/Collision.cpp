// ------------------------------------------------
//			�����蔻��
//					code by shinnnosuke hiratsuka
// ------------------------------------------------
#include "Collision.h"

namespace Collision
{
	// �{�b�N�X�̂����蔻�� 2D
	bool RectToRect(const Point &pos, const Point &size, const Point &col_pos, const Point &col_size)
	{

		const int x0 = pos.x;
		const int y0 = pos.y;
		const int x1 = pos.x + size.x - 1;
		const int y1 = pos.y + size.y - 1;

		const int x2 = col_pos.x;
		const int y2 = col_pos.y;
		const int x3 = col_pos.x + col_size.x - 1;
		const int y3 = col_pos.y + col_size.y - 1;

		//	��̋�`����������̌`�ŏd�Ȃ��Ă��邩�H
		if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
		{
			//	�d�Ȃ��Ă���
			return true;
		}

		//	�d�Ȃ��ĂȂ�����
		return false;
	}
}