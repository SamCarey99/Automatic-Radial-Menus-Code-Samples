#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

//Include radial menu class/struct
#include "RadialSegmentData.h"
#include "BaseRadialMenu.h"

#include "ExampleCBindings.generated.h"


UCLASS()
class RADIALMENU_API UExampleCBindings : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UBaseRadialMenu *RadialMenu;

	UFUNCTION()
	void OnHover_Event(URadialMenuSegment* Segment, FRadialSegmentData SegmentData);

	void NativeConstruct() override;
};