#pragma once

#include "CameraSwitcher.h"
#include "CameraDirector.generated.h"

UCLASS()
class CAMERASWITCHER_API ACameraDirector : public AActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool BlendMode = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SmoothBlendTime = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor* DefaultCamera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<AActor*> Cameras;

private:
	AActor* CurrentCamera = nullptr;
	APlayerController* PlayerController = nullptr;

public:
	// Sets default values for this actor's properties
	ACameraDirector();

	AActor* GetCurrentCamera() const { return CurrentCamera; }

	AActor* ChangeToNextCamera();
	AActor* ChangeToPreviousCamera();

	void ChangeToCamera(int32 Index);
	void ChangeToCamera(AActor* Camera);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetCurrentCamera(AActor* Camera);

	AActor* GetNextCamera();
	AActor* GetPreviousCamera();
};
