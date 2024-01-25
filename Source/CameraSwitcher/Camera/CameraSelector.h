#pragma once

#include "Camera/CameraDirector.h"

#include "GameFramework/Pawn.h"

#include "CameraSelector.generated.h"

UCLASS(Abstract)
class CAMERASWITCHER_API ACameraSelector : public APawn
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera Director")
	TSoftObjectPtr<ACameraDirector> CameraDirector;

private:
	class ACameraSwitcherHUD* PlayerHUD;

public:
	UFUNCTION(BlueprintCallable) AActor* GetCurrentCamera() const { return CameraDirector->GetCurrentCamera(); }

	UFUNCTION(BlueprintCallable) void OnCameraChangeLeft();
	UFUNCTION(BlueprintCallable) void OnCameraChangeRight();

protected:
	/**
	 * Setup pawn when game starts
	 */
	virtual void BeginPlay() override;
};
