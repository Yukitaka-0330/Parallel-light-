#include "Camera.h"

namespace Camera
{
	//�ϐ�
	XMVECTOR position_;	//�J�����̈ʒu�i���_�j
	XMVECTOR target_;	//����ʒu�i�œ_�j
	XMMATRIX viewMatrix_;	//�r���[�s��
	XMMATRIX projMatrix_;	//�v���W�F�N�V�����s��
}


//������
void Camera::Initialize()
{
	position_ = XMVectorSet(0, 3, -10, 0);	//�J�����̈ʒu
	target_ = XMVectorSet(0, 0, 0, 0);	//�J�����̏œ_

	//position_ = XMVectorSet(5, 3, -10, 0);	//�J�����̈ʒu
	//target_ = XMVectorSet(0, 0, 0, 0);	//�J�����̏œ_

	//�v���W�F�N�V�����s��
	projMatrix_ = XMMatrixPerspectiveFovLH(XM_PIDIV4, (FLOAT)800 / (FLOAT)600, 0.1f, 100.0f);
}

//�X�V
void Camera::Update()
{
	//�r���[�s��̍쐬
	viewMatrix_ = XMMatrixLookAtLH(position_, target_, XMVectorSet(0, 1, 0, 0));
}

//�ʒu��ݒ�
void Camera::SetPosition(XMVECTOR position)
{
	position_ = position;
}

void Camera::SetPosition(XMFLOAT3 position)
{
	SetPosition(XMLoadFloat3(&position)); //�I�[�o�[���[�h����Ƃ��͂��̂����ŏ������ق�������
	//�����d�l�ύX���������Ƃ��Ɋ֐��������Ȃ���ׂȂ�Ȃ��̂ŁA��\�i�����߂Ă����Ă��̑�\��u���悤�ɂ��Ă���
}

//�œ_��ݒ�
void Camera::SetTarget(XMVECTOR target)
{
	
	target_ = target;
}

void Camera::SetTarget(XMFLOAT3 target)
{
	SetTarget(XMLoadFloat3(&target));
}

XMVECTOR Camera::GetEyePosition()
{
	return position_;
}

//�r���[�s����擾
XMMATRIX Camera::GetViewMatrix()
{
	return viewMatrix_;
}

//�v���W�F�N�V�����s����擾
XMMATRIX Camera::GetProjectionMatrix()
{
	return projMatrix_;
}

