// Fill out your copyright notice in the Description page of Project Settings.


#include "WHGameInstance.h"

UGameDataAsset* UWHGameInstance::GetGameDataAsset() const
{
	return GameData.LoadSynchronous();
}
