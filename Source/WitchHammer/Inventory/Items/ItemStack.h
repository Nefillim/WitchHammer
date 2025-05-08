
#pragma once
#include "Item.h"
#include "ItemStack.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UItemStack : public UItem
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static UItemStack* Create(int32 Count);


	UPROPERTY()
	int Count = 0;

};
