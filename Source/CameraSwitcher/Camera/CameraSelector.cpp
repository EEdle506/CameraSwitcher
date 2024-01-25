#include "Camera/CameraSelector.h"
#include "Camera/CameraSelectorController.h"

#include "UI/CameraSwitcherHUD.h"

#include "Kismet/GameplayStatics.h"

void ACameraSelector::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PC = GetController<APlayerController>();

    if (!PC)
    {
        return;
    }

    // Setting up HUD

    PlayerHUD = PC->GetHUD<ACameraSwitcherHUD>();

    if (PlayerHUD)
    {
        PlayerHUD->ShowMainMenu();
    }
}

void ACameraSelector::OnCameraChangeLeft()
{
    auto Camera = CameraDirector->ChangeToPreviousCamera();
    auto CameraName = FText::FromString(Camera->GetActorLabel());

    PlayerHUD->UpdateMainMenuData(60, CameraName);
}

void ACameraSelector::OnCameraChangeRight()
{
    auto Camera = CameraDirector->ChangeToNextCamera();
    auto CameraName = FText::FromString(Camera->GetActorLabel());

    PlayerHUD->UpdateMainMenuData(60, CameraName);
}
