// Fill out your copyright notice in the Description page of Project Settings.


#include "StateManagerComponent.h"

// Sets default values for this component's properties
UStateManagerComponent::UStateManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStates();
	
}


// Called every frame
void UStateManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bCanTickState)
	{
		CurrentState->TickState();
	}
	if(bDebug)
	{
		if(CurrentState)
		{
			GEngine->AddOnScreenDebugMessage(-1,0.0f, FColor::Green, this->GetOwner()->GetName() + "'s current state: " + CurrentState->StateDisplayName.ToString());
			if(StateHistory.Num() >0)
			{
				GEngine->AddOnScreenDebugMessage(-1,0.0f, FColor::Purple, this->GetOwner()->GetName() + "'s past state " + StateHistory[StateHistory.Num() - 1]->GetName());
			}
		}
	}
}

void UStateManagerComponent::SwitchStateByKey(FString StateKey)
{
	//Bind the State
	UIState* NewState = StateMap.FindRef(StateKey);

	SwitchState(NewState);
}

void UStateManagerComponent::SwitchState(UIState* NewState)
{
	if(NewState->IsValidLowLevel())
	{
		//If there is no current state, it means we are at init
		if(!CurrentState)
		{
			CurrentState = NewState;
		}
		else
		{
			if(CurrentState->GetClass() == NewState->GetClass() && CurrentState->bCanRepeat == false)
			{
				if(bDebug)
				{
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, this->GetOwner()->GetName() + " state switch failed");
				}
			}
			else
			{
				bCanTickState = false;
				CurrentState->OnExitState();

				if(StateHistory.Num() < StateHistoryLength)
				{
					StateHistory.Push(CurrentState);
				}
				else
				{
					StateHistory.RemoveAt(0);
					StateHistory.Push(CurrentState);
				}
				
				CurrentState = NewState;
			}
		}

		if(CurrentState)
		{
			CurrentState->OnEnterState(GetOwner());
			bCanTickState = true;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, this->GetOwner()->GetName() + "'s state switch failed. " + "Invalid state!");
	}
}

void UStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
}

void UStateManagerComponent::InitializeStates()
{
	for(auto it = AvailableStates.CreateConstIterator(); it; ++it)
	{
		UIState* State = NewObject<UIState>(this, it->Value);
		StateMap.Add(it->Key, State);
	}
	
}

