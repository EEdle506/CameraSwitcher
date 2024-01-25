#pragma once

#include "CameraSwitcher.h"

#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"

#include "CameraSelectorController.generated.h"

UCLASS()
class CAMERASWITCHER_API ACameraSelectorController : public APlayerController
{
	GENERATED_BODY()

public:
	/**
	 * Default input context
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	TSoftObjectPtr<UInputMappingContext> DefaultInputContext;

protected:
	virtual void SetupInputComponent() override;

};
