#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class TASK6_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	// 메쉬 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	
	// 회전 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
