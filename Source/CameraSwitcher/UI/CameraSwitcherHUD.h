#pragma once

#include "CameraSwitcher.h"

#include <GameFramework/HUD.h>

#include "CameraSwitcherHUD.generated.h"

UCLASS(Abstract)
class CAMERASWITCHER_API ACameraSwitcherHUD : public AHUD
{
    GENERATED_BODY()

public:
	/**
	 * @brief 
	 */
	UFUNCTION(BlueprintCallable) void ShowMainMenu();
	/**
	 * @brief 
	 */
	UFUNCTION(BlueprintCallable) void HideMainMenu();

	void UpdateMainMenuData(float currentHealth, const FText& cameraName);

protected: 
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UCameraSwitcherInfo> CameraInfoWidgetClass;

	UPROPERTY()
	class UCameraSwitcherInfo* CameraInfoWidget;
};