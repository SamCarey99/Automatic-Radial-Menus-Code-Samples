#include "ExampleCBindings.h"
#include "EngineGlobals.h"

void UExampleCBindings::NativeConstruct()
{
	TArray<URadialMenuSegment *> Segments = RadialMenu->GetAllSegments();
	for (URadialMenuSegment* i : Segments)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, "OnHover_Event");
		i->OnSegmentClick.AddUnique(Delegate);
	}
}

void UExampleCBindings::OnHover_Event(URadialMenuSegment * Segment, FRadialSegmentData SegmentData)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, SegmentData.SegmentText.ToString());
}