#pragma once
#include "stdafx.h"
#include "IComponent.h"
#include "CLog.h"

namespace dxfw
{
	class CTransform : public IComponent
	{
	public:
		CTransform();
		CTransform(const DirectX::XMMATRIX& worldMatrix);
		virtual ~CTransform();

		DirectX::XMFLOAT4X4* GetWorldMatrix() { return &m_worldMatrix; }
		void SetWorldMatrix(const DirectX::XMMATRIX& worldMatrix) { DirectX::XMStoreFloat4x4(&m_worldMatrix, worldMatrix); }

		DirectX::XMVECTOR GetPosition();
		DirectX::XMVECTOR GetRotationQuat();
		DirectX::XMVECTOR GetScale();

		void Translate(DirectX::XMVECTOR translation, bool relativeToLocal);
		
		void RotateAroundXLocal(float angle);
		void RotateAroundYLocal(float angle);
		void RotateAroundZLocal(float angle);
		
		void RotateAroundAxis(const DirectX::XMFLOAT3& axis, float angle, bool relativeToLocal);

	private:
		DirectX::XMFLOAT4X4 m_worldMatrix;
	};
}