#pragma once

#include "CameraSwitcher.h"

#include <Blueprint/UserWidget.h>

#include "CameraSwitcherInfo.generated.h"

UCLASS(Abstract)
class CAMERASWITCHER_API UCameraSwitcherInfo : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, meta=(BindWidget))
    class UTextBlock* CameraNameTextBox;

    UPROPERTY(EditAnywhere, meta=(BindWidget))
    class UProgressBar* HealthBar;

public:
    void SetCameraNameTextBox(const FText& cameraName);
    void SetHealthBar(float currentHealth);

protected: 
	virtual void NativeConstruct() override;
};