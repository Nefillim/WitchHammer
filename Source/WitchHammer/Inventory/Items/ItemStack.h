
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
	UPROPERTY()
	int Count = 0;
};
