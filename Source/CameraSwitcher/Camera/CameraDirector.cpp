#include "Camera/CameraDirector.h"

#include "Kismet/GameplayStatics.h"

ACameraDirector::ACameraDirector() 
{

}

void ACameraDirector::BeginPlay()
{
    Super::BeginPlay();

    PlayerController = UGameplayStatics::GetPlayerController(this, EAutoReceiveInput::Disabled);

    if (DefaultCamera)
    {
        if (PlayerController)
        {
            PlayerController->SetViewTarget(DefaultCamera);
        }
    }

    if (Cameras.IsEmpty())
    {
        UE_LOGFMT(LogTemp, Warning, "No cameras were specified to array", Cameras.Num());
    }
    else 
    {
        UE_LOGFMT(LogTemp, Warning, "Cameras were inputed to script {0}", Cameras.Num());
    }
}

void ACameraDirector::SetCurrentCamera(AActor* Camera)
{
    if (!Camera)
    {
        return;
    }

    CurrentCamera = Camera;
    
    if (!BlendMode)
    {
        PlayerController->SetViewTarget(CurrentCamera);
    }
    else
    {
        PlayerController->SetViewTargetWithBlend(CurrentCamera, SmoothBlendTime);
    }
}

AActor* ACameraDirector::ChangeToNextCamera()
{
    AActor* NextCamera = GetNextCamera();

    SetCurrentCamera(NextCamera);

    return NextCamera;
}
AActor* ACameraDirector::ChangeToPreviousCamera()
{
    AActor* PreviousCamera = GetPreviousCamera();

    SetCurrentCamera(PreviousCamera);

    return PreviousCamera;
}

void ACameraDirector::ChangeToCamera(int32 Index)
{
    SetCurrentCamera(Cameras[Index]);
}
void ACameraDirector::ChangeToCamera(AActor* Camera)
{
    SetCurrentCamera(Camera);
}

AActor* ACameraDirector::GetNextCamera()
{
    AActor* FirstCamera = *Cameras.begin();

    if (!CurrentCamera)
    {
        return FirstCamera;
    }

    if (int32 CurrentIndex; Cameras.Find(CurrentCamera, CurrentIndex))
    {
        int32 NextIndex = ++CurrentIndex;

        if (Cameras.IsValidIndex(NextIndex))
        {
            return Cameras[NextIndex];
        }
    }

    return FirstCamera;
}
AActor* ACameraDirector::GetPreviousCamera()
{
    AActor* FirstCamera = *Cameras.begin();

    if (!CurrentCamera)
    {
        return FirstCamera;
    }

    if (int32 CurrentIndex; Cameras.Find(CurrentCamera, CurrentIndex))
    {
        int32 PreviousIndex = --CurrentIndex;

        if (Cameras.IsValidIndex(PreviousIndex))
        {
            return Cameras[PreviousIndex];
        }

        if (PreviousIndex <= INDEX_NONE)
        {
            return Cameras.Last();
        }
    }

    return FirstCamera;
}

