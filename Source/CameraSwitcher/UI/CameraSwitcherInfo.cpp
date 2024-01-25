#include "UI/CameraSwitcherInfo.h"

#include <Components/TextBlock.h>
#include <Components/ProgressBar.h>

void UCameraSwitcherInfo::NativeConstruct()
{
    Super::NativeConstruct();
}

void UCameraSwitcherInfo::SetCameraNameTextBox(const FText& cameraName)
{
	if (CameraNameTextBox)
	{
		CameraNameTextBox->SetText(cameraName);
	}
}

void UCameraSwitcherInfo::SetHealthBar(float currentHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(currentHealth);
	}
}