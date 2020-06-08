# Automatic Radial Menus - Code Samples
This repository includes examples of how to interact with the UE4 Automatic Radial Menus plugin using C++. For information about implementing this plugin using blueprints see the full documentation below.<br>
<strong>Full Documentation: </strong>https://docs.google.com/document/d/1FX6kFsc1HwUKw_bF7iKGUtSWE0iaF5YazHdNnkcgnfQ/edit?usp=sharing</br>

<strong>Purchase: </strong>Coming Soon</br>
<strong>Itch: </strong>https://samcarey.itch.io/dynamic-radial-menu-system-ue4-asset</br>
<strong>Website: </strong> http://www.samcarey.tech/#/ProjectPage?ProjectID=6</br>
<strong>Support Email: </strong>contact@samcarey.tech</br>




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
#include "BaseRadialMenu.h"
#include "RadialMenuSegment.h"
```

<h3>Radial Menu Reference</h3>

References to a radial menu can be made in a UUserWidget Class. The BindWidget modifier allows the reference to be automatically set if the name matches in the user widget blueprint.
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

