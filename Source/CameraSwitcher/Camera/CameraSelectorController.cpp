#include "Camera/CameraSelectorController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ACameraSelectorController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (DefaultInputContext.IsNull())
    {
        return;
    }

    // Setting up Input mapping
    auto LocalPlayer = GetLocalPlayer();
    auto Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(DefaultInputContext.LoadSynchronous(), 0);
}