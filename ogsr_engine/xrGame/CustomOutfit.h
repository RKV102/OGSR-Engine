#pragma once

#include "inventory_item_object.h"

struct SBoneProtections;

class CCustomOutfit: public CInventoryItemObject {
	friend class COutfitScript;
private:
    typedef	CInventoryItemObject inherited;
public:
									CCustomOutfit		(void);
	virtual							~CCustomOutfit		(void);

	virtual void					Load				(LPCSTR section);
	
	//����������� ������ ����, ��� ������, ����� ������ ����� �� ���������
	virtual void					Hit					(float P, ALife::EHitType hit_type);

	//������������ �� ������� ����������� ���
	//��� ��������������� ���� �����������
	//���� �� ��������� ����� ������
	float							GetHitTypeProtection(ALife::EHitType hit_type, s16 element);
	float							GetDefHitTypeProtection(ALife::EHitType hit_type);

	float							HitThruArmour		(float hit_power, s16 element, float AP);
	//����������� �� ������� ����������� ������ ����
	//���� �� ��������� ����� ������
	float							GetPowerLoss		();


	virtual void					OnMoveToSlot		();
	virtual void					OnMoveToRuck		();

protected:
	HitImmunity::HitTypeSVec		m_HitTypeProtection;
	float							m_fPowerLoss;

	shared_str						m_ActorVisual;
	shared_str						m_full_icon_name;
	SBoneProtections*				m_boneProtection;	
protected:
	u32								m_ef_equipment_type;

public:
	float							m_additional_weight;
	float							m_additional_weight2;
	shared_str						m_NightVisionSect;
	virtual u32						ef_equipment_type		() const;
	virtual	BOOL					BonePassBullet			(int boneID);
	const shared_str&				GetFullIconName			() const	{return m_full_icon_name;};

	virtual void			net_Export			(NET_Packet& P);
	virtual void			net_Import			(NET_Packet& P);

#ifdef OUTFIT_AF
	float m_fBleedingRestoreSpeed;
	float m_fHealthRestoreSpeed;
	float m_fPowerRestoreSpeed;
	float m_fSatietyRestoreSpeed;
#ifndef OBJECTS_RADIOACTIVE
#ifdef AF_PSY_HEALTH
	float m_fPsyHealthRestoreSpeed;
	virtual float PsyHealthRestoreSpeed() const { return m_fPsyHealthRestoreSpeed; }
#endif
	float m_fRadiationRestoreSpeed;
	virtual float RadiationRestoreSpeed() const { return m_fRadiationRestoreSpeed; }
#endif
#endif
};
