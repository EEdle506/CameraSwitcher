#include "UI/CameraSwitcherHUD.h"
#include "UI/CameraSwitcherInfo.h"

#include "Camera/CameraSelectorController.h"

void ACameraSwitcherHUD::ShowMainMenu()
{
	// Make widget owned by our PlayerController
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	CameraInfoWidget = CreateWidget<UCameraSwitcherInfo>(PC, CameraInfoWidgetClass);

	CameraInfoWidget->AddToViewport();
}

void ACameraSwitcherHUD::HideMainMenu()
{
	if (CameraInfoWidget)
	{
		CameraInfoWidget->RemoveFromParent();
		CameraInfoWidget = nullptr;
	}
}

void ACameraSwitcherHUD::UpdateMainMenuData(float currentHealth, const FText& cameraName)
{
	CameraInfoWidget->SetHealthBar(currentHealth / 100);
	CameraInfoWidget->SetCameraNameTextBox(cameraName);
}
