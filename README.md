# Automatic-Radial-Menus-Code-Samples
This repository includes examples of how to interact with the UE4 Automatic Radial Menus plugin using C++.

<strong>Purchase: </strong>ADD</br>
<strong>Itch: </strong>ADD</br>
<strong>Website: </strong>ADD</br>
<strong>Support Email: </strong>ADD</br>



<h3>Build File</h3>
To access the plugins classes the following dependencies must be added into <strong>ProjectName.build.cs</strong>

```cpp
PrivateDependencyModuleNames.AddRange(new string[] { "AutomaticRadialMenus" });
PrivateIncludePathModuleNames.AddRange(new string[] { "AutomaticRadialMenus" });
PublicDependencyModuleNames.AddRange(new string[] {"SlateCore" });
```
<h3>Include Statements</h3>
The following must be included in the header of the class performing the menu actions.

```cpp
#include "RadialSegmentData.h"
#include "BaseRadialMenu.h
```

<h3>Radial Menu Reffernce</h3>

References to a radial menu can be made in the following in a UUserWidget Class
```cpp
UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UBaseRadialMenu *RadialMenu;
```
<h3>Event Bindings</h3>
There are three types of events which can be bound. 

```cpp
OnHover(URadialMenuSegment * Segment, FRadialSegmentData SegmentData)
OnUnHover(URadialMenuSegment * Segment, FRadialSegmentData SegmentData)
OnSegmentClick(URadialMenuSegment * Segment, FRadialSegmentData SegmentData)
```

Example binding a click event

```cpp
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
 ```

